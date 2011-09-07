	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:
Leh_func_begin1:
	pushq	%rbp
Ltmp0:
	movq	%rsp, %rbp
Ltmp1:
	subq	$176, %rsp
Ltmp2:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	LBB1_19
LBB1_1:
	movl	-20(%rbp), %eax
	cmpl	$36, %eax
	movl	%eax, -136(%rbp)
	jg	LBB1_25
	movl	-136(%rbp), %eax
	cmpl	$10, %eax
	je	LBB1_17
	jmp	LBB1_18
LBB1_25:
	movl	-136(%rbp), %eax
	cmpl	$93, %eax
	jg	LBB1_27
	movl	-136(%rbp), %eax
	cmpl	$82, %eax
	jg	LBB1_29
	movl	-136(%rbp), %eax
	cmpl	$68, %eax
	jg	LBB1_31
	movl	-136(%rbp), %eax
	cmpl	$60, %eax
	jg	LBB1_33
	movl	-136(%rbp), %eax
	leal	-37(%rax), %ecx
	cmpl	$13, %ecx
	movq	%rcx, -144(%rbp)
	ja	LBB1_18
	leaq	LJTI1_0(%rip), %rax
	movq	-144(%rbp), %rcx
	movq	%rcx, %rdx
	movslq	(%rax,%rdx,4), %rdx
	leaq	(%rdx,%rax), %rax
	jmpq	*%rax
LBB1_33:
	movl	-136(%rbp), %eax
	cmpl	$61, %eax
	je	LBB1_16
	jmp	LBB1_18
LBB1_31:
	movl	-136(%rbp), %eax
	cmpl	$69, %eax
	je	LBB1_15
	jmp	LBB1_18
LBB1_29:
	movl	-136(%rbp), %eax
	cmpl	$83, %eax
	je	LBB1_14
	jmp	LBB1_18
LBB1_27:
	movl	-136(%rbp), %eax
	cmpl	$94, %eax
	je	LBB1_13
	jmp	LBB1_18
LBB1_2:
	leaq	-132(%rbp), %rax
	movq	%rax, %rdi
	callq	_atof
	callq	_push
	jmp	LBB1_19
LBB1_3:
	leaq	-132(%rbp), %rax
	movq	%rax, %rdi
	callq	_atof
	movd	%xmm0, %rax
	movabsq	$-9223372036854775808, %rcx
	xorq	%rcx, %rax
	movd	%rax, %xmm0
	callq	_push
	jmp	LBB1_19
LBB1_4:
	leaq	-132(%rbp), %rax
	movq	%rax, %rdi
	callq	_atof
	callq	_push
	jmp	LBB1_19
LBB1_5:
	callq	_pop
	movsd	%xmm0, -152(%rbp)
	callq	_pop
	movsd	-152(%rbp), %xmm1
	addsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	callq	_push
	jmp	LBB1_19
