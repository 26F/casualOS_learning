
@ has got to be comments right?
@ I have no idea what I'm doing...

@ interrupt handlers are functions
@ which handle interrupt 
@ requests which could be 
@ timer based or triggered by
@ perephereals

interrupt_vector_table:
	b . @ Reset
	b . 
	b . @ SWI instruction
	b .
	b .
	b .
	b .
	b .

.comm stack, 0x10000 @ Reserve 64k stack in the BSS
	_start:
		.globl _start
		ldr sp, = stack + 0x10000 @ Set up the stack
		bl main @ Jump to the main function

1:

	b 1b @ Halt

