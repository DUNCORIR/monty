#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the current operation.
 *
 * Description: The integer stored at the top of the stack
 * is treated as the ASCII value of the character to be printed.
 * If the value is not in the ASCII table or the stack is empty,
 * an error message is printed and the program exits.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL) /* Check if the stack is empty */
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n; /* Get the value at the top of the stack */
	/* Check if the value is in the valid ASCII range */

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Print the character corresponding to the ASCII value */
	printf("%c\n", value);
}
