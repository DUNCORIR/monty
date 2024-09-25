#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 *
 * Function checks if there are at least two elements in the stack
 * performs the subtraction, and updates
 * the second top element with the result.
 */ 
void sub(stack_t **stack, unsigned int line_number)
{
	int top_value, second_top_value, result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Retrieve the values of the top two elements*/
	top_value = (*stack)->n; /** top element*/
	second_top_value = (*stack)->next->n; /* second top element*/

	/* perform operation*/
	result = second_top_value - top_value;

	/* update second top element with result */
	(*stack)->next->n = result;

	/* Remove top element from stack */
	pop(stack, line_number);
}
