	.file	"Precompilacion.cpp"
	.local	_ZSt8__ioinit
	.comm	_ZSt8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"Entre un valor: "
.LC1:
	.string	"El programa fallo"
	.align 32
.LC2:
	.string	"El valor que entro esta por fuera del valor m\341ximo"
	.text
	.align 2
.globl main
	.type	main, @function
main:
.LFB1515:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	subl	$8, %esp
.LCFI2:
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	subl	$8, %esp
	pushl	$.LC0
	pushl	$_ZSt4cout
.LCFI3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$16, %esp
	subl	$8, %esp
	leal	-4(%ebp), %eax
	pushl	%eax
	pushl	$_ZSt3cin
	call	_ZNSirsERi
	addl	$16, %esp
	subl	$12, %esp
	pushl	$_ZSt3cin+8
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEE4failEv
	addl	$16, %esp
	testb	%al, %al
	je	.L2
	subl	$8, %esp
	pushl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	subl	$12, %esp
	pushl	$.LC1
	pushl	$_ZSt4cerr
.LCFI4:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$20, %esp
	pushl	%eax
.LCFI5:
	call	_ZNSolsEPFRSoS_E
	addl	$16, %esp
	movl	$1, -8(%ebp)
	jmp	.L1
.L2:
	cmpl	$34000, -4(%ebp)
	jg	.L5
	cmpl	$29999, -4(%ebp)
	jle	.L5
	jmp	.L3
.L5:
	subl	$8, %esp
	pushl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	subl	$12, %esp
	pushl	$.LC2
	pushl	$_ZSt4cout
.LCFI6:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$20, %esp
	pushl	%eax
.LCFI7:
	call	_ZNSolsEPFRSoS_E
	addl	$16, %esp
.L3:
	movl	$0, -8(%ebp)
.L1:
	movl	-8(%ebp), %eax
	leave
	ret
.LFE1515:
	.size	main, .-main
	.align 2
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1523:
	pushl	%ebp
.LCFI8:
	movl	%esp, %ebp
.LCFI9:
	subl	$8, %esp
.LCFI10:
	cmpl	$65535, 12(%ebp)
	jne	.L6
	cmpl	$1, 8(%ebp)
	jne	.L6
	subl	$12, %esp
	pushl	$_ZSt8__ioinit
.LCFI11:
	call	_ZNSt8ios_base4InitC1Ev
	addl	$16, %esp
	subl	$4, %esp
	pushl	$__dso_handle
	pushl	$0
	pushl	$__tcf_0
	call	__cxa_atexit
	addl	$16, %esp
.L6:
	leave
	ret
.LFE1523:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align 2
	.type	__tcf_0, @function
__tcf_0:
.LFB1524:
	pushl	%ebp
.LCFI12:
	movl	%esp, %ebp
.LCFI13:
	subl	$8, %esp
.LCFI14:
	subl	$12, %esp
	pushl	$_ZSt8__ioinit
.LCFI15:
	call	_ZNSt8ios_base4InitD1Ev
	addl	$16, %esp
	leave
	ret
.LFE1524:
	.size	__tcf_0, .-__tcf_0
	.weak	_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE
	.section	.gnu.linkonce.r._ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE,"a",@progbits
	.align 4
	.type	_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE, @object
	.size	_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE, 4
_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE:
	.long	1
	.weak	_ZNSt15basic_streambufIwSt11char_traitsIwEE13_S_pback_sizeE
	.section	.gnu.linkonce.r._ZNSt15basic_streambufIwSt11char_traitsIwEE13_S_pback_sizeE,"a",@progbits
	.align 4
	.type	_ZNSt15basic_streambufIwSt11char_traitsIwEE13_S_pback_sizeE, @object
	.size	_ZNSt15basic_streambufIwSt11char_traitsIwEE13_S_pback_sizeE, 4
_ZNSt15basic_streambufIwSt11char_traitsIwEE13_S_pback_sizeE:
	.long	1
	.text
	.align 2
	.type	_GLOBAL__I_main, @function
_GLOBAL__I_main:
.LFB1526:
	pushl	%ebp
.LCFI16:
	movl	%esp, %ebp
.LCFI17:
	subl	$8, %esp
.LCFI18:
	subl	$8, %esp
	pushl	$65535
	pushl	$1
.LCFI19:
	call	_Z41__static_initialization_and_destruction_0ii
	addl	$16, %esp
	leave
	ret
.LFE1526:
	.size	_GLOBAL__I_main, .-_GLOBAL__I_main
	.section	.ctors,"aw",@progbits
	.align 4
	.long	_GLOBAL__I_main
	.weak	pthread_mutex_unlock
	.weak	pthread_mutex_trylock
	.weak	pthread_mutex_lock
	.weak	pthread_create
	.weak	pthread_setspecific
	.weak	pthread_getspecific
	.weak	pthread_key_delete
	.weak	pthread_key_create
	.weak	pthread_once
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zP"
	.uleb128 0x1
	.sleb128 -4
	.byte	0x8
	.uleb128 0x5
	.byte	0x0
	.long	__gxx_personality_v0
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x88
	.uleb128 0x1
	.align 4
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB1515
	.long	.LFE1515-.LFB1515
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB1515
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI3-.LCFI1
	.byte	0x2e
	.uleb128 0x10
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0x2e
	.uleb128 0x14
	.byte	0x4
	.long	.LCFI5-.LCFI4
	.byte	0x2e
	.uleb128 0x10
	.byte	0x4
	.long	.LCFI6-.LCFI5
	.byte	0x2e
	.uleb128 0x14
	.byte	0x4
	.long	.LCFI7-.LCFI6
	.byte	0x2e
	.uleb128 0x10
	.align 4
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB1523
	.long	.LFE1523-.LFB1523
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI8-.LFB1523
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI9-.LCFI8
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI11-.LCFI9
	.byte	0x2e
	.uleb128 0x10
	.align 4
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.long	.LFB1524
	.long	.LFE1524-.LFB1524
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI12-.LFB1524
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI13-.LCFI12
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI15-.LCFI13
	.byte	0x2e
	.uleb128 0x10
	.align 4
.LEFDE5:
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.long	.LFB1526
	.long	.LFE1526-.LFB1526
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI16-.LFB1526
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI17-.LCFI16
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	.LCFI19-.LCFI17
	.byte	0x2e
	.uleb128 0x10
	.align 4
.LEFDE7:
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.2 20031022 (Red Hat Linux 3.3.2-1)"