LBB1_6:
	callq	_pop
	movsd	%xmm0, -160(%rbp)
	callq	_pop
	movsd	-160(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	callq	_push
	jmp	LBB1_19
LBB1_7:
	callq	_pop
	movsd	%xmm0, -32(%rbp)
	callq	_pop
	movsd	-32(%rbp), %xmm1
	subsd	%xmm1, %xmm0
	callq	_push
	jmp	LBB1_19
LBB1_8:
	callq	_pop
	movsd	%xmm0, -32(%rbp)
	movsd	-32(%rbp), %xmm0
	movabsq	$0, %rax
	cvtsi2sdq	%rax, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	LBB1_9
	jp	LBB1_9
	jmp	LBB1_10
LBB1_9:
	callq	_pop
	movsd	-32(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	callq	_push
	jmp	LBB1_11
LBB1_10:
	leaq	L_.str(%rip), %rax
	movq	%rax, %rdi
	callq	_puts
LBB1_11:
	jmp	LBB1_19
LBB1_12:
	callq	_pop
	movsd	%xmm0, -32(%rbp)
	callq	_pop
	movsd	-32(%rbp), %xmm1
	callq	_fmod
	callq	_push
	jmp	LBB1_19
LBB1_13:
	callq	_pop
	movsd	%xmm0, -32(%rbp)
	callq	_pop
	movsd	-32(%rbp), %xmm1
	callq	_pow
	callq	_push
	jmp	LBB1_19
LBB1_14:
	callq	_pop
	callq	_sin
	callq	_push
	jmp	LBB1_19
LBB1_15:
	callq	_pop
	callq	_exp
	callq	_push
	jmp	LBB1_19
LBB1_16:
	callq	_pop
	cvttsd2si	%xmm0, %eax
	subl	$97, %eax
	movl	%eax, -164(%rbp)
	callq	_pop
	movl	-164(%rbp), %eax
	movslq	%eax, %rcx
	leaq	_vars(%rip), %rdx
	movabsq	$8, %rsi
	imulq	%rsi, %rcx
	movq	%rdx, %rsi
	addq	%rcx, %rsi
	movsd	%xmm0, (%rsi)
	movslq	%eax, %rax
	movabsq	$8, %rcx
	imulq	%rcx, %rax
	addq	%rax, %rdx
	movsd	(%rdx), %xmm0
	callq	_push
	jmp	LBB1_19
LBB1_17:
	callq	_pop
	movsd	%xmm0, _vars+976(%rip)
	movsd	_vars+976(%rip), %xmm0
	movb	$1, %cl
	leaq	L_.str1(%rip), %rdx
	movq	%rdx, %rdi
	movb	%cl, %al
	callq	_printf
	jmp	LBB1_19
LBB1_18:
	leaq	-132(%rbp), %rax
	xorb	%cl, %cl
	leaq	L_.str2(%rip), %rdx
	movq	%rdx, %rdi
	movq	%rax, %rsi
	movb	%cl, %al
	callq	_printf
LBB1_19:
	leaq	-132(%rbp), %rax
	movq	%rax, %rdi
	callq	_getop
	movl	%eax, %ecx
	movl	%ecx, -20(%rbp)
	movl	-20(%rbp), %ecx
	cmpl	$-1, %ecx
	jne	LBB1_1
	movl	$0, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -168(%rbp)
	jne	LBB1_23
	movl	-168(%rbp), %eax
	addq	$176, %rsp
	popq	%rbp
	ret
LBB1_23:
	callq	___stack_chk_fail
Leh_func_end1:
	.align	2, 0x90
L1_0_set_12 = LBB1_12-LJTI1_0
L1_0_set_18 = LBB1_18-LJTI1_0
L1_0_set_6 = LBB1_6-LJTI1_0
L1_0_set_5 = LBB1_5-LJTI1_0
L1_0_set_7 = LBB1_7-LJTI1_0
L1_0_set_8 = LBB1_8-LJTI1_0
L1_0_set_2 = LBB1_2-LJTI1_0
L1_0_set_3 = LBB1_3-LJTI1_0
L1_0_set_4 = LBB1_4-LJTI1_0
LJTI1_0:
	.long	L1_0_set_12
	.long	L1_0_set_18
	.long	L1_0_set_18
	.long	L1_0_set_18
	.long	L1_0_set_18
	.long	L1_0_set_6
	.long	L1_0_set_5
	.long	L1_0_set_18
	.long	L1_0_set_7
	.long	L1_0_set_18
	.long	L1_0_set_8
	.long	L1_0_set_2
	.long	L1_0_set_3
	.long	L1_0_set_4

	.globl	_push
	.align	4, 0x90
_push:
Leh_func_begin2:
	pushq	%rbp
Ltmp3:
	movq	%rsp, %rbp
Ltmp4:
	subq	$16, %rsp
Ltmp5:
	movsd	%xmm0, -8(%rbp)
	movl	_sp(%rip), %eax
	cmpl	$99, %eax
	jg	LBB2_2
	movl	_sp(%rip), %eax
	movslq	%eax, %rcx
	movq	_val@GOTPCREL(%rip), %rdx
	leaq	(%rdx), %rdx
	movabsq	$8, %rsi
	imulq	%rsi, %rcx
	addq	%rcx, %rdx
	movsd	-8(%rbp), %xmm0
	movsd	%xmm0, (%rdx)
	addl	$1, %eax
	movl	%eax, _sp(%rip)
	jmp	LBB2_3
LBB2_2:
	movsd	-8(%rbp), %xmm0
	movb	$1, %al
	leaq	L_.str3(%rip), %rcx
	movq	%rcx, %rdi
	callq	_printf
LBB2_3:
	addq	$16, %rsp
	popq	%rbp
	ret
Leh_func_end2:

	.globl	_pop
	.align	4, 0x90
_pop:
Leh_func_begin3:
	pushq	%rbp
Ltmp6:
	movq	%rsp, %rbp
Ltmp7:
	subq	$16, %rsp
Ltmp8:
	movl	_sp(%rip), %eax
	cmpl	$0, %eax
	jle	LBB3_2
	movl	_sp(%rip), %eax
	subl	$1, %eax
	movl	%eax, _sp(%rip)
	movl	_sp(%rip), %eax
	movslq	%eax, %rax
	movq	_val@GOTPCREL(%rip), %rcx
	leaq	(%rcx), %rcx
	movabsq	$8, %rdx
	imulq	%rdx, %rax
	addq	%rax, %rcx
	movsd	(%rcx), %xmm0
	movsd	%xmm0, -16(%rbp)
	jmp	LBB3_3
LBB3_2:
	leaq	L_.str4(%rip), %rax
	movq	%rax, %rdi
	callq	_puts
	movabsq	$0, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	%xmm0, -16(%rbp)
LBB3_3:
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
Leh_func_end3:

	.globl	_getop
	.align	4, 0x90
_getop:
Leh_func_begin4:
	pushq	%rbp
Ltmp9:
	movq	%rsp, %rbp
Ltmp10:
	subq	$48, %rsp
Ltmp11:
	movq	%rdi, -8(%rbp)
	movl	$1, -36(%rbp)
LBB4_1:
	callq	_getch
	movl	%eax, %ecx
	movl	%ecx, -28(%rbp)
	movl	-28(%rbp), %ecx
	movq	-8(%rbp), %rdx
	movb	%cl, (%rdx)
	movq	-8(%rbp), %rcx
	movb	(%rcx), %cl
	cmpb	$32, %cl
	je	LBB4_1
	movl	-28(%rbp), %eax
	cmpl	$9, %eax
	je	LBB4_1
	movq	-8(%rbp), %rax
	movb	$0, 1(%rax)
	movl	-28(%rbp), %eax
	cmpl	$45, %eax
	jne	LBB4_7
	callq	_getch
	movl	%eax, %ecx
	movl	%ecx, -32(%rbp)
	movl	-32(%rbp), %ecx
	movl	%ecx, %edi
	callq	_isdigit
	movl	%eax, %ecx
	cmpl	$0, %ecx
	je	LBB4_6
	movl	-32(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movq	-8(%rbp), %rcx
	movb	%al, (%rcx)
	movl	$-1, -36(%rbp)
	jmp	LBB4_7
LBB4_6:
	movl	-32(%rbp), %eax
	movl	%eax, %edi
	callq	_ungetch
LBB4_7:
	movl	-28(%rbp), %eax
	cmpl	$96, %eax
	jle	LBB4_13
	movl	-28(%rbp), %eax
	cmpl	$122, %eax
	jg	LBB4_13
	callq	_getch
	movl	%eax, %ecx
	movl	%ecx, -32(%rbp)
	movl	-32(%rbp), %ecx
	cmpl	$32, %ecx
	je	LBB4_11
	movl	-32(%rbp), %eax
	cmpl	$9, %eax
	jne	LBB4_12
LBB4_11:
	movl	$50, -20(%rbp)
	jmp	LBB4_26
LBB4_12:
	movl	-32(%rbp), %eax
	movl	%eax, %edi
	callq	_ungetch
LBB4_13:
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	callq	_isdigit
	movl	%eax, %ecx
	cmpl	$0, %ecx
	jne	LBB4_16
	movl	-28(%rbp), %eax
	cmpl	$46, %eax
	je	LBB4_16
	movl	-28(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp	LBB4_26
LBB4_16:
	movl	$0, -24(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	callq	_isdigit
	movl	%eax, %ecx
	cmpl	$0, %ecx
	je	LBB4_18
LBB4_17:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	callq	_getch
	movl	%eax, %ecx
	movl	%ecx, -28(%rbp)
	movl	-28(%rbp), %ecx
	movq	-8(%rbp), %rdx
	movl	-24(%rbp), %esi
	movslq	%esi, %rsi
	movb	%cl, (%rdx,%rsi)
	movq	-8(%rbp), %rcx
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	movb	(%rcx,%rdx), %cl
	movsbl	%cl, %ecx
	movl	%ecx, %edi
	callq	_isdigit
	movl	%eax, %ecx
	cmpl	$0, %ecx
	jne	LBB4_17
LBB4_18:
	movl	-28(%rbp), %eax
	cmpl	$46, %eax
	jne	LBB4_20
LBB4_19:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	callq	_getch
	movl	%eax, %ecx
	movl	%ecx, -28(%rbp)
	movl	-28(%rbp), %ecx
	movq	-8(%rbp), %rdx
	movl	-24(%rbp), %esi
	movslq	%esi, %rsi
	movb	%cl, (%rdx,%rsi)
	movq	-8(%rbp), %rcx
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	movb	(%rcx,%rdx), %cl
	movsbl	%cl, %ecx
	movl	%ecx, %edi
	callq	_isdigit
	movl	%eax, %ecx
	cmpl	$0, %ecx
	jne	LBB4_19
LBB4_20:
	movq	-8(%rbp), %rax
	movl	-24(%rbp), %ecx
	movslq	%ecx, %rcx
	movb	$0, (%rax,%rcx)
	movl	-28(%rbp), %eax
	cmpl	$-1, %eax
	je	LBB4_22
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	callq	_ungetch
LBB4_22:
	movl	-36(%rbp), %eax
	cmpl	$0, %eax
	jle	LBB4_24
	movl	$48, -16(%rbp)
	jmp	LBB4_25
LBB4_24:
	movl	$49, -16(%rbp)
LBB4_25:
	movl	-16(%rbp), %eax
	movl	%eax, -20(%rbp)
LBB4_26:
	movl	-20(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
Leh_func_end4:

	.align	4, 0x90
_isdigit:
Leh_func_begin5:
	pushq	%rbp
Ltmp12:
	movq	%rsp, %rbp
Ltmp13:
	subq	$16, %rsp
Ltmp14:
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movabsq	$1024, %rcx
	movl	%eax, %edi
	movq	%rcx, %rsi
	callq	___isctype
	movl	%eax, %ecx
	movl	%ecx, -12(%rbp)
	movl	-12(%rbp), %ecx
	movl	%ecx, -8(%rbp)
	movl	-8(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
Leh_func_end5:

	.align	4, 0x90
___isctype:
Leh_func_begin6:
	pushq	%rbp
Ltmp15:
	movq	%rsp, %rbp
Ltmp16:
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$0, %eax
	jl	LBB6_4
	movl	-4(%rbp), %eax
	cmpl	$255, %eax
	jg	LBB6_4
	movl	-4(%rbp), %eax
	movslq	%eax, %rax
	movq	__DefaultRuneLocale@GOTPCREL(%rip), %rcx
	leaq	(%rcx), %rcx
	movabsq	$60, %rdx
	addq	%rdx, %rcx
	movl	(%rcx,%rax,4), %eax
	movl	%eax, %eax
	movq	-16(%rbp), %rcx
	andq	%rcx, %rax
	cmpq	$0, %rax
	je	LBB6_4
	movl	$1, -24(%rbp)
	jmp	LBB6_5
LBB6_4:
	movl	$0, -24(%rbp)
LBB6_5:
	movl	-24(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	popq	%rbp
	ret
Leh_func_end6:

	.globl	_getch
	.align	4, 0x90
_getch:
Leh_func_begin7:
	pushq	%rbp
Ltmp17:
	movq	%rsp, %rbp
Ltmp18:
	subq	$16, %rsp
Ltmp19:
	movl	_bufp(%rip), %eax
	cmpl	$0, %eax
	jle	LBB7_2
	movl	_bufp(%rip), %eax
	subl	$1, %eax
	movl	%eax, _bufp(%rip)
	movl	_bufp(%rip), %eax
	movslq	%eax, %rax
	movq	_buf@GOTPCREL(%rip), %rcx
	leaq	(%rcx), %rcx
	addq	%rax, %rcx
	movb	(%rcx), %al
	movsbl	%al, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB7_3
LBB7_2:
	callq	_getchar
	movl	%eax, %ecx
	movl	%ecx, -8(%rbp)
LBB7_3:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
Leh_func_end7:

	.globl	_ungetch
	.align	4, 0x90
_ungetch:
Leh_func_begin8:
	pushq	%rbp
Ltmp20:
	movq	%rsp, %rbp
Ltmp21:
	subq	$16, %rsp
Ltmp22:
	movl	%edi, -4(%rbp)
	movl	_bufp(%rip), %eax
	cmpl	$99, %eax
	jle	LBB8_2
	leaq	L_.str5(%rip), %rax
	movq	%rax, %rdi
	callq	_puts
	jmp	LBB8_3
LBB8_2:
	movl	_bufp(%rip), %eax
	movl	-4(%rbp), %ecx
	movslq	%eax, %rdx
	movq	_buf@GOTPCREL(%rip), %rsi
	leaq	(%rsi), %rsi
	addq	%rdx, %rsi
	movb	%cl, (%rsi)
	addl	$1, %eax
	movl	%eax, _bufp(%rip)
LBB8_3:
	addq	$16, %rsp
	popq	%rbp
	ret
Leh_func_end8:

	.globl	_sp
.zerofill __DATA,__common,_sp,4,2
	.globl	_bufp
.zerofill __DATA,__common,_bufp,4,2
	.globl	_vars
.zerofill __DATA,__common,_vars,208,5
	.section	__TEXT,__cstring,cstring_literals
L_.str:
	.asciz	 "error: zero divisor"

L_.str1:
	.asciz	 "%.8g\n"

L_.str2:
	.asciz	 "error: unknown command %s\n"

	.comm	_val,800,5
	.align	3
L_.str3:
	.asciz	 "error: stack full, can't push %g\n"

L_.str4:
	.asciz	 "error: stack empty"

	.comm	_buf,100,5
L_.str5:
	.asciz	 "ungetch: too many characters"

	.section	__TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame0:
Lsection_eh_frame:
Leh_frame_common:
Lset0 = Leh_frame_common_end-Leh_frame_common_begin
	.long	Lset0
Leh_frame_common_begin:
	.long	0
	.byte	1
	.asciz	 "zR"
	.byte	1
	.byte	120
	.byte	16
	.byte	1
	.byte	16
	.byte	12
	.byte	7
	.byte	8
	.byte	144
	.byte	1
	.align	3
Leh_frame_common_end:
	.globl	_main.eh
_main.eh:
Lset1 = Leh_frame_end1-Leh_frame_begin1
	.long	Lset1
Leh_frame_begin1:
Lset2 = Leh_frame_begin1-Leh_frame_common
	.long	Lset2
Ltmp23:
	.quad	Leh_func_begin1-Ltmp23
Lset3 = Leh_func_end1-Leh_func_begin1
	.quad	Lset3
	.byte	0
	.byte	4
Lset4 = Ltmp0-Leh_func_begin1
	.long	Lset4
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset5 = Ltmp1-Ltmp0
	.long	Lset5
	.byte	13
	.byte	6
	.align	3
Leh_frame_end1:

	.globl	_push.eh
_push.eh:
Lset6 = Leh_frame_end2-Leh_frame_begin2
	.long	Lset6
Leh_frame_begin2:
Lset7 = Leh_frame_begin2-Leh_frame_common
	.long	Lset7
Ltmp24:
	.quad	Leh_func_begin2-Ltmp24
Lset8 = Leh_func_end2-Leh_func_begin2
	.quad	Lset8
	.byte	0
	.byte	4
Lset9 = Ltmp3-Leh_func_begin2
	.long	Lset9
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset10 = Ltmp4-Ltmp3
	.long	Lset10
	.byte	13
	.byte	6
	.align	3
Leh_frame_end2:

	.globl	_pop.eh
_pop.eh:
Lset11 = Leh_frame_end3-Leh_frame_begin3
	.long	Lset11
Leh_frame_begin3:
Lset12 = Leh_frame_begin3-Leh_frame_common
	.long	Lset12
Ltmp25:
	.quad	Leh_func_begin3-Ltmp25
Lset13 = Leh_func_end3-Leh_func_begin3
	.quad	Lset13
	.byte	0
	.byte	4
Lset14 = Ltmp6-Leh_func_begin3
	.long	Lset14
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset15 = Ltmp7-Ltmp6
	.long	Lset15
	.byte	13
	.byte	6
	.align	3
Leh_frame_end3:

	.globl	_getop.eh
_getop.eh:
Lset16 = Leh_frame_end4-Leh_frame_begin4
	.long	Lset16
Leh_frame_begin4:
Lset17 = Leh_frame_begin4-Leh_frame_common
	.long	Lset17
Ltmp26:
	.quad	Leh_func_begin4-Ltmp26
Lset18 = Leh_func_end4-Leh_func_begin4
	.quad	Lset18
	.byte	0
	.byte	4
Lset19 = Ltmp9-Leh_func_begin4
	.long	Lset19
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset20 = Ltmp10-Ltmp9
	.long	Lset20
	.byte	13
	.byte	6
	.align	3
Leh_frame_end4:

_isdigit.eh:
Lset21 = Leh_frame_end5-Leh_frame_begin5
	.long	Lset21
Leh_frame_begin5:
Lset22 = Leh_frame_begin5-Leh_frame_common
	.long	Lset22
Ltmp27:
	.quad	Leh_func_begin5-Ltmp27
Lset23 = Leh_func_end5-Leh_func_begin5
	.quad	Lset23
	.byte	0
	.byte	4
Lset24 = Ltmp12-Leh_func_begin5
	.long	Lset24
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset25 = Ltmp13-Ltmp12
	.long	Lset25
	.byte	13
	.byte	6
	.align	3
Leh_frame_end5:

___isctype.eh:
Lset26 = Leh_frame_end6-Leh_frame_begin6
	.long	Lset26
Leh_frame_begin6:
Lset27 = Leh_frame_begin6-Leh_frame_common
	.long	Lset27
Ltmp28:
	.quad	Leh_func_begin6-Ltmp28
Lset28 = Leh_func_end6-Leh_func_begin6
	.quad	Lset28
	.byte	0
	.byte	4
Lset29 = Ltmp15-Leh_func_begin6
	.long	Lset29
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset30 = Ltmp16-Ltmp15
	.long	Lset30
	.byte	13
	.byte	6
	.align	3
Leh_frame_end6:

	.globl	_getch.eh
_getch.eh:
Lset31 = Leh_frame_end7-Leh_frame_begin7
	.long	Lset31
Leh_frame_begin7:
Lset32 = Leh_frame_begin7-Leh_frame_common
	.long	Lset32
Ltmp29:
	.quad	Leh_func_begin7-Ltmp29
Lset33 = Leh_func_end7-Leh_func_begin7
	.quad	Lset33
	.byte	0
	.byte	4
Lset34 = Ltmp17-Leh_func_begin7
	.long	Lset34
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset35 = Ltmp18-Ltmp17
	.long	Lset35
	.byte	13
	.byte	6
	.align	3
Leh_frame_end7:

	.globl	_ungetch.eh
_ungetch.eh:
Lset36 = Leh_frame_end8-Leh_frame_begin8
	.long	Lset36
Leh_frame_begin8:
Lset37 = Leh_frame_begin8-Leh_frame_common
	.long	Lset37
Ltmp30:
	.quad	Leh_func_begin8-Ltmp30
Lset38 = Leh_func_end8-Leh_func_begin8
	.quad	Lset38
	.byte	0
	.byte	4
Lset39 = Ltmp20-Leh_func_begin8
	.long	Lset39
	.byte	14
	.byte	16
	.byte	134
	.byte	2
	.byte	4
Lset40 = Ltmp21-Ltmp20
	.long	Lset40
	.byte	13
	.byte	6
	.align	3
Leh_frame_end8:


.subsections_via_symbols
