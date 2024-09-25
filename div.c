#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element.
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
	stack_t *top = *stack;
	int divisor, dividend;

	/* Check for at least two elements in the stack */
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);  /*Exit if not enough elements*/
	}
	/* Access the top two elements of the stack */
	divisor = top->n;
	dividend = top->next->n;

	/* check for zero division */
	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE); 
	}
	/* Perform the division and store the result in the second top element */
	top->next->n = dividend / divisor; /*Store result in second top element*/
	*stack = top->next; /* move pointer to next element*/
	free(top);
}
