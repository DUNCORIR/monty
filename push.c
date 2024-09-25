#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the opcode
 * appears (used for error reporting).
 *
 * Description: Adds a new element to the top of the stack. If the argument
 * is not a valid integer, it exits the program with a failure status.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg; /* Variable to store the argument (integer as string) */
	int num;

	/* Retrieve the argument to push from a global or external variable */
	arg = strtok(NULL, " \t\n"); /* Get next token which shoud be integer */

	/* Check if the argument is NULL or not a valid integer */
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Convert the string argument to an integer */
	num = atoi(arg);
	if (num == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Create a new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node */
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Adjust pointers if the stack is not empty */
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	/* Set the new node as the head of the stack */
	*stack = new_node;
}
