#include "monty.h"

/**
 * execute - Executes the given opcode by matching it with the supported
 * instructions and calling the corresponding function.
 * @opcode: The opcode to execute as a string (e.g., "push", "pall").
 * @line_number: The line number from the Monty bytecode file being executed
 * @stack: A double pointer to the top of the stack (doubly linked list).
 *
 * Description: This function loops through a list of available instructions
 * (opcodes) and compares them with the provided `opcode`. If a
 * match is found, it calls the corresponding function to execute
 * the operation on the stack. If no match is found, an error
 * message is displayed, and the program exits with a failure status.
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL} /* Sentinel value indicating the end of the array */
	};
	int i = 0;

	/* Loop through the available instructions until a match is found */
	while (instructions[i].opcode)
	{
		/* Compare the provided opcode with the current instruction */
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			/* If there's a match, call the corresponding function */
			instructions[i].f(stack, line_number);
			return;
		}
		i++;  /* Move to the next instruction */
	}
	/* If no match is found, print an error message and exit with failure */
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - Frees a doubly linked list (the stack).
 * @stack: Pointer to the head of the stack.
 *
 * Description: This function iteratively traverses the
 * stack (doubly linked list) and frees each node to prevent memory leaks.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	/* Traverse through the stack until all nodes are freed */
	while (stack != NULL)
	{
		temp = stack;  /* Store the current node */
		stack = stack->next; /* Move to the next node in the stack */
		free(temp);
	}
}
