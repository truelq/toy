	.text
	.file	"tt.c"
	.globl	fibo                    # -- Begin function fibo
	.p2align	4, 0x90
	.type	fibo,@function
fibo:                                   # @fibo
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movl	%edi, -12(%rbp)
	cmpl	$1, -12(%rbp)
	je	.LBB0_2
# %bb.1:
	cmpl	$2, -12(%rbp)
	jne	.LBB0_3
.LBB0_2:
	movl	$1, -16(%rbp)
	jmp	.LBB0_4
.LBB0_3:
	movl	-12(%rbp), %edi
	subl	$1, %edi
	callq	fibo
	movl	%eax, %ebx
	movl	-12(%rbp), %edi
	subl	$2, %edi
	callq	fibo
	addl	%eax, %ebx
	movl	%ebx, -16(%rbp)
.LBB0_4:
	movl	-16(%rbp), %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end0:
	.size	fibo, .Lfunc_end0-fibo
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -20(%rbp)
	callq	getchar
	movl	%eax, -12(%rbp)
	movl	$1, -4(%rbp)
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jg	.LBB1_3
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-4(%rbp), %edi
	callq	fibo
	movl	%eax, -8(%rbp)
	movl	$49, %edi
	callq	putchar
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB1_1
.LBB1_3:
	movl	$1, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	a,@object               # @a
	.comm	a,4,4
	.type	b,@object               # @b
	.comm	b,4,4
	.type	c,@object               # @c
	.comm	c,4,4

	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
