	.file	"Funprime.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
.LC1:
	.ascii "Prime Number\0"
.LC2:
	.ascii "Not Prime Number\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	scanf
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	isPrime
	cmpl	$1, %eax
	jne	.L2
	leaq	.LC1(%rip), %rcx
	call	printf
	jmp	.L3
.L2:
	leaq	.LC2(%rip), %rcx
	call	printf
.L3:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	isPrime
	.def	isPrime;	.scl	2;	.type	32;	.endef
	.seh_proc	isPrime
isPrime:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$1, 16(%rbp)
	jg	.L6
	movl	$0, %eax
	jmp	.L7
.L6:
	movl	$2, -4(%rbp)
	jmp	.L8
.L10:
	movl	16(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L9
	movl	$0, %eax
	jmp	.L7
.L9:
	addl	$1, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	cmpl	16(%rbp), %eax
	jl	.L10
	movl	$1, %eax
.L7:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 9.1.0"
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
