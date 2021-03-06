.set FLAGS,(1<<0)|(1<<1)
.set MAGICNUM, 0x1BADB002
.set CHECKSUM, -(MAGICNUM+FLAGS)

.section .multiboot
.align 4
.long MAGICNUM
.long FLAGS
.long CHECKSUM



.section .text
.extern kernelMain
.extern callConstructors
.global _start


_start:
	mov $kernstack,%esp
	call callConstructors
	call kernelMain

_stop:
	cli
	hlt
	jmp _stop

.section .bss
.space 1*1024*1024
kernstack:
