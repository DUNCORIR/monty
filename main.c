#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter program.
 * @argc: The argument count.
 * @argv: The argument vector containing the program name and file name.
 *
 * Return: EXIT_SUCCESS on success, or EXIT
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;

	mode = STACK_MODE; /* Initialize mode to STACK_MODE */

	/* Check for correct usage */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open bytecode file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (custom_getline(&line, &len, file) != -1)
	{
		/* Increment line number here for each read line */
		line_number++; /* Tokenize the line */
		opcode = strtok(line, " \t\n");

		/* Only increment for valid opcodes (not comments or empty lines) */
		if (opcode && opcode[0] != '#')
		{
			execute(opcode, &stack, line_number); /* Pass line number to execute */
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}

/**
 * custom_getline - Custom implementation of getline for C90 compatibility
 * @lineptr: Pointer to the buffer containing the line
 * @n: Size of the buffer
 * @stream: File stream to read from
 *
 * Return: The number of characters read, or -1 on failure
 */
int custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}

		(*lineptr)[pos++] = (char)c;
		if (c == '\n')
			break;
	}

	if (c == EOF && pos == 0)
		return (-1);

	(*lineptr)[pos] = '\0';
	return (pos);
}
