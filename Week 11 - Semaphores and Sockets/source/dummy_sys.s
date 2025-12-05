	.file	"dummy_sys.c"
	.text
	.section	.rodata
.LC0:
	.string	"-c"
.LC1:
	.string	"/bin/sh"
	.text
	.globl	my_system
	.type	my_system, @function
my_system:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$304, %rsp
	movq	%rdi, -296(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	call	fork@PLT
	movl	%eax, -276(%rbp)
	cmpl	$0, -276(%rbp)
	jne	.L2
	movq	-296(%rbp), %rax
	movl	$0, %r8d
	movq	%rax, %rcx
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	execl@PLT
	movl	$1, %edi
	call	_exit@PLT
.L2:
	cmpl	$0, -276(%rbp)
	jns	.L3
	movl	$-1, -280(%rbp)
	jmp	.L4
.L3:
	leaq	-280(%rbp), %rcx
	movl	-276(%rbp), %eax
	movl	$0, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	waitpid@PLT
	cmpl	%eax, -276(%rbp)
	je	.L4
	movl	$-1, -280(%rbp)
.L4:
	movl	-280(%rbp), %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	my_system, .-my_system
	.section	.rodata
.LC2:
	.string	"input command: "
.LC3:
	.string	"%s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$272, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
.L8:
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-272(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	-272(%rbp), %rax
	movq	%rax, %rdi
	call	my_system
	jmp	.L8
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
