#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/*check if stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Store the current top element in a temp variable*/
	temp = *stack;
	/* updtae the stack pointer to next element*/
	*stack = (*stack)->next;
	/*if new top element exists, set its prev pointer to NULL */
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	/*Free the memory allocated for the original top element */

	free(temp);
}
