	.file	"sec0_6_6.c"
	.globl	global
	.bss
	.align 4
	.type	global, @object
	.size	global, 4
global:
	.zero	4
	.text
	.globl	callee
	.type	callee, @function
callee:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	popq	%rbp
	ret
	.size	callee, .-callee
	.globl	caller
	.type	caller, @function
caller:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$4, %esi
	movl	$3, %edi
	call	callee
	movl	%eax, global(%rip)
	nop
	popq	%rbp
	ret
	.size	caller, .-caller
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	call	caller
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
