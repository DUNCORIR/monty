#include "monty.h"

/**
 * mod - comutes the rest of division of the second top
 * element of stack by top element of stack.
 * @stack: The double pointer to head of stack.
 * @line_number: Line number of current operation
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top_element = 0, second_top_element = 0;
	stack_t *mod;

	/* check if less than 2 elements */
	if (*stack == NULL || (*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top_element == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Access the values of the top two elements */
	top_element = (*stack)->n;
	second_top_element = (*stack)->next->n;
	
	/* perform modulus and store result in second element */
	(*stack)->next->n = second_top_element % top_element;
	/* Remove the top element from the stack */
	mod = *stack; /* Save the pointer to the current top element */
	*stack = (*stack)->next; /* Move the stack pointer to the next element */
	free(mod);
}
