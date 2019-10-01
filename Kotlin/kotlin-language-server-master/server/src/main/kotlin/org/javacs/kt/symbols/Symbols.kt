package org.javacs.kt.symbols

import org.jetbrains.kotlin.com.intellij.psi.PsiElement
import org.eclipse.lsp4j.Location
import org.eclipse.lsp4j.SymbolInformation
import org.eclipse.lsp4j.SymbolKind
import org.eclipse.lsp4j.DocumentSymbol
import org.eclipse.lsp4j.jsonrpc.messages.Either
import org.javacs.kt.SourcePath
import org.javacs.kt.completion.containsCharactersInOrder
import org.javacs.kt.position.range
import org.javacs.kt.util.preOrderTraversal
import org.javacs.kt.util.toPath
import org.jetbrains.kotlin.psi.*
import org.jetbrains.kotlin.psi.psiUtil.parents

fun documentSymbols(file: KtFile): List<Either<SymbolInformation, DocumentSymbol>> =
        doDocumentSymbols(file).mapNotNull(::symbolInformation).toList().map { Either.forLeft<SymbolInformation, DocumentSymbol>(it) }

private fun doDocumentSymbols(file: KtFile): Sequence<KtNamedDeclaration> =
        file.preOrderTraversal().mapNotNull { pickImportantElements(it, true) }

private const val MAX_SYMBOLS = 50

fun workspaceSymbols(query: String, sp: SourcePath): List<SymbolInformation> =
        doWorkspaceSymbols(sp)
                .filter { containsCharactersInOrder(it.name!!, query, false) }
                .mapNotNull(::symbolInformation)
                .take(MAX_SYMBOLS)
                .toList()

private fun doWorkspaceSymbols(sp: SourcePath): Sequence<KtNamedDeclaration> =
        sp.all().asSequence().flatMap(::fileSymbols)

private fun fileSymbols(file: KtFile): Sequence<KtNamedDeclaration> =
        file.preOrderTraversal().mapNotNull { pickImportantElements(it, false) }

private fun pickImportantElements(node: PsiElement, includeLocals: Boolean): KtNamedDeclaration? =
        when (node) {
            is KtClassOrObject -> if (node.name == null) null else node
            is KtTypeAlias -> node
            is KtConstructor<*> -> node
            is KtNamedFunction -> if (!node.isLocal || includeLocals) node else null
            is KtProperty -> if (!node.isLocal || includeLocals) node else null
            is KtVariableDeclaration -> if (includeLocals) node else null
            else -> null
        }

private fun symbolInformation(d: KtNamedDeclaration): SymbolInformation? {
    val name = d.name ?: return null

    return SymbolInformation(name, symbolKind(d), symbolLocation(d), symbolContainer(d))
}

private fun symbolKind(d: KtNamedDeclaration): SymbolKind =
        when (d) {
            is KtClassOrObject -> SymbolKind.Class
            is KtTypeAlias -> SymbolKind.Interface
            is KtConstructor<*> -> SymbolKind.Constructor
            is KtNamedFunction -> SymbolKind.Function
            is KtProperty -> SymbolKind.Property
            is KtVariableDeclaration -> SymbolKind.Variable
            else -> throw IllegalArgumentException("Unexpected symbol $d")
        }

private fun symbolLocation(d: KtNamedDeclaration): Location {
    val file = d.containingFile
    val uri = file.toPath().toUri().toString()
    val range = range(file.text, d.textRange)

    return Location(uri, range)
}

private fun symbolContainer(d: KtNamedDeclaration): String? =
        d.parents
                .filterIsInstance<KtNamedDeclaration>()
                .firstOrNull()
                ?.fqName.toString()
