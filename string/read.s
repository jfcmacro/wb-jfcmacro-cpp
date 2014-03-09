	.file	"read.C"
	.version	"01.01"
gcc2_compiled.:
		.section	.rodata
.LC0:
	.string	"Please enter you name\n"
.LC1:
	.string	"!\n"
.LC2:
	.string	"Hello, "
.globl __rethrow
.text
	.align 4
.globl main
	.type	 main,@function
main:
.LFB1:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	subl	$24, %esp
.LCFI2:
	subl	$12, %esp
	leal	-24(%ebp), %eax
	pushl	%eax
.LCFI3:
	call	__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
.LEHB3:
	subl	$8, %esp
	pushl	$.LC0
	pushl	$cout
	call	__ls__7ostreamPCc
	addl	$16, %esp
	subl	$4, %esp
	pushl	$10
	leal	-24(%ebp), %eax
	pushl	%eax
	pushl	$cin
	call	getline__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7istreamRt12basic_string3ZX01ZX11ZX21X01_R7istream
	addl	$16, %esp
	subl	$8, %esp
	pushl	$.LC1
	subl	$12, %esp
	leal	-24(%ebp), %eax
	pushl	%eax
	subl	$12, %esp
	pushl	$.LC2
	pushl	$cout
.LCFI4:
	call	__ls__7ostreamPCc
	addl	$20, %esp
	movl	%eax, %eax
	pushl	%eax
	call	__ls__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7ostreamRCt12basic_string3ZX01ZX11ZX21_R7ostream
	addl	$20, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI5:
	call	__ls__7ostreamPCc
	addl	$16, %esp
	subl	$12, %esp
	pushl	$0
	call	exit
	.p2align 2
.L3:
.LEHE3:
.LEHB5:
	subl	$8, %esp
	pushl	$2
	leal	-24(%ebp), %eax
	pushl	%eax
	call	_._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LRTH3
	call	__rethrow
	.p2align 2
.L5:
.LEHE5:
.LCFI6:
	call	terminate__Fv
.LFE1:
.Lfe1:
	.size	 main,.Lfe1-main
	.section	.gnu.linkonce.t.__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB2:
	pushl	%ebp
.LCFI7:
	movl	%esp, %ebp
.LCFI8:
	pushl	%ebx
.LCFI9:
	subl	$4, %esp
.LCFI10:
	movl	8(%ebp), %ebx
	subl	$12, %esp
	pushl	$_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.nilRep
.LCFI11:
	call	grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	movl	%eax, (%ebx)
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE2:
.Lfe2:
	.size	 __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe2-__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.section	.gnu.linkonce.t._._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	_._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 _._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
_._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB3:
	pushl	%ebp
.LCFI12:
	movl	%esp, %ebp
.LCFI13:
	pushl	%ebx
.LCFI14:
	subl	$4, %esp
.LCFI15:
	movl	12(%ebp), %ebx
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI16:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$4, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI17:
	call	release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	movl	%ebx, %eax
	andl	$1, %eax
	testb	%al, %al
	je	.L12
	subl	$12, %esp
	pushl	8(%ebp)
	call	__builtin_delete
	addl	$16, %esp
.L12:
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE3:
.Lfe3:
	.size	 _._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe3-_._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.weak	_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.npos
	.section	.gnu.linkonce.r._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.npos,"a",@progbits
	.align 4
	.type	 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.npos,@object
	.size	 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.npos,4
_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.npos:
	.long	-1
	.section	.gnu.linkonce.t.getline__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7istreamRt12basic_string3ZX01ZX11ZX21X01_R7istream,"ax",@progbits
	.align 4
	.weak	getline__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7istreamRt12basic_string3ZX01ZX11ZX21X01_R7istream
	.type	 getline__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7istreamRt12basic_string3ZX01ZX11ZX21X01_R7istream,@function
getline__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7istreamRt12basic_string3ZX01ZX11ZX21X01_R7istream:
.LFB4:
	pushl	%ebp
.LCFI18:
	movl	%esp, %ebp
.LCFI19:
	subl	$24, %esp
.LCFI20:
	movl	16(%ebp), %eax
	movb	%al, -1(%ebp)
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI21:
	call	ipfx1__7istream
	addl	$16, %esp
	movl	%eax, %eax
	testl	%eax, %eax
	je	.L14
	movl	$0, -8(%ebp)
	subl	$12, %esp
	movl	8(%ebp), %eax
	pushl	(%eax)
	call	rdbuf__C3ios
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -12(%ebp)
	subl	$8, %esp
	pushl	$0
	pushl	12(%ebp)
	call	resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	.p2align 2
.L17:
	subl	$12, %esp
	pushl	-12(%ebp)
	call	sbumpc__9streambuf
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -16(%ebp)
	cmpl	$-1, -16(%ebp)
	jne	.L18
	subl	$8, %esp
	cmpl	$0, -8(%ebp)
	jne	.L19
	movl	$3, -20(%ebp)
	jmp	.L20
	.p2align 2
.L19:
	movl	$1, -20(%ebp)
.L20:
	pushl	-20(%ebp)
	movl	8(%ebp), %eax
	pushl	(%eax)
	call	setstate__3iosi
	addl	$16, %esp
	jmp	.L14
	.p2align 2
.L18:
	leal	-8(%ebp), %eax
	incl	(%eax)
	movsbl	-1(%ebp),%eax
	cmpl	%eax, -16(%ebp)
	jne	.L21
	jmp	.L14
	.p2align 2
.L21:
	subl	$8, %esp
	movsbl	-16(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	call	__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c
	addl	$16, %esp
	subl	$12, %esp
	pushl	12(%ebp)
	call	length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	cmpl	$-2, %eax
	jne	.L17
	subl	$8, %esp
	pushl	$2
	movl	8(%ebp), %eax
	pushl	(%eax)
	call	setstate__3iosi
	addl	$16, %esp
.L14:
	subl	$12, %esp
	pushl	8(%ebp)
	call	isfx__7istream
	addl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, %eax
	leave
	ret
.LFE4:
.Lfe4:
	.size	 getline__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7istreamRt12basic_string3ZX01ZX11ZX21X01_R7istream,.Lfe4-getline__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7istreamRt12basic_string3ZX01ZX11ZX21X01_R7istream
	.section	.gnu.linkonce.t.__ls__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7ostreamRCt12basic_string3ZX01ZX11ZX21_R7ostream,"ax",@progbits
	.align 4
	.weak	__ls__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7ostreamRCt12basic_string3ZX01ZX11ZX21_R7ostream
	.type	 __ls__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7ostreamRCt12basic_string3ZX01ZX11ZX21_R7ostream,@function
__ls__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7ostreamRCt12basic_string3ZX01ZX11ZX21_R7ostream:
.LFB5:
	pushl	%ebp
.LCFI22:
	movl	%esp, %ebp
.LCFI23:
	subl	$8, %esp
.LCFI24:
	subl	$4, %esp
	subl	$8, %esp
	pushl	12(%ebp)
.LCFI25:
	call	length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$12, %esp
	movl	%eax, %eax
	pushl	%eax
	subl	$4, %esp
	pushl	12(%ebp)
.LCFI26:
	call	data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$8, %esp
	movl	%eax, %eax
	pushl	%eax
	pushl	8(%ebp)
.LCFI27:
	call	write__7ostreamPCci
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	leave
	ret
.LFE5:
.Lfe5:
	.size	 __ls__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7ostreamRCt12basic_string3ZX01ZX11ZX21_R7ostream,.Lfe5-__ls__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_R7ostreamRCt12basic_string3ZX01ZX11ZX21_R7ostream
	.weak	_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.nilRep
	.section	.gnu.linkonce.d._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.nilRep,"aw",@progbits
	.align 4
	.type	 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.nilRep,@object
	.size	 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.nilRep,16
_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0.nilRep:
	.long	0
	.long	0
	.long	1
.byte	0
	.zero	3
	.section	.gnu.linkonce.t.grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,"ax",@progbits
	.align 4
	.weak	grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.type	 grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,@function
grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep:
.LFB6:
	pushl	%ebp
.LCFI28:
	movl	%esp, %ebp
.LCFI29:
	subl	$8, %esp
.LCFI30:
	movl	8(%ebp), %eax
	cmpb	$0, 12(%eax)
	je	.L27
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI31:
	call	clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	jmp	.L26
	.p2align 2
.L27:
	movl	8(%ebp), %eax
	incl	8(%eax)
	subl	$12, %esp
	pushl	8(%ebp)
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
.L26:
	leave
	ret
.LFE6:
.Lfe6:
	.size	 grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,.Lfe6-grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.section	.gnu.linkonce.t.rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB7:
	pushl	%ebp
.LCFI32:
	movl	%esp, %ebp
.LCFI33:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	subl	$16, %eax
	movl	%eax, %eax
	popl	%ebp
	ret
.LFE7:
.Lfe7:
	.size	 rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe7-rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.section	.gnu.linkonce.t.release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,"ax",@progbits
	.align 4
	.weak	release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.type	 release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,@function
release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep:
.LFB8:
	pushl	%ebp
.LCFI34:
	movl	%esp, %ebp
.LCFI35:
	subl	$8, %esp
.LCFI36:
	movl	8(%ebp), %eax
	decl	8(%eax)
	movl	8(%ebp), %eax
	cmpl	$0, 8(%eax)
	jne	.L33
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI37:
	call	__dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv
	addl	$16, %esp
.L33:
	leave
	ret
.LFE8:
.Lfe8:
	.size	 release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,.Lfe8-release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.section	.gnu.linkonce.t.resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui,"ax",@progbits
	.align 4
	.weak	resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
	.type	 resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui,@function
resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui:
.LFB9:
	pushl	%ebp
.LCFI38:
	movl	%esp, %ebp
.LCFI39:
	pushl	%esi
.LCFI40:
	pushl	%ebx
.LCFI41:
	movl	8(%ebp), %esi
	movl	12(%ebp), %ebx
	subl	$4, %esp
	subl	$12, %esp
.LCFI42:
	call	eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$12, %esp
	movb	%al, %al
	movsbl	%al,%eax
	pushl	%eax
	pushl	%ebx
	pushl	%esi
.LCFI43:
	call	resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
	addl	$16, %esp
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
.LFE9:
.Lfe9:
	.size	 resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui,.Lfe9-resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
	.section	.gnu.linkonce.t.__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c,"ax",@progbits
	.align 4
	.weak	__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c
	.type	 __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c,@function
__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c:
.LFB10:
	pushl	%ebp
.LCFI44:
	movl	%esp, %ebp
.LCFI45:
	subl	$8, %esp
.LCFI46:
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movb	%al, %al
	subl	$4, %esp
	movsbl	%al,%eax
	pushl	%eax
	pushl	$1
	pushl	%edx
.LCFI47:
	call	append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	leave
	ret
.LFE10:
.Lfe10:
	.size	 __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c,.Lfe10-__apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c
	.section	.gnu.linkonce.t.length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB11:
	pushl	%ebp
.LCFI48:
	movl	%esp, %ebp
.LCFI49:
	subl	$8, %esp
.LCFI50:
	movl	8(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
.LCFI51:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	movl	(%eax), %eax
	movl	%eax, %eax
	leave
	ret
.LFE11:
.Lfe11:
	.size	 length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe11-length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.section	.gnu.linkonce.t.data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB12:
	pushl	%ebp
.LCFI52:
	movl	%esp, %ebp
.LCFI53:
	subl	$8, %esp
.LCFI54:
	movl	8(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
.LCFI55:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$4, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI56:
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	leave
	ret
.LFE12:
.Lfe12:
	.size	 data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe12-data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.section	.gnu.linkonce.t.clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,"ax",@progbits
	.align 4
	.weak	clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.type	 clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,@function
clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep:
.LFB13:
	pushl	%ebp
.LCFI57:
	movl	%esp, %ebp
.LCFI58:
	pushl	%ebx
.LCFI59:
	subl	$4, %esp
.LCFI60:
	movl	8(%ebp), %ebx
	subl	$12, %esp
	pushl	(%ebx)
.LCFI61:
	call	create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -8(%ebp)
	pushl	(%ebx)
	subl	$8, %esp
	pushl	%ebx
.LCFI62:
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$12, %esp
	movl	%eax, %eax
	pushl	%eax
	pushl	$0
	pushl	-8(%ebp)
.LCFI63:
	call	copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	addl	$16, %esp
	movl	-8(%ebp), %edx
	movl	(%ebx), %eax
	movl	%eax, (%edx)
	subl	$12, %esp
	pushl	-8(%ebp)
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE13:
.Lfe13:
	.size	 clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,.Lfe13-clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.section	.gnu.linkonce.t.data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,"ax",@progbits
	.align 4
	.weak	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.type	 data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,@function
data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep:
.LFB14:
	pushl	%ebp
.LCFI64:
	movl	%esp, %ebp
.LCFI65:
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, %eax
	popl	%ebp
	ret
.LFE14:
.Lfe14:
	.size	 data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,.Lfe14-data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.section	.gnu.linkonce.t.__dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv,"ax",@progbits
	.align 4
	.weak	__dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv
	.type	 __dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv,@function
__dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv:
.LFB15:
	pushl	%ebp
.LCFI66:
	movl	%esp, %ebp
.LCFI67:
	subl	$8, %esp
.LCFI68:
	movl	8(%ebp), %edx
	subl	$8, %esp
	movl	4(%edx), %eax
	addl	$16, %eax
	pushl	%eax
	pushl	%edx
.LCFI69:
	call	deallocate__t24__default_alloc_template2b1i0PvUi
	addl	$16, %esp
	leave
	ret
.LFE15:
.Lfe15:
	.size	 __dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv,.Lfe15-__dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv
	.section	.gnu.linkonce.t.eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB16:
	pushl	%ebp
.LCFI70:
	movl	%esp, %ebp
.LCFI71:
	subl	$8, %esp
.LCFI72:
	call	eos__t18string_char_traits1Zc
	movb	%al, %al
	movb	%al, %al
	leave
	ret
.LFE16:
.Lfe16:
	.size	 eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe16-eos__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
		.section	.rodata
.LC3:
	.string	"n > max_size ()"
	.section	.gnu.linkonce.t.resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic,"ax",@progbits
	.align 4
	.weak	resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
	.type	 resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic,@function
resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic:
.LFB17:
	pushl	%ebp
.LCFI73:
	movl	%esp, %ebp
.LCFI74:
	subl	$8, %esp
.LCFI75:
	movl	16(%ebp), %eax
	movb	%al, -1(%ebp)
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI76:
	call	max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	cmpl	%eax, 12(%ebp)
	jbe	.L52
	subl	$12, %esp
	pushl	$.LC3
	call	__length_error__FPCc
	addl	$16, %esp
.L52:
	subl	$12, %esp
	pushl	8(%ebp)
	call	length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	cmpl	%eax, 12(%ebp)
	jbe	.L56
	subl	$4, %esp
	movsbl	-1(%ebp),%eax
	pushl	%eax
	subl	$4, %esp
	pushl	8(%ebp)
.LCFI77:
	call	length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$8, %esp
	movl	%eax, %edx
	movl	12(%ebp), %eax
	subl	%edx, %eax
	pushl	%eax
	pushl	8(%ebp)
.LCFI78:
	call	append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
	addl	$16, %esp
	jmp	.L58
	.p2align 2
.L56:
	subl	$4, %esp
	pushl	$-1
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
	addl	$16, %esp
.L58:
	leave
	ret
.LFE17:
.Lfe17:
	.size	 resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic,.Lfe17-resize__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
	.section	.gnu.linkonce.t.append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic,"ax",@progbits
	.align 4
	.weak	append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
	.type	 append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic,@function
append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic:
.LFB18:
	pushl	%ebp
.LCFI79:
	movl	%esp, %ebp
.LCFI80:
	pushl	%ebx
.LCFI81:
	subl	$4, %esp
.LCFI82:
	movl	8(%ebp), %ebx
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%al, %al
	subl	$12, %esp
	movsbl	%al,%eax
	pushl	%eax
	pushl	%edx
	pushl	$0
	subl	$4, %esp
	pushl	%ebx
.LCFI83:
	call	length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$8, %esp
	movl	%eax, %eax
	pushl	%eax
	pushl	%ebx
.LCFI84:
	call	replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
	addl	$32, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE18:
.Lfe18:
	.size	 append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic,.Lfe18-append__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
	.section	.gnu.linkonce.t.create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi,"ax",@progbits
	.align 4
	.weak	create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
	.type	 create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi,@function
create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi:
.LFB19:
	pushl	%ebp
.LCFI85:
	movl	%esp, %ebp
.LCFI86:
	subl	$8, %esp
.LCFI87:
	subl	$12, %esp
	movl	8(%ebp), %eax
	incl	%eax
	pushl	%eax
.LCFI88:
	call	frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
	addl	$16, %esp
	movl	%eax, 8(%ebp)
	subl	$8, %esp
	pushl	8(%ebp)
	pushl	$16
	call	__nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
	addl	$16, %esp
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-4(%ebp), %eax
	movl	$1, 8(%eax)
	movl	-4(%ebp), %eax
	movb	$0, 12(%eax)
	movl	-4(%ebp), %eax
	movl	%eax, %eax
	leave
	ret
.LFE19:
.Lfe19:
	.size	 create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi,.Lfe19-create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
	.section	.gnu.linkonce.t.copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi,"ax",@progbits
	.align 4
	.weak	copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	.type	 copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi,@function
copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi:
.LFB20:
	pushl	%ebp
.LCFI89:
	movl	%esp, %ebp
.LCFI90:
	subl	$8, %esp
.LCFI91:
	cmpl	$0, 20(%ebp)
	je	.L65
	subl	$4, %esp
	pushl	20(%ebp)
	pushl	16(%ebp)
	pushl	8(%ebp)
.LCFI92:
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$4, %esp
	movl	%eax, %eax
	addl	12(%ebp), %eax
	pushl	%eax
.LCFI93:
	call	copy__t18string_char_traits1ZcPcPCcUi
	addl	$16, %esp
.L65:
	leave
	ret
.LFE20:
.Lfe20:
	.size	 copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi,.Lfe20-copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	.section	.gnu.linkonce.t.deallocate__t24__default_alloc_template2b1i0PvUi,"ax",@progbits
	.align 4
	.weak	deallocate__t24__default_alloc_template2b1i0PvUi
	.type	 deallocate__t24__default_alloc_template2b1i0PvUi,@function
deallocate__t24__default_alloc_template2b1i0PvUi:
.LFB21:
	pushl	%ebp
.LCFI94:
	movl	%esp, %ebp
.LCFI95:
	subl	$24, %esp
.LCFI96:
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	cmpl	$128, 12(%ebp)
	jbe	.L67
	subl	$8, %esp
	pushl	12(%ebp)
	pushl	8(%ebp)
.LCFI97:
	call	deallocate__t23__malloc_alloc_template1i0PvUi
	addl	$16, %esp
	jmp	.L66
	.p2align 2
.L67:
	subl	$12, %esp
	pushl	12(%ebp)
	call	_S_freelist_index__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	imull	$4, %eax, %edx
	movl	$_t24__default_alloc_template2b1i0._S_free_list, %eax
	addl	%edx, %eax
	movl	%eax, -8(%ebp)
	subl	$12, %esp
	leal	-9(%ebp), %eax
	pushl	%eax
	call	__Q2t24__default_alloc_template2b1i05_Lock
	addl	$16, %esp
	movl	%eax, %eax
	movl	-4(%ebp), %edx
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-8(%ebp), %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	subl	$8, %esp
	pushl	$2
	leal	-9(%ebp), %eax
	pushl	%eax
	call	_._Q2t24__default_alloc_template2b1i05_Lock
	addl	$16, %esp
.L66:
	leave
	ret
.LFE21:
.Lfe21:
	.size	 deallocate__t24__default_alloc_template2b1i0PvUi,.Lfe21-deallocate__t24__default_alloc_template2b1i0PvUi
	.section	.gnu.linkonce.t.max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB22:
	pushl	%ebp
.LCFI98:
	movl	%esp, %ebp
.LCFI99:
	movl	8(%ebp), %eax
	movl	$-2, %eax
	popl	%ebp
	ret
.LFE22:
.Lfe22:
	.size	 max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe22-max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.section	.gnu.linkonce.t.erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi,"ax",@progbits
	.align 4
	.weak	erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
	.type	 erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi,@function
erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi:
.LFB23:
	pushl	%ebp
.LCFI100:
	movl	%esp, %ebp
.LCFI101:
	subl	$8, %esp
.LCFI102:
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	subl	$12, %esp
	pushl	$0
	pushl	$0
	pushl	%eax
	pushl	%edx
	pushl	%ecx
.LCFI103:
	call	replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
	addl	$32, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	leave
	ret
.LFE23:
.Lfe23:
	.size	 erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi,.Lfe23-erase__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
		.section	.rodata
.LC4:
	.string	"pos > len"
.LC5:
	.string	"len - n1 > max_size () - n2"
	.section	.gnu.linkonce.t.replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic,"ax",@progbits
	.align 4
	.weak	replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
	.type	 replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic,@function
replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic:
.LFB24:
	pushl	%ebp
.LCFI104:
	movl	%esp, %ebp
.LCFI105:
	pushl	%ebx
.LCFI106:
	subl	$20, %esp
.LCFI107:
	movl	24(%ebp), %eax
	movb	%al, -5(%ebp)
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI108:
	call	length__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jbe	.L78
	subl	$12, %esp
	pushl	$.LC4
	call	__out_of_range__FPCc
	addl	$16, %esp
.L78:
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	%eax, 16(%ebp)
	jbe	.L82
	movl	12(%ebp), %eax
	movl	-12(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 16(%ebp)
.L82:
	nop
	movl	16(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	%eax, %ebx
	subl	%edx, %ebx
	subl	$12, %esp
	pushl	8(%ebp)
	call	max_size__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	subl	20(%ebp), %eax
	cmpl	%eax, %ebx
	jbe	.L84
	subl	$12, %esp
	pushl	$.LC5
	call	__length_error__FPCc
	addl	$16, %esp
.L84:
	movl	16(%ebp), %edx
	movl	-12(%ebp), %eax
	subl	%edx, %eax
	addl	20(%ebp), %eax
	movl	%eax, -16(%ebp)
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	8(%ebp)
	call	check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movb	%al, %al
	testb	%al, %al
	je	.L88
	subl	$12, %esp
	pushl	-16(%ebp)
	call	create__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -20(%ebp)
	pushl	12(%ebp)
	subl	$8, %esp
	pushl	8(%ebp)
.LCFI109:
	call	data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$12, %esp
	movl	%eax, %eax
	pushl	%eax
	pushl	$0
	pushl	-20(%ebp)
.LCFI110:
	call	copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	addl	$16, %esp
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	subl	%edx, %eax
	pushl	%eax
	subl	$8, %esp
	pushl	8(%ebp)
.LCFI111:
	call	data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$12, %esp
	movl	%eax, %eax
	addl	12(%ebp), %eax
	addl	16(%ebp), %eax
	pushl	%eax
	movl	20(%ebp), %eax
	addl	12(%ebp), %eax
	pushl	%eax
	pushl	-20(%ebp)
.LCFI112:
	call	copy__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	addl	$16, %esp
	pushl	20(%ebp)
	movsbl	-5(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	-20(%ebp)
	call	set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi
	addl	$16, %esp
	subl	$8, %esp
	pushl	-20(%ebp)
	pushl	8(%ebp)
	call	repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	jmp	.L89
	.p2align 2
.L88:
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	subl	%edx, %eax
	pushl	%eax
	subl	$8, %esp
	pushl	8(%ebp)
.LCFI113:
	call	data__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$12, %esp
	movl	%eax, %eax
	addl	12(%ebp), %eax
	addl	16(%ebp), %eax
	pushl	%eax
	movl	20(%ebp), %eax
	addl	12(%ebp), %eax
	pushl	%eax
	pushl	8(%ebp)
.LCFI114:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$4, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI115:
	call	move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	addl	$16, %esp
	pushl	20(%ebp)
	movsbl	-5(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
.LCFI116:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$4, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI117:
	call	set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi
	addl	$16, %esp
.L89:
	subl	$12, %esp
	pushl	8(%ebp)
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movl	%eax, (%edx)
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE24:
.Lfe24:
	.size	 replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic,.Lfe24-replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
	.section	.gnu.linkonce.t.frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi,"ax",@progbits
	.align 4
	.weak	frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
	.type	 frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi,@function
frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi:
.LFB25:
	pushl	%ebp
.LCFI118:
	movl	%esp, %ebp
.LCFI119:
	subl	$4, %esp
.LCFI120:
	movl	$16, -4(%ebp)
	.p2align 2
.L92:
	movl	8(%ebp), %eax
	cmpl	%eax, -4(%ebp)
	jb	.L94
	jmp	.L93
	.p2align 2
.L94:
	movl	-4(%ebp), %eax
	movl	%eax, %eax
	sall	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	.L92
	.p2align 2
.L93:
	movl	-4(%ebp), %eax
	movl	%eax, %eax
	leave
	ret
.LFE25:
.Lfe25:
	.size	 frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi,.Lfe25-frob_size__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
	.section	.gnu.linkonce.t.__nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi,"ax",@progbits
	.align 4
	.weak	__nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
	.type	 __nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi,@function
__nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi:
.LFB26:
	pushl	%ebp
.LCFI121:
	movl	%esp, %ebp
.LCFI122:
	subl	$8, %esp
.LCFI123:
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	subl	$12, %esp
	leal	(%eax,%edx), %eax
	pushl	%eax
.LCFI124:
	call	allocate__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	leave
	ret
.LFE26:
.Lfe26:
	.size	 __nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi,.Lfe26-__nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
	.section	.gnu.linkonce.t.deallocate__t23__malloc_alloc_template1i0PvUi,"ax",@progbits
	.align 4
	.weak	deallocate__t23__malloc_alloc_template1i0PvUi
	.type	 deallocate__t23__malloc_alloc_template1i0PvUi,@function
deallocate__t23__malloc_alloc_template1i0PvUi:
.LFB27:
	pushl	%ebp
.LCFI125:
	movl	%esp, %ebp
.LCFI126:
	subl	$8, %esp
.LCFI127:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	subl	$12, %esp
	pushl	%eax
.LCFI128:
	call	free
	addl	$16, %esp
	leave
	ret
.LFE27:
.Lfe27:
	.size	 deallocate__t23__malloc_alloc_template1i0PvUi,.Lfe27-deallocate__t23__malloc_alloc_template1i0PvUi
	.weak	_t24__default_alloc_template2b1i0._S_free_list
	.section	.gnu.linkonce.d._t24__default_alloc_template2b1i0._S_free_list,"aw",@progbits
	.align 32
	.type	 _t24__default_alloc_template2b1i0._S_free_list,@object
	.size	 _t24__default_alloc_template2b1i0._S_free_list,64
_t24__default_alloc_template2b1i0._S_free_list:
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.section	.gnu.linkonce.t._S_freelist_index__t24__default_alloc_template2b1i0Ui,"ax",@progbits
	.align 4
	.weak	_S_freelist_index__t24__default_alloc_template2b1i0Ui
	.type	 _S_freelist_index__t24__default_alloc_template2b1i0Ui,@function
_S_freelist_index__t24__default_alloc_template2b1i0Ui:
.LFB28:
	pushl	%ebp
.LCFI129:
	movl	%esp, %ebp
.LCFI130:
	subl	$4, %esp
.LCFI131:
	movl	8(%ebp), %eax
	addl	$7, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	shrl	$3, %eax
	decl	%eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
.LFE28:
.Lfe28:
	.size	 _S_freelist_index__t24__default_alloc_template2b1i0Ui,.Lfe28-_S_freelist_index__t24__default_alloc_template2b1i0Ui
	.section	.gnu.linkonce.t.__Q2t24__default_alloc_template2b1i05_Lock,"ax",@progbits
	.align 4
	.weak	__Q2t24__default_alloc_template2b1i05_Lock
	.type	 __Q2t24__default_alloc_template2b1i05_Lock,@function
__Q2t24__default_alloc_template2b1i05_Lock:
.LFB29:
	pushl	%ebp
.LCFI132:
	movl	%esp, %ebp
.LCFI133:
	subl	$8, %esp
.LCFI134:
	movl	8(%ebp), %eax
	subl	$12, %esp
	pushl	$_t24__default_alloc_template2b1i0._S_node_allocator_lock
.LCFI135:
	call	pthread_mutex_lock
	addl	$16, %esp
	leave
	ret
.LFE29:
.Lfe29:
	.size	 __Q2t24__default_alloc_template2b1i05_Lock,.Lfe29-__Q2t24__default_alloc_template2b1i05_Lock
	.section	.gnu.linkonce.t._._Q2t24__default_alloc_template2b1i05_Lock,"ax",@progbits
	.align 4
	.weak	_._Q2t24__default_alloc_template2b1i05_Lock
	.type	 _._Q2t24__default_alloc_template2b1i05_Lock,@function
_._Q2t24__default_alloc_template2b1i05_Lock:
.LFB30:
	pushl	%ebp
.LCFI136:
	movl	%esp, %ebp
.LCFI137:
	pushl	%ebx
.LCFI138:
	subl	$4, %esp
.LCFI139:
	movl	12(%ebp), %ebx
	subl	$12, %esp
	pushl	$_t24__default_alloc_template2b1i0._S_node_allocator_lock
.LCFI140:
	call	pthread_mutex_unlock
	addl	$16, %esp
	movl	%ebx, %eax
	andl	$1, %eax
	testb	%al, %al
	je	.L109
	subl	$12, %esp
	pushl	8(%ebp)
	call	__builtin_delete
	addl	$16, %esp
.L109:
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE30:
.Lfe30:
	.size	 _._Q2t24__default_alloc_template2b1i05_Lock,.Lfe30-_._Q2t24__default_alloc_template2b1i05_Lock
	.section	.gnu.linkonce.t.check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui,"ax",@progbits
	.align 4
	.weak	check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
	.type	 check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui,@function
check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui:
.LFB31:
	pushl	%ebp
.LCFI141:
	movl	%esp, %ebp
.LCFI142:
	subl	$8, %esp
.LCFI143:
	incl	12(%ebp)
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI144:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	movb	$0, 12(%eax)
	movb	$0, -1(%ebp)
	subl	$12, %esp
	pushl	8(%ebp)
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	cmpl	$1, 8(%eax)
	ja	.L112
	subl	$12, %esp
	pushl	8(%ebp)
	call	capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	cmpl	%eax, 12(%ebp)
	ja	.L112
	subl	$8, %esp
	subl	$4, %esp
	pushl	8(%ebp)
.LCFI145:
	call	capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$8, %esp
	movl	%eax, %eax
	pushl	%eax
	pushl	12(%ebp)
.LCFI146:
	call	excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
	addl	$16, %esp
	movb	%al, %al
	testb	%al, %al
	jne	.L112
	jmp	.L111
	.p2align 2
.L112:
	movb	$1, -1(%ebp)
.L111:
	movb	-1(%ebp), %al
	leave
	ret
.LFE31:
.Lfe31:
	.size	 check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui,.Lfe31-check_realloc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
	.section	.gnu.linkonce.t.set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi,"ax",@progbits
	.align 4
	.weak	set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi
	.type	 set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi,@function
set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi:
.LFB32:
	pushl	%ebp
.LCFI147:
	movl	%esp, %ebp
.LCFI148:
	pushl	%ebx
.LCFI149:
	subl	$4, %esp
.LCFI150:
	movl	8(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	16(%ebp), %eax
	movl	20(%ebp), %edx
	movb	%al, -5(%ebp)
	subl	$4, %esp
	pushl	%edx
	leal	-5(%ebp), %eax
	pushl	%eax
	pushl	%ecx
.LCFI151:
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$4, %esp
	movl	%eax, %eax
	addl	%ebx, %eax
	pushl	%eax
.LCFI152:
	call	set__t18string_char_traits1ZcPcRCcUi
	addl	$16, %esp
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE32:
.Lfe32:
	.size	 set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi,.Lfe32-set__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUicUi
	.section	.gnu.linkonce.t.repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,"ax",@progbits
	.align 4
	.weak	repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.type	 repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,@function
repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep:
.LFB33:
	pushl	%ebp
.LCFI153:
	movl	%esp, %ebp
.LCFI154:
	pushl	%esi
.LCFI155:
	pushl	%ebx
.LCFI156:
	movl	8(%ebp), %ebx
	movl	12(%ebp), %esi
	subl	$12, %esp
	pushl	%ebx
.LCFI157:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$4, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI158:
	call	release__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	subl	$12, %esp
	pushl	%esi
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, (%ebx)
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
.LFE33:
.Lfe33:
	.size	 repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep,.Lfe33-repup__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PQ2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	.section	.gnu.linkonce.t.move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi,"ax",@progbits
	.align 4
	.weak	move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	.type	 move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi,@function
move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi:
.LFB34:
	pushl	%ebp
.LCFI159:
	movl	%esp, %ebp
.LCFI160:
	subl	$8, %esp
.LCFI161:
	cmpl	$0, 20(%ebp)
	je	.L120
	subl	$4, %esp
	pushl	20(%ebp)
	pushl	16(%ebp)
	pushl	8(%ebp)
.LCFI162:
	call	data__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
	addl	$4, %esp
	movl	%eax, %eax
	addl	12(%ebp), %eax
	pushl	%eax
.LCFI163:
	call	move__t18string_char_traits1ZcPcPCcUi
	addl	$16, %esp
.L120:
	leave
	ret
.LFE34:
.Lfe34:
	.size	 move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi,.Lfe34-move__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiPCcUi
	.section	.gnu.linkonce.t.allocate__t24__default_alloc_template2b1i0Ui,"ax",@progbits
	.align 4
	.weak	allocate__t24__default_alloc_template2b1i0Ui
	.type	 allocate__t24__default_alloc_template2b1i0Ui,@function
allocate__t24__default_alloc_template2b1i0Ui:
.LFB35:
	pushl	%ebp
.LCFI164:
	movl	%esp, %ebp
.LCFI165:
	pushl	%ebx
.LCFI166:
	subl	$20, %esp
.LCFI167:
	cmpl	$128, 8(%ebp)
	jbe	.L122
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI168:
	call	allocate__t23__malloc_alloc_template1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	jmp	.L121
	.p2align 2
.L122:
	subl	$12, %esp
	pushl	8(%ebp)
	call	_S_freelist_index__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	imull	$4, %eax, %edx
	movl	$_t24__default_alloc_template2b1i0._S_free_list, %eax
	addl	%edx, %eax
	movl	%eax, -8(%ebp)
	subl	$12, %esp
	leal	-13(%ebp), %eax
	pushl	%eax
	call	__Q2t24__default_alloc_template2b1i05_Lock
	addl	$16, %esp
	movl	%eax, %eax
.LEHB123:
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L124
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI169:
	call	_S_round_up__t24__default_alloc_template2b1i0Ui
	addl	$4, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI170:
	call	_S_refill__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %ebx
	subl	$8, %esp
	pushl	$2
	leal	-13(%ebp), %eax
	pushl	%eax
	call	_._Q2t24__default_alloc_template2b1i05_Lock
	addl	$16, %esp
	movl	%ebx, %eax
	jmp	.L121
	.p2align 2
.L124:
	movl	-8(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-12(%ebp), %ebx
	subl	$8, %esp
	pushl	$2
	leal	-13(%ebp), %eax
	pushl	%eax
	call	_._Q2t24__default_alloc_template2b1i05_Lock
	addl	$16, %esp
	movl	%ebx, %eax
	jmp	.L121
	.p2align 2
.L123:
.LEHE123:
	subl	$8, %esp
	pushl	$2
	leal	-13(%ebp), %eax
	pushl	%eax
	call	_._Q2t24__default_alloc_template2b1i05_Lock
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LRTH123
	call	__rethrow
	.p2align 2
.L121:
	movl	-4(%ebp), %ebx
	leave
	ret
.LFE35:
.Lfe35:
	.size	 allocate__t24__default_alloc_template2b1i0Ui,.Lfe35-allocate__t24__default_alloc_template2b1i0Ui
	.weak	_t24__default_alloc_template2b1i0._S_node_allocator_lock
	.section	.gnu.linkonce.d._t24__default_alloc_template2b1i0._S_node_allocator_lock,"aw",@progbits
	.align 4
	.type	 _t24__default_alloc_template2b1i0._S_node_allocator_lock,@object
	.size	 _t24__default_alloc_template2b1i0._S_node_allocator_lock,24
_t24__default_alloc_template2b1i0._S_node_allocator_lock:
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.section	.gnu.linkonce.t.capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,"ax",@progbits
	.align 4
	.weak	capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.type	 capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,@function
capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0:
.LFB36:
	pushl	%ebp
.LCFI171:
	movl	%esp, %ebp
.LCFI172:
	subl	$8, %esp
.LCFI173:
	movl	8(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
.LCFI174:
	call	rep__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	addl	$16, %esp
	movl	%eax, %eax
	movl	4(%eax), %eax
	movl	%eax, %eax
	leave
	ret
.LFE36:
.Lfe36:
	.size	 capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0,.Lfe36-capacity__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
	.section	.gnu.linkonce.t.excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi,"ax",@progbits
	.align 4
	.weak	excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
	.type	 excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi,@function
excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi:
.LFB37:
	pushl	%ebp
.LCFI175:
	movl	%esp, %ebp
.LCFI176:
	subl	$4, %esp
.LCFI177:
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	cmpl	$16, -4(%ebp)
	jae	.L133
	movl	$16, -4(%ebp)
.L133:
	imull	$2, -4(%ebp), %eax
	movl	$0, %edx
	cmpl	12(%ebp), %eax
	setb	%dl
	movb	%dl, %al
	movb	%al, %al
	leave
	ret
.LFE37:
.Lfe37:
	.size	 excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi,.Lfe37-excess_slop__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
	.section	.gnu.linkonce.t.allocate__t23__malloc_alloc_template1i0Ui,"ax",@progbits
	.align 4
	.weak	allocate__t23__malloc_alloc_template1i0Ui
	.type	 allocate__t23__malloc_alloc_template1i0Ui,@function
allocate__t23__malloc_alloc_template1i0Ui:
.LFB38:
	pushl	%ebp
.LCFI178:
	movl	%esp, %ebp
.LCFI179:
	subl	$8, %esp
.LCFI180:
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI181:
	call	malloc
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	movl	%eax, -4(%ebp)
	cmpl	$0, -4(%ebp)
	jne	.L136
	subl	$12, %esp
	pushl	8(%ebp)
	call	_S_oom_malloc__t23__malloc_alloc_template1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -4(%ebp)
.L136:
	movl	-4(%ebp), %eax
	movl	%eax, %eax
	leave
	ret
.LFE38:
.Lfe38:
	.size	 allocate__t23__malloc_alloc_template1i0Ui,.Lfe38-allocate__t23__malloc_alloc_template1i0Ui
	.section	.gnu.linkonce.t._S_round_up__t24__default_alloc_template2b1i0Ui,"ax",@progbits
	.align 4
	.weak	_S_round_up__t24__default_alloc_template2b1i0Ui
	.type	 _S_round_up__t24__default_alloc_template2b1i0Ui,@function
_S_round_up__t24__default_alloc_template2b1i0Ui:
.LFB39:
	pushl	%ebp
.LCFI182:
	movl	%esp, %ebp
.LCFI183:
	movl	8(%ebp), %eax
	addl	$7, %eax
	andl	$-8, %eax
	movl	%eax, %eax
	popl	%ebp
	ret
.LFE39:
.Lfe39:
	.size	 _S_round_up__t24__default_alloc_template2b1i0Ui,.Lfe39-_S_round_up__t24__default_alloc_template2b1i0Ui
	.section	.gnu.linkonce.t._S_refill__t24__default_alloc_template2b1i0Ui,"ax",@progbits
	.align 4
	.weak	_S_refill__t24__default_alloc_template2b1i0Ui
	.type	 _S_refill__t24__default_alloc_template2b1i0Ui,@function
_S_refill__t24__default_alloc_template2b1i0Ui:
.LFB40:
	pushl	%ebp
.LCFI184:
	movl	%esp, %ebp
.LCFI185:
	subl	$40, %esp
.LCFI186:
	movl	$20, -4(%ebp)
	subl	$8, %esp
	leal	-4(%ebp), %eax
	pushl	%eax
	pushl	8(%ebp)
.LCFI187:
	call	_S_chunk_alloc__t24__default_alloc_template2b1i0UiRi
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, -8(%ebp)
	cmpl	$1, -4(%ebp)
	jne	.L141
	movl	-8(%ebp), %eax
	movl	%eax, %eax
	jmp	.L140
	.p2align 2
.L141:
	subl	$12, %esp
	pushl	8(%ebp)
	call	_S_freelist_index__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	imull	$4, %eax, %edx
	movl	$_t24__default_alloc_template2b1i0._S_free_list, %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	-8(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, (%edx)
	movl	$1, -28(%ebp)
	.p2align 2
.L142:
	movl	-24(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %edx
	leal	-24(%ebp), %eax
	addl	%edx, (%eax)
	movl	-4(%ebp), %eax
	decl	%eax
	cmpl	-28(%ebp), %eax
	jne	.L145
	movl	-20(%ebp), %eax
	movl	$0, (%eax)
	jmp	.L143
	.p2align 2
.L145:
	movl	-20(%ebp), %edx
	movl	-24(%ebp), %eax
	movl	%eax, (%edx)
	leal	-28(%ebp), %eax
	incl	(%eax)
	jmp	.L142
	.p2align 2
.L143:
	movl	-16(%ebp), %eax
	movl	%eax, %eax
.L140:
	leave
	ret
.LFE40:
.Lfe40:
	.size	 _S_refill__t24__default_alloc_template2b1i0Ui,.Lfe40-_S_refill__t24__default_alloc_template2b1i0Ui
		.section	.rodata
.LC6:
	.string	"out of memory"
	.section	.gnu.linkonce.t._S_oom_malloc__t23__malloc_alloc_template1i0Ui,"ax",@progbits
	.align 4
	.weak	_S_oom_malloc__t23__malloc_alloc_template1i0Ui
	.type	 _S_oom_malloc__t23__malloc_alloc_template1i0Ui,@function
_S_oom_malloc__t23__malloc_alloc_template1i0Ui:
.LFB41:
	pushl	%ebp
.LCFI188:
	movl	%esp, %ebp
.LCFI189:
	subl	$8, %esp
.LCFI190:
	nop
	.p2align 2
.L149:
	movl	_t23__malloc_alloc_template1i0.__malloc_alloc_oom_handler, %eax
	movl	%eax, -4(%ebp)
	cmpl	$0, -4(%ebp)
	jne	.L152
	subl	$8, %esp
	pushl	$endl__FR7ostream
	subl	$12, %esp
	pushl	$.LC6
	pushl	$cerr
.LCFI191:
	call	__ls__7ostreamPCc
	addl	$20, %esp
	movl	%eax, %eax
	pushl	%eax
.LCFI192:
	call	__ls__7ostreamPFR7ostream_R7ostream
	addl	$16, %esp
	subl	$12, %esp
	pushl	$1
	call	exit
	.p2align 2
.L152:
	movl	-4(%ebp), %eax
.LCFI193:
	call	*%eax
	subl	$12, %esp
	pushl	8(%ebp)
.LCFI194:
	call	malloc
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	movl	%eax, -8(%ebp)
	cmpl	$0, -8(%ebp)
	je	.L149
	movl	-8(%ebp), %eax
	movl	%eax, %eax
	leave
	ret
.LFE41:
.Lfe41:
	.size	 _S_oom_malloc__t23__malloc_alloc_template1i0Ui,.Lfe41-_S_oom_malloc__t23__malloc_alloc_template1i0Ui
	.section	.gnu.linkonce.t._S_chunk_alloc__t24__default_alloc_template2b1i0UiRi,"ax",@progbits
	.align 4
	.weak	_S_chunk_alloc__t24__default_alloc_template2b1i0UiRi
	.type	 _S_chunk_alloc__t24__default_alloc_template2b1i0UiRi,@function
_S_chunk_alloc__t24__default_alloc_template2b1i0UiRi:
.LFB42:
	pushl	%ebp
.LCFI195:
	movl	%esp, %ebp
.LCFI196:
	subl	$40, %esp
.LCFI197:
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	imull	(%edx), %eax
	movl	%eax, -8(%ebp)
	movl	_t24__default_alloc_template2b1i0._S_start_free, %edx
	movl	_t24__default_alloc_template2b1i0._S_end_free, %eax
	subl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jb	.L156
	movl	_t24__default_alloc_template2b1i0._S_start_free, %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	%eax, _t24__default_alloc_template2b1i0._S_start_free
	movl	-4(%ebp), %eax
	movl	%eax, %eax
	jmp	.L155
	.p2align 2
.L156:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jb	.L158
	movl	-12(%ebp), %eax
	movl	$0, %edx
	divl	8(%ebp)
	movl	12(%ebp), %edx
	movl	%eax, (%edx)
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	imull	(%edx), %eax
	movl	%eax, -8(%ebp)
	movl	_t24__default_alloc_template2b1i0._S_start_free, %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	%eax, _t24__default_alloc_template2b1i0._S_start_free
	movl	-4(%ebp), %eax
	movl	%eax, %eax
	jmp	.L155
	.p2align 2
.L158:
	subl	$12, %esp
	movl	_t24__default_alloc_template2b1i0._S_heap_size, %eax
	shrl	$4, %eax
	pushl	%eax
.LCFI198:
	call	_S_round_up__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %edx
	movl	-8(%ebp), %eax
	movl	%eax, %eax
	sall	$1, %eax
	addl	%edx, %eax
	movl	%eax, -16(%ebp)
	cmpl	$0, -12(%ebp)
	je	.L160
	subl	$12, %esp
	pushl	-12(%ebp)
	call	_S_freelist_index__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	imull	$4, %eax, %edx
	movl	$_t24__default_alloc_template2b1i0._S_free_list, %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	_t24__default_alloc_template2b1i0._S_start_free, %edx
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-20(%ebp), %edx
	movl	_t24__default_alloc_template2b1i0._S_start_free, %eax
	movl	%eax, (%edx)
.L160:
	subl	$12, %esp
	pushl	-16(%ebp)
	call	malloc
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, _t24__default_alloc_template2b1i0._S_start_free
	cmpl	$0, _t24__default_alloc_template2b1i0._S_start_free
	jne	.L161
	movl	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	.p2align 2
.L162:
	cmpl	$128, -20(%ebp)
	jbe	.L165
	jmp	.L163
	.p2align 2
.L165:
	subl	$12, %esp
	pushl	-20(%ebp)
	call	_S_freelist_index__t24__default_alloc_template2b1i0Ui
	addl	$16, %esp
	movl	%eax, %eax
	imull	$4, %eax, %edx
	movl	$_t24__default_alloc_template2b1i0._S_free_list, %eax
	addl	%edx, %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	je	.L164
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-28(%ebp), %eax
	movl	%eax, _t24__default_alloc_template2b1i0._S_start_free
	movl	-20(%ebp), %eax
	addl	_t24__default_alloc_template2b1i0._S_start_free, %eax
	movl	%eax, _t24__default_alloc_template2b1i0._S_end_free
	subl	$8, %esp
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	_S_chunk_alloc__t24__default_alloc_template2b1i0UiRi
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
	jmp	.L155
	.p2align 2
.L164:
	leal	-20(%ebp), %eax
	addl	$8, (%eax)
	jmp	.L162
	.p2align 2
.L163:
	movl	$0, _t24__default_alloc_template2b1i0._S_end_free
	subl	$12, %esp
	pushl	-16(%ebp)
	call	allocate__t23__malloc_alloc_template1i0Ui
	addl	$16, %esp
	movl	%eax, _t24__default_alloc_template2b1i0._S_start_free
.L161:
	movl	-16(%ebp), %eax
	addl	%eax, _t24__default_alloc_template2b1i0._S_heap_size
	movl	-16(%ebp), %eax
	addl	_t24__default_alloc_template2b1i0._S_start_free, %eax
	movl	%eax, _t24__default_alloc_template2b1i0._S_end_free
	subl	$8, %esp
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	_S_chunk_alloc__t24__default_alloc_template2b1i0UiRi
	addl	$16, %esp
	movl	%eax, %eax
	movl	%eax, %eax
.L155:
	leave
	ret
.LFE42:
.Lfe42:
	.size	 _S_chunk_alloc__t24__default_alloc_template2b1i0UiRi,.Lfe42-_S_chunk_alloc__t24__default_alloc_template2b1i0UiRi
	.weak	_t23__malloc_alloc_template1i0.__malloc_alloc_oom_handler
	.section	.gnu.linkonce.d._t23__malloc_alloc_template1i0.__malloc_alloc_oom_handler,"aw",@progbits
	.align 4
	.type	 _t23__malloc_alloc_template1i0.__malloc_alloc_oom_handler,@object
	.size	 _t23__malloc_alloc_template1i0.__malloc_alloc_oom_handler,4
_t23__malloc_alloc_template1i0.__malloc_alloc_oom_handler:
	.long	0
	.weak	_t24__default_alloc_template2b1i0._S_start_free
	.section	.gnu.linkonce.d._t24__default_alloc_template2b1i0._S_start_free,"aw",@progbits
	.align 4
	.type	 _t24__default_alloc_template2b1i0._S_start_free,@object
	.size	 _t24__default_alloc_template2b1i0._S_start_free,4
_t24__default_alloc_template2b1i0._S_start_free:
	.long	0
	.weak	_t24__default_alloc_template2b1i0._S_end_free
	.section	.gnu.linkonce.d._t24__default_alloc_template2b1i0._S_end_free,"aw",@progbits
	.align 4
	.type	 _t24__default_alloc_template2b1i0._S_end_free,@object
	.size	 _t24__default_alloc_template2b1i0._S_end_free,4
_t24__default_alloc_template2b1i0._S_end_free:
	.long	0
	.weak	_t24__default_alloc_template2b1i0._S_heap_size
	.section	.gnu.linkonce.d._t24__default_alloc_template2b1i0._S_heap_size,"aw",@progbits
	.align 4
	.type	 _t24__default_alloc_template2b1i0._S_heap_size,@object
	.size	 _t24__default_alloc_template2b1i0._S_heap_size,4
_t24__default_alloc_template2b1i0._S_heap_size:
	.long	0
	.section	.gcc_except_table,"aw",@progbits
	.align 4
__EXCEPTION_TABLE__:
	.long	-2
	.value	4
	.value	1
.LRTH0:
.LRTH3:
	.long	.LEHB3
	.long	.LEHE3
	.long	.L3
	.long	0

.LRTH5:
	.long	.LEHB5
	.long	.LEHE5
	.long	.L5
	.long	0

.LRTH123:
	.long	.LEHB123
	.long	.LEHE123
	.long	.L123
	.long	0

.LRTH1:
	.long	-1


	.section	.eh_frame,"aw",@progbits
__FRAME_BEGIN__:
	.4byte	.LLCIE1
.LSCIE1:
	.4byte	0x0
	.byte	0x1
	.string	"eh"

	.4byte	__EXCEPTION_TABLE__
	.byte	0x1
	.byte	0x7c
	.byte	0x8
	.byte	0xc
	.byte	0x4
	.byte	0x4
	.byte	0x88
	.byte	0x1
	.align 4
.LECIE1:
	.set	.LLCIE1,.LECIE1-.LSCIE1
	.4byte	.LLFDE1
.LSFDE1:
	.4byte	.LSFDE1-__FRAME_BEGIN__
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.byte	0x4
	.4byte	.LCFI0-.LFB1
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI1-.LCFI0
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI3-.LCFI1
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI4-.LCFI3
	.byte	0x2e
	.byte	0x14
	.byte	0x4
	.4byte	.LCFI5-.LCFI4
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI6-.LCFI5
	.byte	0x2e
	.byte	0x0
	.align 4
.LEFDE1:
	.set	.LLFDE1,.LEFDE1-.LSFDE1
	.4byte	.LLFDE3
.LSFDE3:
	.4byte	.LSFDE3-__FRAME_BEGIN__
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.byte	0x4
	.4byte	.LCFI7-.LFB2
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI8-.LCFI7
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI9-.LCFI8
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI11-.LCFI9
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE3:
	.set	.LLFDE3,.LEFDE3-.LSFDE3
	.4byte	.LLFDE5
.LSFDE5:
	.4byte	.LSFDE5-__FRAME_BEGIN__
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.byte	0x4
	.4byte	.LCFI12-.LFB3
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI13-.LCFI12
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI14-.LCFI13
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI16-.LCFI14
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI17-.LCFI16
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE5:
	.set	.LLFDE5,.LEFDE5-.LSFDE5
	.4byte	.LLFDE7
.LSFDE7:
	.4byte	.LSFDE7-__FRAME_BEGIN__
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.byte	0x4
	.4byte	.LCFI18-.LFB4
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI19-.LCFI18
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI21-.LCFI19
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE7:
	.set	.LLFDE7,.LEFDE7-.LSFDE7
	.4byte	.LLFDE9
.LSFDE9:
	.4byte	.LSFDE9-__FRAME_BEGIN__
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.byte	0x4
	.4byte	.LCFI22-.LFB5
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI23-.LCFI22
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI25-.LCFI23
	.byte	0x2e
	.byte	0xc
	.byte	0x4
	.4byte	.LCFI26-.LCFI25
	.byte	0x2e
	.byte	0x8
	.byte	0x4
	.4byte	.LCFI27-.LCFI26
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE9:
	.set	.LLFDE9,.LEFDE9-.LSFDE9
	.4byte	.LLFDE11
.LSFDE11:
	.4byte	.LSFDE11-__FRAME_BEGIN__
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.byte	0x4
	.4byte	.LCFI28-.LFB6
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI29-.LCFI28
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI31-.LCFI29
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE11:
	.set	.LLFDE11,.LEFDE11-.LSFDE11
	.4byte	.LLFDE15
.LSFDE15:
	.4byte	.LSFDE15-__FRAME_BEGIN__
	.4byte	.LFB8
	.4byte	.LFE8-.LFB8
	.byte	0x4
	.4byte	.LCFI34-.LFB8
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI35-.LCFI34
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI37-.LCFI35
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE15:
	.set	.LLFDE15,.LEFDE15-.LSFDE15
	.4byte	.LLFDE17
.LSFDE17:
	.4byte	.LSFDE17-__FRAME_BEGIN__
	.4byte	.LFB9
	.4byte	.LFE9-.LFB9
	.byte	0x4
	.4byte	.LCFI38-.LFB9
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI39-.LCFI38
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI40-.LCFI39
	.byte	0x86
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI41-.LCFI40
	.byte	0x83
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI42-.LCFI41
	.byte	0x2e
	.byte	0xc
	.byte	0x4
	.4byte	.LCFI43-.LCFI42
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE17:
	.set	.LLFDE17,.LEFDE17-.LSFDE17
	.4byte	.LLFDE19
.LSFDE19:
	.4byte	.LSFDE19-__FRAME_BEGIN__
	.4byte	.LFB10
	.4byte	.LFE10-.LFB10
	.byte	0x4
	.4byte	.LCFI44-.LFB10
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI45-.LCFI44
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI47-.LCFI45
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE19:
	.set	.LLFDE19,.LEFDE19-.LSFDE19
	.4byte	.LLFDE23
.LSFDE23:
	.4byte	.LSFDE23-__FRAME_BEGIN__
	.4byte	.LFB12
	.4byte	.LFE12-.LFB12
	.byte	0x4
	.4byte	.LCFI52-.LFB12
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI53-.LCFI52
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI55-.LCFI53
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI56-.LCFI55
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE23:
	.set	.LLFDE23,.LEFDE23-.LSFDE23
	.4byte	.LLFDE25
.LSFDE25:
	.4byte	.LSFDE25-__FRAME_BEGIN__
	.4byte	.LFB13
	.4byte	.LFE13-.LFB13
	.byte	0x4
	.4byte	.LCFI57-.LFB13
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI58-.LCFI57
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI59-.LCFI58
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI61-.LCFI59
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI62-.LCFI61
	.byte	0x2e
	.byte	0xc
	.byte	0x4
	.4byte	.LCFI63-.LCFI62
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE25:
	.set	.LLFDE25,.LEFDE25-.LSFDE25
	.4byte	.LLFDE29
.LSFDE29:
	.4byte	.LSFDE29-__FRAME_BEGIN__
	.4byte	.LFB15
	.4byte	.LFE15-.LFB15
	.byte	0x4
	.4byte	.LCFI66-.LFB15
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI67-.LCFI66
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI69-.LCFI67
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE29:
	.set	.LLFDE29,.LEFDE29-.LSFDE29
	.4byte	.LLFDE31
.LSFDE31:
	.4byte	.LSFDE31-__FRAME_BEGIN__
	.4byte	.LFB16
	.4byte	.LFE16-.LFB16
	.byte	0x4
	.4byte	.LCFI70-.LFB16
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI71-.LCFI70
	.byte	0xd
	.byte	0x5
	.align 4
.LEFDE31:
	.set	.LLFDE31,.LEFDE31-.LSFDE31
	.4byte	.LLFDE33
.LSFDE33:
	.4byte	.LSFDE33-__FRAME_BEGIN__
	.4byte	.LFB17
	.4byte	.LFE17-.LFB17
	.byte	0x4
	.4byte	.LCFI73-.LFB17
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI74-.LCFI73
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI76-.LCFI74
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI77-.LCFI76
	.byte	0x2e
	.byte	0x8
	.byte	0x4
	.4byte	.LCFI78-.LCFI77
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE33:
	.set	.LLFDE33,.LEFDE33-.LSFDE33
	.4byte	.LLFDE35
.LSFDE35:
	.4byte	.LSFDE35-__FRAME_BEGIN__
	.4byte	.LFB18
	.4byte	.LFE18-.LFB18
	.byte	0x4
	.4byte	.LCFI79-.LFB18
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI80-.LCFI79
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI81-.LCFI80
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI83-.LCFI81
	.byte	0x2e
	.byte	0x8
	.byte	0x4
	.4byte	.LCFI84-.LCFI83
	.byte	0x2e
	.byte	0x20
	.align 4
.LEFDE35:
	.set	.LLFDE35,.LEFDE35-.LSFDE35
	.4byte	.LLFDE37
.LSFDE37:
	.4byte	.LSFDE37-__FRAME_BEGIN__
	.4byte	.LFB19
	.4byte	.LFE19-.LFB19
	.byte	0x4
	.4byte	.LCFI85-.LFB19
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI86-.LCFI85
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI88-.LCFI86
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE37:
	.set	.LLFDE37,.LEFDE37-.LSFDE37
	.4byte	.LLFDE39
.LSFDE39:
	.4byte	.LSFDE39-__FRAME_BEGIN__
	.4byte	.LFB20
	.4byte	.LFE20-.LFB20
	.byte	0x4
	.4byte	.LCFI89-.LFB20
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI90-.LCFI89
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI92-.LCFI90
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI93-.LCFI92
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE39:
	.set	.LLFDE39,.LEFDE39-.LSFDE39
	.4byte	.LLFDE41
.LSFDE41:
	.4byte	.LSFDE41-__FRAME_BEGIN__
	.4byte	.LFB21
	.4byte	.LFE21-.LFB21
	.byte	0x4
	.4byte	.LCFI94-.LFB21
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI95-.LCFI94
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI97-.LCFI95
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE41:
	.set	.LLFDE41,.LEFDE41-.LSFDE41
	.4byte	.LLFDE45
.LSFDE45:
	.4byte	.LSFDE45-__FRAME_BEGIN__
	.4byte	.LFB23
	.4byte	.LFE23-.LFB23
	.byte	0x4
	.4byte	.LCFI100-.LFB23
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI101-.LCFI100
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI103-.LCFI101
	.byte	0x2e
	.byte	0x20
	.align 4
.LEFDE45:
	.set	.LLFDE45,.LEFDE45-.LSFDE45
	.4byte	.LLFDE47
.LSFDE47:
	.4byte	.LSFDE47-__FRAME_BEGIN__
	.4byte	.LFB24
	.4byte	.LFE24-.LFB24
	.byte	0x4
	.4byte	.LCFI104-.LFB24
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI105-.LCFI104
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI106-.LCFI105
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI108-.LCFI106
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI109-.LCFI108
	.byte	0x2e
	.byte	0xc
	.byte	0x4
	.4byte	.LCFI110-.LCFI109
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI111-.LCFI110
	.byte	0x2e
	.byte	0xc
	.byte	0x4
	.4byte	.LCFI112-.LCFI111
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI113-.LCFI112
	.byte	0x2e
	.byte	0xc
	.byte	0x4
	.4byte	.LCFI114-.LCFI113
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI115-.LCFI114
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI116-.LCFI115
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI117-.LCFI116
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE47:
	.set	.LLFDE47,.LEFDE47-.LSFDE47
	.4byte	.LLFDE51
.LSFDE51:
	.4byte	.LSFDE51-__FRAME_BEGIN__
	.4byte	.LFB26
	.4byte	.LFE26-.LFB26
	.byte	0x4
	.4byte	.LCFI121-.LFB26
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI122-.LCFI121
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI124-.LCFI122
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE51:
	.set	.LLFDE51,.LEFDE51-.LSFDE51
	.4byte	.LLFDE61
.LSFDE61:
	.4byte	.LSFDE61-__FRAME_BEGIN__
	.4byte	.LFB31
	.4byte	.LFE31-.LFB31
	.byte	0x4
	.4byte	.LCFI141-.LFB31
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI142-.LCFI141
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI144-.LCFI142
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI145-.LCFI144
	.byte	0x2e
	.byte	0x8
	.byte	0x4
	.4byte	.LCFI146-.LCFI145
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE61:
	.set	.LLFDE61,.LEFDE61-.LSFDE61
	.4byte	.LLFDE63
.LSFDE63:
	.4byte	.LSFDE63-__FRAME_BEGIN__
	.4byte	.LFB32
	.4byte	.LFE32-.LFB32
	.byte	0x4
	.4byte	.LCFI147-.LFB32
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI148-.LCFI147
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI149-.LCFI148
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI151-.LCFI149
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI152-.LCFI151
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE63:
	.set	.LLFDE63,.LEFDE63-.LSFDE63
	.4byte	.LLFDE65
.LSFDE65:
	.4byte	.LSFDE65-__FRAME_BEGIN__
	.4byte	.LFB33
	.4byte	.LFE33-.LFB33
	.byte	0x4
	.4byte	.LCFI153-.LFB33
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI154-.LCFI153
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI155-.LCFI154
	.byte	0x86
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI156-.LCFI155
	.byte	0x83
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI157-.LCFI156
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI158-.LCFI157
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE65:
	.set	.LLFDE65,.LEFDE65-.LSFDE65
	.4byte	.LLFDE67
.LSFDE67:
	.4byte	.LSFDE67-__FRAME_BEGIN__
	.4byte	.LFB34
	.4byte	.LFE34-.LFB34
	.byte	0x4
	.4byte	.LCFI159-.LFB34
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI160-.LCFI159
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI162-.LCFI160
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI163-.LCFI162
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE67:
	.set	.LLFDE67,.LEFDE67-.LSFDE67
	.4byte	.LLFDE69
.LSFDE69:
	.4byte	.LSFDE69-__FRAME_BEGIN__
	.4byte	.LFB35
	.4byte	.LFE35-.LFB35
	.byte	0x4
	.4byte	.LCFI164-.LFB35
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI165-.LCFI164
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI166-.LCFI165
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.4byte	.LCFI168-.LCFI166
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI169-.LCFI168
	.byte	0x2e
	.byte	0x4
	.byte	0x4
	.4byte	.LCFI170-.LCFI169
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE69:
	.set	.LLFDE69,.LEFDE69-.LSFDE69
	.4byte	.LLFDE75
.LSFDE75:
	.4byte	.LSFDE75-__FRAME_BEGIN__
	.4byte	.LFB38
	.4byte	.LFE38-.LFB38
	.byte	0x4
	.4byte	.LCFI178-.LFB38
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI179-.LCFI178
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI181-.LCFI179
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE75:
	.set	.LLFDE75,.LEFDE75-.LSFDE75
	.4byte	.LLFDE79
.LSFDE79:
	.4byte	.LSFDE79-__FRAME_BEGIN__
	.4byte	.LFB40
	.4byte	.LFE40-.LFB40
	.byte	0x4
	.4byte	.LCFI184-.LFB40
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI185-.LCFI184
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI187-.LCFI185
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE79:
	.set	.LLFDE79,.LEFDE79-.LSFDE79
	.4byte	.LLFDE81
.LSFDE81:
	.4byte	.LSFDE81-__FRAME_BEGIN__
	.4byte	.LFB41
	.4byte	.LFE41-.LFB41
	.byte	0x4
	.4byte	.LCFI188-.LFB41
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI189-.LCFI188
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI191-.LCFI189
	.byte	0x2e
	.byte	0x14
	.byte	0x4
	.4byte	.LCFI192-.LCFI191
	.byte	0x2e
	.byte	0x10
	.byte	0x4
	.4byte	.LCFI193-.LCFI192
	.byte	0x2e
	.byte	0x0
	.byte	0x4
	.4byte	.LCFI194-.LCFI193
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE81:
	.set	.LLFDE81,.LEFDE81-.LSFDE81
	.4byte	.LLFDE83
.LSFDE83:
	.4byte	.LSFDE83-__FRAME_BEGIN__
	.4byte	.LFB42
	.4byte	.LFE42-.LFB42
	.byte	0x4
	.4byte	.LCFI195-.LFB42
	.byte	0xe
	.byte	0x8
	.byte	0x85
	.byte	0x2
	.byte	0x4
	.4byte	.LCFI196-.LCFI195
	.byte	0xd
	.byte	0x5
	.byte	0x4
	.4byte	.LCFI198-.LCFI196
	.byte	0x2e
	.byte	0x10
	.align 4
.LEFDE83:
	.set	.LLFDE83,.LEFDE83-.LSFDE83
	.ident	"GCC: (GNU) 2.96 20000731 (Red Hat Linux 7.3 2.96-110)"
