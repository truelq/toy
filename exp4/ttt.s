	.text
	.file	"ttt.ll"
	.globl	read                    # -- Begin function read
	.p2align	4, 0x90
	.type	read,@function
read:                                   # @read
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$0, 4(%rsp)
	jmp	.LBB0_1
	.p2align	4, 0x90
.LBB0_2:                                # %hard3begin
                                        #   in Loop: Header=BB0_1 Depth=1
	movl	4(%rsp), %eax
	leal	(%rax,%rax,4), %eax
	movl	(%rsp), %ecx
	leal	-48(%rcx,%rax,2), %eax
	movl	%eax, 4(%rsp)
.LBB0_1:                                # %hard3before
                                        # =>This Inner Loop Header: Depth=1
	callq	getchar
	movl	%eax, (%rsp)
	cmpl	$10, (%rsp)
	jne	.LBB0_2
# %bb.3:                                # %hard3end
	movl	4(%rsp), %eax
	popq	%rcx
	retq
.Lfunc_end0:
	.size	read, .Lfunc_end0-read
	.cfi_endproc
                                        # -- End function
	.globl	write                   # -- Begin function write
	.p2align	4, 0x90
	.type	write,@function
write:                                  # @write
	.cfi_startproc
# %bb.0:
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, 16(%rsp)
	movl	$1, 12(%rsp)
	jmp	.LBB1_1
	.p2align	4, 0x90
.LBB1_2:                                # %hard4begin
                                        #   in Loop: Header=BB1_1 Depth=1
	movl	12(%rsp), %eax
	addl	%eax, %eax
	leal	(%rax,%rax,4), %eax
	movl	%eax, 12(%rsp)
.LBB1_1:                                # %hard4before
                                        # =>This Inner Loop Header: Depth=1
	movl	12(%rsp), %eax
	cmpl	16(%rsp), %eax
	jle	.LBB1_2
# %bb.3:                                # %hard4end
	movl	12(%rsp), %eax
	movl	$3435973837, %ecx       # imm = 0xCCCCCCCD
	imulq	%rax, %rcx
	shrq	$35, %rcx
	movl	%ecx, 12(%rsp)
	cmpl	$10, 16(%rsp)
	jl	.LBB1_6
	.p2align	4, 0x90
.LBB1_5:                                # %hard11begin
                                        # =>This Inner Loop Header: Depth=1
	movl	16(%rsp), %ecx
	movl	12(%rsp), %esi
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%esi
	movl	%eax, %edx
	imull	%esi, %edx
	subl	%edx, %ecx
	movl	%ecx, 16(%rsp)
	movl	$3435973837, %ecx       # imm = 0xCCCCCCCD
	imulq	%rsi, %rcx
	shrq	$35, %rcx
	movl	%ecx, 12(%rsp)
	addl	$48, %eax
	movl	%eax, 20(%rsp)
	movl	%eax, %edi
	callq	putchar
	cmpl	$10, 16(%rsp)
	jge	.LBB1_5
.LBB1_6:                                # %hard11end
	movl	16(%rsp), %edi
	addl	$48, %edi
	callq	putchar
	movl	$10, %edi
	callq	putchar
	movl	16(%rsp), %eax
	addq	$24, %rsp
	retq
.Lfunc_end1:
	.size	write, .Lfunc_end1-write
	.cfi_endproc
                                        # -- End function
	.globl	test                    # -- Begin function test
	.p2align	4, 0x90
	.type	test,@function
test:                                   # @test
	.cfi_startproc
# %bb.0:
	movl	%edi, -4(%rsp)
	movl	$1, -8(%rsp)
	movl	$1, -12(%rsp)
	jmp	.LBB2_1
	.p2align	4, 0x90
.LBB2_2:                                # %hard4begin
                                        #   in Loop: Header=BB2_1 Depth=1
	movl	-8(%rsp), %eax
	movl	-12(%rsp), %ecx
	imull	%eax, %ecx
	movl	%ecx, -12(%rsp)
	incl	%eax
	movl	%eax, -8(%rsp)
.LBB2_1:                                # %hard4before
                                        # =>This Inner Loop Header: Depth=1
	movl	-8(%rsp), %eax
	cmpl	-4(%rsp), %eax
	jle	.LBB2_2
# %bb.3:                                # %hard4end
	movl	-12(%rsp), %eax
	retq
.Lfunc_end2:
	.size	test, .Lfunc_end2-test
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$1, 12(%rsp)
	callq	read
	movl	%eax, 16(%rsp)
	movl	%eax, %edi
	callq	write
	jmp	.LBB3_1
	.p2align	4, 0x90
.LBB3_2:                                # %hard6begin
                                        #   in Loop: Header=BB3_1 Depth=1
	movl	12(%rsp), %edi
	callq	test
	movl	%eax, 20(%rsp)
	movl	%eax, %edi
	callq	write
	incl	12(%rsp)
.LBB3_1:                                # %hard6before
                                        # =>This Inner Loop Header: Depth=1
	movl	12(%rsp), %eax
	cmpl	16(%rsp), %eax
	jle	.LBB3_2
# %bb.3:                                # %hard6end
	movl	$1, %eax
	addq	$24, %rsp
	retq
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
                                        # -- End function
	.type	_a,@object              # @_a
	.comm	_a,4,4
	.type	b,@object               # @b
	.comm	b,4,4
	.type	c,@object               # @c
	.comm	c,4,4

	.section	".note.GNU-stack","",@progbits
