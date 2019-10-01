package org.javacs.kt.signaturehelp

import org.eclipse.lsp4j.ParameterInformation
import org.eclipse.lsp4j.SignatureHelp
import org.eclipse.lsp4j.SignatureInformation
import org.javacs.kt.CompiledFile
import org.javacs.kt.completion.DECL_RENDERER
import org.javacs.kt.completion.identifierOverloads
import org.javacs.kt.completion.memberOverloads
import org.javacs.kt.docs.findDoc
import org.javacs.kt.util.findParent
import org.javacs.kt.util.nullResult
import org.jetbrains.kotlin.descriptors.CallableDescriptor
import org.jetbrains.kotlin.descriptors.DeclarationDescriptorWithSource
import org.jetbrains.kotlin.descriptors.ValueParameterDescriptor
import org.jetbrains.kotlin.psi.KtCallExpression
import org.jetbrains.kotlin.psi.KtDotQualifiedExpression
import org.jetbrains.kotlin.psi.KtNameReferenceExpression
import org.jetbrains.kotlin.psi.psiUtil.startOffset

fun fetchSignatureHelpAt(file: CompiledFile, cursor: Int): SignatureHelp? {
    val call = file.parseAtPoint(cursor)?.findParent<KtCallExpression>() ?: return nullResult("No call around ${file.describePosition(cursor)}")
    val candidates = candidates(call, file)
    val activeDeclaration = activeDeclaration(call, candidates)
    val activeParameter = activeParameter(call, cursor)
    val signatures = candidates.map(::toSignature)

    return SignatureHelp(signatures, activeDeclaration, activeParameter)
}

private fun toSignature(desc: CallableDescriptor): SignatureInformation {
    val label = DECL_RENDERER.render(desc)
    val params = desc.valueParameters.map(::toParameter)
    val docstring = docstring(desc)

    return SignatureInformation(label, docstring, params)
}

private fun toParameter(param: ValueParameterDescriptor): ParameterInformation {
    val label = DECL_RENDERER.renderValueParameters(listOf(param), false)
    val removeParens = label.substring(1, label.length - 1)
    val docstring = docstring(param)

    return ParameterInformation(removeParens, docstring)
}

private fun docstring(declaration: DeclarationDescriptorWithSource): String {
    val doc = findDoc(declaration) ?: return ""

    return doc.getContent().trim()
}

private fun candidates(call: KtCallExpression, file: CompiledFile): List<CallableDescriptor> {
    val target = call.calleeExpression!!
    val identifier = target.text // TODO when call is foo.bar(), is this bar or foo.bar ?
    val dotParent = target.findParent<KtDotQualifiedExpression>()
    if (dotParent != null) {
        val type = file.typeAtPoint(dotParent.receiverExpression.startOffset) ?: return emptyList()

        return memberOverloads(type, identifier).toList()
    }
    val idParent = target.findParent<KtNameReferenceExpression>()
    if (idParent != null) {
        val scope = file.scopeAtPoint(idParent.startOffset) ?: return emptyList()

        return identifierOverloads(scope, identifier).toList()
    }
    return emptyList()
}

private fun activeDeclaration(call: KtCallExpression, candidates: List<CallableDescriptor>): Int {
    return candidates.indexOfFirst { isCompatibleWith(call, it) }
}

private fun isCompatibleWith(call: KtCallExpression, candidate: CallableDescriptor): Boolean {
    val argumentList = call.valueArgumentList ?: return true
    val nArguments = argumentList.text.count { it == ',' } + 1
    if (nArguments > candidate.valueParameters.size)
        return false

    for (arg in call.valueArguments) {
        if (arg.isNamed()) {
            if (candidate.valueParameters.none { arg.name == it.name.identifier })
                return false
        }
        // TODO consider types as well
    }

    return true
}

private fun activeParameter(call: KtCallExpression, cursor: Int): Int {
    val args = call.valueArgumentList ?: return -1
    val text = args.text
    val beforeCursor = text.subSequence(0, cursor - args.textRange.startOffset)

    return beforeCursor.count { it == ','}
}