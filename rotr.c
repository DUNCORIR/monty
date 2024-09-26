#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number (unused in this opcode)
 *
 * Description: The last element of the stack becomes the
 * top element of the stack.rotr never fails.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void) line_number;

	/* Check if stack is empty or has only one element */
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	/* Find the last element of the stack */
	while (last->next != NULL)
	{
		last = last->next;
	}
	/* Adjust pointers to rotate the stack */
	last->prev->next = NULL; /* Detach the last element */
	last->next = *stack;  /* Point last element's next to the current top */
	(*stack)->prev = last; /* Update the current top's prev pointer */
	*stack = last;  /* Update the head pointer */
	last->prev = NULL;  /* The new top element has no previous */
}
