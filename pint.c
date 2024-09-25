#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/*checks if stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the value at top of the stack */
	printf("%d\n", (*stack)->n);
}
