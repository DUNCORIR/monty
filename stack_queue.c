#include "monty.h"
/**
 * stack_op - Set the mode to stack (LIFO).
 * @stack: Double pointer to the stack.
 * @line_number: The current line number in the bytecode file.
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Prevent unused parameter warning */
	(void)line_number; /* Prevent unused parameter warning */
	mode = STACK_MODE; /* Set mode to LIFO */
}

/**
 * queue_op - Set the mode to queue (FIFO).
 * @stack: Double pointer to the stack.
 * @line_number: The current line number in the bytecode file.
 */
/* Function to set mode to QUEUE_MODE */
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Prevent unused parameter warning */
	(void)line_number; /* Prevent unused parameter warning */
	mode = QUEUE_MODE; /* Set mode to FIFO */
}
