	.text
	.abicalls
	.option	pic0
	.section	.mdebug.abi32,"",@progbits
	.nan	legacy
	.file	"tt.c"
	.text
	.globl	fibo                    # -- Begin function fibo
	.p2align	2
	.type	fibo,@function
	.set	nomicromips
	.set	nomips16
	.ent	fibo
fibo:                                   # @fibo
	.cfi_startproc
	.frame	$fp,40,$ra
	.mask 	0xc0010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:
	addiu	$sp, $sp, -40
	.cfi_def_cfa_offset 40
	sw	$ra, 36($sp)            # 4-byte Folded Spill
	sw	$fp, 32($sp)            # 4-byte Folded Spill
	sw	$16, 28($sp)            # 4-byte Folded Spill
	.cfi_offset 31, -4
	.cfi_offset 30, -8
	.cfi_offset 16, -12
	move	$fp, $sp
	.cfi_def_cfa_register 30
	sw	$4, 20($fp)
	lw	$1, 20($fp)
	addiu	$2, $zero, 1
	beq	$1, $2, $BB0_4
	nop
# %bb.1:
	j	$BB0_2
	nop
$BB0_2:
	lw	$1, 20($fp)
	addiu	$2, $zero, 2
	bne	$1, $2, $BB0_5
	nop
# %bb.3:
	j	$BB0_4
	nop
$BB0_4:
	addiu	$1, $zero, 1
	j	$BB0_6
	sw	$1, 24($fp)
$BB0_5:
	lw	$1, 20($fp)
	jal	fibo
	addiu	$4, $1, -1
	move	$16, $2
	lw	$1, 20($fp)
	jal	fibo
	addiu	$4, $1, -2
	addu	$1, $16, $2
	j	$BB0_6
	sw	$1, 24($fp)
$BB0_6:
	lw	$2, 24($fp)
	move	$sp, $fp
	lw	$16, 28($sp)            # 4-byte Folded Reload
	lw	$fp, 32($sp)            # 4-byte Folded Reload
	lw	$ra, 36($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
	.set	at
	.set	macro
	.set	reorder
	.end	fibo
$func_end0:
	.size	fibo, ($func_end0)-fibo
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	2
	.type	main,@function
	.set	nomicromips
	.set	nomips16
	.ent	main
main:                                   # @main
	.cfi_startproc
	.frame	$fp,48,$ra
	.mask 	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:
	addiu	$sp, $sp, -48
	.cfi_def_cfa_offset 48
	sw	$ra, 44($sp)            # 4-byte Folded Spill
	sw	$fp, 40($sp)            # 4-byte Folded Spill
	.cfi_offset 31, -4
	.cfi_offset 30, -8
	move	$fp, $sp
	.cfi_def_cfa_register 30
	jal	getchar
	sw	$zero, 36($fp)
	sw	$2, 32($fp)
	addiu	$1, $zero, 1
	j	$BB1_1
	sw	$1, 24($fp)
$BB1_1:                                 # =>This Inner Loop Header: Depth=1
	lw	$1, 24($fp)
	lw	$2, 32($fp)
	slt	$1, $2, $1
	bnez	$1, $BB1_4
	nop
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	j	$BB1_3
	nop
$BB1_3:                                 #   in Loop: Header=BB1_1 Depth=1
	lw	$1, 28($fp)
	sw	$1, 20($fp)
	jal	fibo
	lw	$4, 24($fp)
	sw	$2, 28($fp)
	jal	putchar
	addiu	$4, $zero, 49
	lw	$1, 24($fp)
	addiu	$1, $1, 1
	j	$BB1_1
	sw	$1, 24($fp)
$BB1_4:
	addiu	$2, $zero, 1
	move	$sp, $fp
	lw	$fp, 40($sp)            # 4-byte Folded Reload
	lw	$ra, 44($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 48
	.set	at
	.set	macro
	.set	reorder
	.end	main
$func_end1:
	.size	main, ($func_end1)-main
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
	.text
