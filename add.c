#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	/* Check if the stack has fewer than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Add the top element to the second top element */
	(*stack)->next->n += (*stack)->n;
	/* Store the current top element in a temporary variable */
	temp = *stack;
	/* Update the stack pointer to the next element */
	*stack = (*stack)->next;
	/* Set the previous pointer of the new top element to NULL */
	(*stack)->prev = NULL;

	/* Free the memory allocated for the original top element */
	free(temp);
}
