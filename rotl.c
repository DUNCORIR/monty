#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the head (top) of the stack.
 * @line_number: The line number in bytecode file (unused in the function).
 *
 * Description: This function moves the top element
 * of the stack to the bottom, effectively rotating all elements
 * one position towards the top.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;
	(void)line_number;

	/* If stack is empty or has only one element, there's nothing to rotate */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	/* Initialize pointers */
	first = *stack;  /* Points to the current top element */
	last = *stack;  /* Temporary pointer to traverse to the last element */

	while (last->next != NULL)
	{
		last = last->next;
	}
	/* Adjust pointers to perform the rotation */
	*stack = first->next; /* Update the stack pointer to the new top element */
	(*stack)->prev = NULL; /* Sets new top element's previous pointer to NULL */

	first->next = NULL; /* orig top element now last, set next pointer NULL */
	first->prev = last; /* Link original top element to current last element */
	last->next = first; /* Link the last element to the original top element */
}
