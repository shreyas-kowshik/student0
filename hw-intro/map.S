	.file	"map.c"
	.comm	foo,4,4
	.globl	stuff
	.data
	.align 4
	.type	stuff, @object
	.size	stuff, 4
stuff:
	.long	7
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, -20(%rbp)
	movl	$100, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movl	$100, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movl	$3, %edi
	call	recur
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
