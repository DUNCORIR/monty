#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the current operation (unused).
 *
 * Description: Traverses the stack from the top to the bottom and prints
 * the values stored in each node. If the stack is empty, nothing is printed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	/* Traversing stack and printing each element's value */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
