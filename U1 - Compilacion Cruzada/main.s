	.cpu cortex-m3
	.arch armv7-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 1 "main.c"
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
.LFB0:
	.loc 1 7 1
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	.cfi_def_cfa_offset 4
	.cfi_offset 7, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 16
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	.loc 1 9 4
	ldr	r3, .L7
	ldr	r3, [r3]
	.loc 1 9 25
	orr	r2, r3, #16
	.loc 1 9 4
	ldr	r3, .L7
	.loc 1 9 25
	str	r2, [r3]
	.loc 1 13 4
	ldr	r3, .L7+4
	ldr	r3, [r3]
	ldr	r2, .L7+4
	.loc 1 13 36
	orr	r3, r3, #3145728
	str	r3, [r2]
	.loc 1 15 4
	ldr	r3, .L7+4
	ldr	r3, [r3]
	ldr	r2, .L7+4
	.loc 1 15 36
	bic	r3, r3, #12582912
	str	r3, [r2]
.L6:
	.loc 1 19 6
	ldr	r3, .L7+8
	ldr	r3, [r3]
	ldr	r2, .L7+8
	.loc 1 19 38
	orr	r3, r3, #8192
	str	r3, [r2]
.LBB2:
	.loc 1 22 13
	movs	r3, #0
	str	r3, [r7, #4]
	.loc 1 22 5
	b	.L2
.L3:
	.loc 1 22 33 discriminator 3
	ldr	r3, [r7, #4]
	adds	r3, r3, #1
	str	r3, [r7, #4]
.L2:
	.loc 1 22 22 discriminator 1
	ldr	r3, [r7, #4]
	ldr	r2, .L7+12
	cmp	r3, r2
	ble	.L3
.LBE2:
	.loc 1 25 6
	ldr	r3, .L7+8
	ldr	r3, [r3]
	ldr	r2, .L7+8
	.loc 1 25 38
	bic	r3, r3, #8192
	str	r3, [r2]
.LBB3:
	.loc 1 28 13
	movs	r3, #0
	str	r3, [r7]
	.loc 1 28 5
	b	.L4
.L5:
	.loc 1 28 33 discriminator 3
	ldr	r3, [r7]
	adds	r3, r3, #1
	str	r3, [r7]
.L4:
	.loc 1 28 22 discriminator 1
	ldr	r3, [r7]
	ldr	r2, .L7+12
	cmp	r3, r2
	ble	.L5
.LBE3:
	.loc 1 19 38
	b	.L6
.L8:
	.align	2
.L7:
	.word	1073877016
	.word	1073811460
	.word	1073811468
	.word	499999
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Letext0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x73
	.2byte	0x5
	.byte	0x1
	.byte	0x4
	.4byte	.Ldebug_abbrev0
	.uleb128 0x2
	.4byte	.LASF0
	.byte	0x1d
	.4byte	.LASF1
	.4byte	.LASF2
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x3
	.4byte	.LASF3
	.byte	0x1
	.byte	0x6
	.byte	0x5
	.4byte	0x6f
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x6f
	.uleb128 0x4
	.4byte	.LBB2
	.4byte	.LBE2-.LBB2
	.4byte	0x59
	.uleb128 0x1
	.ascii	"i\000"
	.byte	0x16
	.4byte	0x6f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x5
	.4byte	.LBB3
	.4byte	.LBE3-.LBB3
	.uleb128 0x1
	.ascii	"i\000"
	.byte	0x1c
	.4byte	0x6f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 13
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF1:
	.ascii	"main.c\000"
.LASF2:
	.ascii	"/home/lucasvidmar/Documents/Embebidos/TPs/U1 - Comp"
	.ascii	"ilacion Cruzada\000"
.LASF0:
	.ascii	"GNU C17 12.2.0 -mcpu=cortex-m3 -mthumb -mfloat-abi="
	.ascii	"soft -march=armv7-m -g\000"
.LASF3:
	.ascii	"main\000"
	.ident	"GCC: (Fedora 12.2.0-1.fc37) 12.2.0"
