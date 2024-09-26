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
	stack_t *new_node, *temp;
	char *arg = strtok(NULL, " \t\n"); /* Get next token which shoud be integer */
	int num;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = convert_to_int(arg, line_number); /* Use helper function */
	new_node = malloc(sizeof(stack_t)); /* Allocate memory for the new node */
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;  /* Initialize the new node */
	new_node->prev = new_node->next = NULL;
	if (mode == 0) /* Stack mode (LIFO) */
	{
		new_node->next = *stack; /* Link the current top to the new node */
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node; /* Update stack to point to the new top */
	}
	else /* Queue mode (FIFO) */
	{
		if (!*stack)
			*stack = new_node;
		else
		{
			temp = *stack;
			while (temp->next) /* Traverse to the end of the queue */
				temp = temp->next;
			temp->next = new_node;  /* Link last node to the new node */
			new_node->prev = temp;  /* Set the previous link */
		}
	}
}
/**
 * convert_to_int - Function to convert a string to an
 * integer with error handling.
 * @arg: The string to convert.
 * @line_number: The line number in the bytecode where the error occurred.
 *
 * Return: The converted integer value.
 */
int convert_to_int(char *arg, unsigned int line_number)
{
	int num = atoi(arg);

	if (num == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (num);
}
