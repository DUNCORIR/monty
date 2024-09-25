#include "monty.h"

/**
 * mul - Performs multiplication on two top elements of stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the current operation.
 *
 * Description: multiplies the second top element of the
 * stack with the top element of the stack.
 * result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end
 * stack is one element shorter.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *sum;  /* Pointer to temporarily hold the top element */
	int top_element, second_top_element; /* store values of top two elements */

	/* Check if the stack has fewer than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Access the top two elements */
	top_element = (*stack)->n;
	second_top_element = (*stack)->next->n;

	/* Perfom mul and store result in result in second top element */
	(*stack)->next->n = top_element * second_top_element;
	/* Remove the top element from the stack */
	sum = *stack; /* Save the pointer to the current top element */
	*stack = (*stack)->next; /* Move the stack pointer to the next element */
	free(sum);/* Free the memory allocated for the removed top element */
}
