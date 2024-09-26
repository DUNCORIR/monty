#include "monty.h"

/**
 * div_op - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the current
 * operation in the Monty bytecode file.
 *
 * Description: The div opcode divides the second top element of the stack
 * by the top element.
 * If there are less than two elements in the stack,
 * or if the top element is zero, an error message is printed, and the
 * program exits with EXIT_FAILURE. The result of the division replaces the
 * second top element, and the top element is removed from the stack.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element, *second_top_element;
	int result;

	/* Check for at least two elements in the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);  /*Exit if not enough elements*/
	}
	/* Access the top two elements */
	top_element = *stack;
	second_top_element = top_element->next; /* Pointer to the second top element */

	/* check for zero division */
	if (top_element->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Perform the division and store the result in the second top element */
	result = second_top_element->n / top_element->n;
	second_top_element->n = result;

	/* Remove the top element */
	top_element = top_element->next; /* Update the stack pointer to the next element */
	free(*stack); /*Free the old top element*/
	*stack = top_element;  /* Update the stack pointer */
}
