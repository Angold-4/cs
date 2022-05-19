	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_fib                            ## -- Begin function fib
	.p2align	4, 0x90
_fib:                                   ## @fib
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	cmpq	$2, -16(%rbp)
	jge	LBB0_2
## %bb.1:
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB0_3
LBB0_2:
	movq	-16(%rbp), %rdi
	subq	$1, %rdi
	callq	_fib
	movq	%rax, -24(%rbp)                 ## 8-byte Spill
	movq	-16(%rbp), %rdi
	subq	$2, %rdi
	callq	_fib
	movq	%rax, %rcx
	movq	-24(%rbp), %rax                 ## 8-byte Reload
	addq	%rcx, %rax
	movq	%rax, -8(%rbp)
LBB0_3:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp                            ## ret addr of prev called function
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$10, %edi
	callq	_fib
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
