## a. Ver secciones del .o 

> arm-none-eabi-objdump -h main.o

*main.o:     file format elf32-littlearm* 

```
Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         00000050  00000000  00000000  00000034  2**2
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000000  00000000  00000000  00000084  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  00000000  00000000  00000084  2**0
                  ALLOC
  3 .debug_info   0000006c  00000000  00000000  00000084  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
  4 .debug_abbrev 0000006b  00000000  00000000  000000f0  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
  5 .debug_aranges 00000020  00000000  00000000  0000015b  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
  6 .debug_line   00000092  00000000  00000000  0000017b  2**0
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
  7 .debug_str    000000bb  00000000  00000000  0000020d  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
  8 .comment      00000024  00000000  00000000  000002c8  2**0
                  CONTENTS, READONLY
  9 .debug_frame  0000002c  00000000  00000000  000002ec  2**2
                  CONTENTS, RELOC, READONLY, DEBUGGING, OCTETS
 10 .ARM.attributes 0000002d  00000000  00000000  00000318  2**0
                  CONTENTS, READONLY
```

## b. Disassembly de section .text:

> arm-none-eabi-objdump -d main.o

*main.o:     file format elf32-littlearm*

```
Disassembly of section .text:

00000000 <main>:
   0:   b580            push    {r7, lr}
   2:   af00            add     r7, sp, #0
   4:   4b0f            ldr     r3, [pc, #60]   @ (44 <main+0x44>)
   6:   681b            ldr     r3, [r3, #0]
   8:   f043 0210       orr.w   r2, r3, #16
   c:   4b0d            ldr     r3, [pc, #52]   @ (44 <main+0x44>)
   e:   601a            str     r2, [r3, #0]
  10:   4b0d            ldr     r3, [pc, #52]   @ (48 <main+0x48>)
  12:   681b            ldr     r3, [r3, #0]
  14:   4a0c            ldr     r2, [pc, #48]   @ (48 <main+0x48>)
  16:   f443 1340       orr.w   r3, r3, #3145728        @ 0x300000
  1a:   6013            str     r3, [r2, #0]
  1c:   4b0a            ldr     r3, [pc, #40]   @ (48 <main+0x48>)
  1e:   681b            ldr     r3, [r3, #0]
  20:   4a09            ldr     r2, [pc, #36]   @ (48 <main+0x48>)
  22:   f423 0340       bic.w   r3, r3, #12582912       @ 0xc00000
  26:   6013            str     r3, [r2, #0]
  28:   200d            movs    r0, #13
  2a:   f7ff fffe       bl      0 <apagarLeds>
  2e:   4807            ldr     r0, [pc, #28]   @ (4c <main+0x4c>)
  30:   f7ff fffe       bl      0 <softwareDelay>
  34:   200d            movs    r0, #13
  36:   f7ff fffe       bl      0 <apagarLeds>
  3a:   4804            ldr     r0, [pc, #16]   @ (4c <main+0x4c>)
  3c:   f7ff fffe       bl      0 <softwareDelay>
  40:   bf00            nop
  42:   e7f1            b.n     28 <main+0x28>
  44:   40021018        .word   0x40021018
  48:   40011004        .word   0x40011004
  4c:   0007a120        .word   0x0007a120
```


## c. Todas las seccciones

> arm-none-eabi-objdump -D main.o

*main.o:     file format elf32-littlearm*

