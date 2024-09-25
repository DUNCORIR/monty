#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 *
 * This function is an implementation of the NOP opcode,
 * which stands for "no operation". It does
 * not alter the stack or output anything.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}
