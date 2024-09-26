#include "monty.h"

/**
 * pstr_op - Function prints a string starting at top of the stack.
 * @stack: Double pointer to the top of stack to be modified.
 * @line_number: The line number of the current bytecode file.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack; /* Start from the top of the stack */
	(void) line_number;

	/* check for empty stack */
	if (current == NULL)
	{
		putchar('\n'); /* Print a new line */
		return;
	}
	/* iterate through the stack */
	while (current != NULL)
	{
		int value;

		value = current->n;

		/* if at 0 or invalid ASCII value, stop*/
		if (value == 0 || value < 0 || value > 127)
		{
			break; /* Exit the loop if 0 or out of ASCII range */
		}
		/* print corresponding character */
		putchar(value);
		current = current->next; /* Move to the next element in the stack */
	}
	putchar('\n');  /*print a new line at end */
}
