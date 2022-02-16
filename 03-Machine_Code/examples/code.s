	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 1
	.globl	_sum                            ; -- Begin function sum
	.p2align	2
_sum:                                   ; @sum
	.cfi_startproc
; %bb.0:
	adrp	x8, _accum@PAGE
	ldr	w9, [x8, _accum@PAGEOFF]
	add	w0, w1, w0
	add	w9, w9, w0
	str	w9, [x8, _accum@PAGEOFF]
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_accum                          ; @accum
.zerofill __DATA,__common,_accum,4,2
.subsections_via_symbols
