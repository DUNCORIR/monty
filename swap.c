#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	/* Check if the stack has fewer than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Swap the values of the top two elements */
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
