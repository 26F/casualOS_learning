
#define SERIAL_BASE 0x16000000
#define SERIAL_FLAG_REGISTER 0x18
#define SERIAL_BUFFER_FULL (1 << 5) // e.g 2^5 = 32


void putc(char c)
{


	// wait until the serial buffer is empty
	// volatile tells the compiler not to optimise the 
	// loop away, since we're waiting for hardware..
	while (*(volatile unsigned long*)(SERIAL_BASE + SERIAL_FLAG_REGISTER)
		                              & (SERIAL_BUFFER_FULL));


	// put our character, c, into the serial buffer
	*(volatile unsigned long*)SERIAL_BASE = c;

	// print a carriage return if this is a newline

	if (c == '\n') {

		putc('\r'); // is this an ARM specific thing?

	}

}


void puts(const char* str)
{


	while (*str) {

		putc(*str++);

	}

}



int main(void)
{

	puts("Hello, World!\n");
	return 0;

}