```
Disassembly of section .text:

00000000 <main>:
   0:   b580            push    {r7, lr}
   2:   af00            add     r7, sp, #0
   4:   4b0f            ldr     r3, [pc, #60]   @ (44 <main+0x44>)
   6:   681b            ldr     r3, [r3, #0]
   8:   f043 0210       orr.w   r2, r3, #16
   c:   4b0d            ldr     r3, [pc, #52]   @ (44 <main+0x44>)
   e:   601a            str     r2, [r3, #0]
  10:   4b0d            ldr     r3, [pc, #52]   @ (48 <main+0x48>)
  12:   681b            ldr     r3, [r3, #0]
  14:   4a0c            ldr     r2, [pc, #48]   @ (48 <main+0x48>)
  16:   f443 1340       orr.w   r3, r3, #3145728        @ 0x300000
  1a:   6013            str     r3, [r2, #0]
  1c:   4b0a            ldr     r3, [pc, #40]   @ (48 <main+0x48>)
  1e:   681b            ldr     r3, [r3, #0]
  20:   4a09            ldr     r2, [pc, #36]   @ (48 <main+0x48>)
  22:   f423 0340       bic.w   r3, r3, #12582912       @ 0xc00000
  26:   6013            str     r3, [r2, #0]
  28:   200d            movs    r0, #13
  2a:   f7ff fffe       bl      0 <apagarLeds>
  2e:   4807            ldr     r0, [pc, #28]   @ (4c <main+0x4c>)
  30:   f7ff fffe       bl      0 <softwareDelay>
  34:   200d            movs    r0, #13
  36:   f7ff fffe       bl      0 <apagarLeds>
  3a:   4804            ldr     r0, [pc, #16]   @ (4c <main+0x4c>)
  3c:   f7ff fffe       bl      0 <softwareDelay>
  40:   bf00            nop
  42:   e7f1            b.n     28 <main+0x28>
  44:   40021018        andmi   r1, r2, r8, lsl r0
  48:   40011004        andmi   r1, r1, r4
  4c:   0007a120        andeq   sl, r7, r0, lsr #2

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:   00000068        andeq   r0, r0, r8, rrx
   4:   04010005        streq   r0, [r1], #-5
   8:   00000000        andeq   r0, r0, r0
   c:   00005302        andeq   r5, r0, r2, lsl #6
  10:   00001d00        andeq   r1, r0, r0, lsl #26
  14:   00100000        andseq  r0, r0, r0
  18:   00000000        andeq   r0, r0, r0
  1c:   00500000        subseq  r0, r0, r0
  20:   00000000        andeq   r0, r0, r0
  24:   9d030000        stcls   0, cr0, [r3, #-0]
  28:   02000000        andeq   r0, r0, #0
  2c:   0038060b        eorseq  r0, r8, fp, lsl #12
  30:   38010000        stmdacc r1, {}  @ <UNPREDICTABLE>
  34:   00000000        andeq   r0, r0, r0
  38:   69050404        stmdbvs r5, {r2, sl}
  3c:   0500746e        streq   r7, [r0, #-1134]        @ 0xfffffb92
  40:   000000b0        strheq  r0, [r0], -r0   @ <UNPREDICTABLE>
  44:   38050702        stmdacc r5, {r1, r8, r9, sl}
  48:   55000000        strpl   r0, [r0, #-0]
  4c:   01000000        mrseq   r0, (UNDEF: 0)
  50:   00000038        andeq   r0, r0, r8, lsr r0
  54:   00ab0600        adceq   r0, fp, r0, lsl #12
  58:   04010000        streq   r0, [r1], #-0
  5c:   00003805        andeq   r3, r0, r5, lsl #16
  60:   00000000        andeq   r0, r0, r0
  64:   00005000        andeq   r5, r0, r0
  68:   009c0100        addseq  r0, ip, r0, lsl #2

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:   49000501        stmdbmi r0, {r0, r8, sl}
   4:   02000013        andeq   r0, r0, #19
   8:   0e250111        mcreq   1, 1, r0, cr5, cr1, {0}
   c:   0e030b13        vmoveq.32       d3[0], r0
  10:   01110e1b        tsteq   r1, fp, lsl lr
  14:   17100612                        @ <UNDEFINED> instruction: 0x17100612
  18:   2e030000        cdpcs   0, 0, cr0, cr3, cr0, {0}
  1c:   03193f01        tsteq   r9, #1, 30
  20:   3b0b3a0e        blcc    2ce860 <main+0x2ce860>
  24:   270b390b        strcs   r3, [fp, -fp, lsl #18]
  28:   01193c19        tsteq   r9, r9, lsl ip
  2c:   04000013        streq   r0, [r0], #-19  @ 0xffffffed
  30:   0b0b0024        bleq    2c00c8 <main+0x2c00c8>
  34:   08030b3e        stmdaeq r3, {r1, r2, r3, r4, r5, r8, r9, fp}
  38:   2e050000        cdpcs   0, 0, cr0, cr5, cr0, {0}
  3c:   03193f01        tsteq   r9, #1, 30
  40:   3b0b3a0e        blcc    2ce880 <main+0x2ce880>
  44:   270b390b        strcs   r3, [fp, -fp, lsl #18]
  48:   3c134919                        @ <UNDEFINED> instruction: 0x3c134919
  4c:   00130119        andseq  r0, r3, r9, lsl r1
  50:   002e0600        eoreq   r0, lr, r0, lsl #12
  54:   0e03193f                        @ <UNDEFINED> instruction: 0x0e03193f
  58:   0b3b0b3a        bleq    ec2d48 <main+0xec2d48>
  5c:   13490b39        movtne  r0, #39737      @ 0x9b39
  60:   06120111                        @ <UNDEFINED> instruction: 0x06120111
  64:   197c1840        ldmdbne ip!, {r6, fp, ip}^
  68:   Address 0x68 is out of bounds.


Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:   0000001c        andeq   r0, r0, ip, lsl r0
   4:   00000002        andeq   r0, r0, r2
   8:   00040000        andeq   r0, r4, r0
        ...
  14:   00000050        andeq   r0, r0, r0, asr r0
        ...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:   0000008e        andeq   r0, r0, lr, lsl #1
   4:   00440003        subeq   r0, r4, r3
   8:   01020000        mrseq   r0, (UNDEF: 2)
   c:   000d0efb        strdeq  r0, [sp], -fp
  10:   01010101        tsteq   r1, r1, lsl #2
  14:   01000000        mrseq   r0, (UNDEF: 0)
  18:   2e010000        cdpcs   0, 0, cr0, cr1, cr0, {0}
  1c:   6946432f        stmdbvs r6, {r0, r1, r2, r3, r5, r8, r9, lr}^
  20:   0073656c        rsbseq  r6, r3, ip, ror #10
  24:   46432f2e        strbmi  r2, [r3], -lr, lsr #30
  28:   73656c69        cmnvc   r5, #26880      @ 0x6900
  2c:   2f2e2e2f        svccs   0x002e2e2f
  30:   64616548        strbtvs r6, [r1], #-1352        @ 0xfffffab8
  34:   00737265        rsbseq  r7, r3, r5, ror #4
  38:   69616d00        stmdbvs r1!, {r8, sl, fp, sp, lr}^
  3c:   00632e6e        rsbeq   r2, r3, lr, ror #28
  40:   6c000001        stcvs   0, cr0, [r0], {1}
  44:   2e736465        cdpcs   4, 7, cr6, cr3, cr5, {3}
  48:   00020068        andeq   r0, r2, r8, rrx
  4c:   01050000        mrseq   r0, (UNDEF: 5)
  50:   00020500        andeq   r0, r2, r0, lsl #10
  54:   16000000        strne   r0, [r0], -r0
  58:   05300305        ldreq   r0, [r0, #-773]!        @ 0xfffffcfb
  5c:   03052e0f        movweq  r2, #24079      @ 0x5e0f
  60:   200f052e        andcs   r0, pc, lr, lsr #10
  64:   05240305        streq   r0, [r4, #-773]!        @ 0xfffffcfb
  68:   03053c0d        movweq  r3, #23565      @ 0x5c0d
  6c:   3c0d053e        cfstr32cc       mvfx0, [sp], {62}       @ 0x3e
  70:   02000505        andeq   r0, r0, #20971520       @ 0x1400000
  74:   00400104        subeq   r0, r0, r4, lsl #2
  78:   3f010402        svccc   0x00010402
  7c:   01040200        mrseq   r0, R12_usr
  80:   0402003e        streq   r0, [r2], #-62  @ 0xffffffc2
  84:   02003f01        andeq   r3, r0, #1, 30
  88:   78030104        stmdavc r3, {r2, r8}
  8c:   0008023c        andeq   r0, r8, ip, lsr r2
  90:   Address 0x90 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:   46432f2e        strbmi  r2, [r3], -lr, lsr #30
   4:   73656c69        cmnvc   r5, #26880      @ 0x6900
   8:   69616d2f        stmdbvs r1!, {r0, r1, r2, r3, r5, r8, sl, fp, sp, lr}^
   c:   00632e6e        rsbeq   r2, r3, lr, ror #28
  10:   6d6f682f        stclvs  8, cr6, [pc, #-188]!    @ ffffff5c <main+0xffffff5c>
  14:   756c2f65        strbvc  r2, [ip, #-3941]!       @ 0xfffff09b
  18:   76736163        ldrbtvc r6, [r3], -r3, ror #2
  1c:   616d6469        cmnvs   sp, r9, ror #8
  20:   6f442f72        svcvs   0x00442f72
  24:   656d7563        strbvs  r7, [sp, #-1379]!       @ 0xfffffa9d
  28:   2f73746e        svccs   0x0073746e
  2c:   65626d45        strbvs  r6, [r2, #-3397]!       @ 0xfffff2bb
  30:   6f646962        svcvs   0x00646962
  34:   50542f73        subspl  r2, r4, r3, ror pc
  38:   31552f73        cmpcc   r5, r3, ror pc
  3c:   43202d20                        @ <UNDEFINED> instruction: 0x43202d20
  40:   69706d6f        ldmdbvs r0!, {r0, r1, r2, r3, r5, r6, r8, sl, fp, sp, lr}^
  44:   6963616c        stmdbvs r3!, {r2, r3, r5, r6, r8, sp, lr}^
  48:   43206e6f                        @ <UNDEFINED> instruction: 0x43206e6f
  4c:   617a7572        cmnvs   sl, r2, ror r5
  50:   47006164        strmi   r6, [r0, -r4, ror #2]
  54:   4320554e                        @ <UNDEFINED> instruction: 0x4320554e
  58:   31203731                        @ <UNDEFINED> instruction: 0x31203731
  5c:   2e322e32        mrccs   14, 1, r2, cr2, cr2, {1}
  60:   6d2d2030        stcvs   0, cr2, [sp, #-192]!    @ 0xffffff40
  64:   3d757063        ldclcc  0, cr7, [r5, #-396]!    @ 0xfffffe74
  68:   74726f63        ldrbtvc r6, [r2], #-3939        @ 0xfffff09d
  6c:   6d2d7865        stcvs   8, cr7, [sp, #-404]!    @ 0xfffffe6c
  70:   6d2d2033        stcvs   0, cr2, [sp, #-204]!    @ 0xffffff34
  74:   6d756874        ldclvs  8, cr6, [r5, #-464]!    @ 0xfffffe30
  78:   6d2d2062        stcvs   0, cr2, [sp, #-392]!    @ 0xfffffe78
  7c:   616f6c66        cmnvs   pc, r6, ror #24
  80:   62612d74        rsbvs   r2, r1, #116, 26        @ 0x1d00
  84:   6f733d69        svcvs   0x00733d69
  88:   2d207466        cfstrscs        mvf7, [r0, #-408]!      @ 0xfffffe68
  8c:   6372616d        cmnvs   r2, #1073741851 @ 0x4000001b
  90:   72613d68        rsbvc   r3, r1, #104, 26        @ 0x1a00
  94:   2d37766d        ldccs   6, cr7, [r7, #-436]!    @ 0xfffffe4c
  98:   672d206d        strvs   r2, [sp, -sp, rrx]!
  9c:   666f7300        strbtvs r7, [pc], -r0, lsl #6
  a0:   72617774        rsbvc   r7, r1, #116, 14        @ 0x1d00000
  a4:   6c654465        cfstrdvs        mvd4, [r5], #-404       @ 0xfffffe6c
  a8:   6d007961        vstrvs.16       s14, [r0, #-194]        @ 0xffffff3e    @ <UNPREDICTABLE>
  ac:   006e6961        rsbeq   r6, lr, r1, ror #18
  b0:   67617061        strbvs  r7, [r1, -r1, rrx]!
  b4:   654c7261        strbvs  r7, [ip, #-609] @ 0xfffffd9f
  b8:   Address 0xb8 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:   43434700        movtmi  r4, #14080      @ 0x3700
   4:   4628203a                        @ <UNDEFINED> instruction: 0x4628203a
   8:   726f6465        rsbvc   r6, pc, #1694498816     @ 0x65000000
   c:   32312061        eorscc  r2, r1, #97     @ 0x61
  10:   302e322e        eorcc   r3, lr, lr, lsr #4
  14:   662e312d        strtvs  r3, [lr], -sp, lsr #2
  18:   29373363        ldmdbcs r7!, {r0, r1, r5, r6, r8, r9, ip, sp}
  1c:   2e323120        rsfcssp f3, f2, f0
  20:   00302e32        eorseq  r2, r0, r2, lsr lr

Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:   0000000c        andeq   r0, r0, ip
   4:   ffffffff                        @ <UNDEFINED> instruction: 0xffffffff
   8:   7c020001        stcvc   0, cr0, [r2], {1}
   c:   000d0c0e        andeq   r0, sp, lr, lsl #24
  10:   00000018        andeq   r0, r0, r8, lsl r0
        ...
  1c:   00000050        andeq   r0, r0, r0, asr r0
  20:   87080e41        strhi   r0, [r8, -r1, asr #28]
  24:   41018e02        tstmi   r1, r2, lsl #28
  28:   0000070d        andeq   r0, r0, sp, lsl #14

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:   00002c41        andeq   r2, r0, r1, asr #24
   4:   61656100        cmnvs   r5, r0, lsl #2
   8:   01006962        tsteq   r0, r2, ror #18
   c:   00000022        andeq   r0, r0, r2, lsr #32
  10:   4d2d3705        stcmi   7, cr3, [sp, #-20]!     @ 0xffffffec
  14:   070a0600        streq   r0, [sl, -r0, lsl #12]
  18:   1202094d        andne   r0, r2, #1261568        @ 0x134000
  1c:   15011404        strne   r1, [r1, #-1028]        @ 0xfffffbfc
  20:   18031701        stmdane r3, {r0, r8, r9, sl, ip}
  24:   1a011901        bne     46430 <main+0x46430>
  28:   22061e01        andcs   r1, r6, #1, 28
  2c:   Address 0x2c is out of bounds.
 ```