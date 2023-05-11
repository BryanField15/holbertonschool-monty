#include "monty.h"

/**
* parse_line - tokenises and passes opcodes and arguments to check_op_func
* @line_buf: line to tokenise
* @stack: the stack
* @current_line_no: current line number
* Return: void
*/

void parse_line(char *line_buf, stack_t **stack, unsigned int current_line_no)
{
	char *line_tokens[2];

	line_tokens[0] = strtok(line_buf, " \n\t");
	if (line_tokens[0] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", current_line_no);
		exit(EXIT_FAILURE);
	}
	line_tokens[1] = strtok(NULL, " \n\t");
	if (line_tokens[1] != NULL)
	{
		if (is_num(line_tokens[1], current_line_no) == 1)
		{
			g_push_arg = atoi(line_tokens[1]);
		}
	}
	check_op_func(stack, line_tokens[0], current_line_no);
}

/**
 * main - entry point for monty interpreter
 * @ac: number of command line arguments
 * @av: monty file with opcodes
 *
 * Return: void
 */
int main(int ac, char **av)
{
	stack_t *stack;
	FILE *fp;
	char *line_buf = NULL;
	ssize_t line_size = 0;
	size_t line_buf_size = 0;
	unsigned int current_line_number = 0;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_size = getline(&line_buf, &line_buf_size, fp);
	while (line_size >= 0)
	{
		current_line_number = current_line_number + 1;
		parse_line(line_buf, &stack, current_line_number);
		free(line_buf);
		line_buf = NULL;
		line_size = getline(&line_buf, &line_buf_size, fp);
	}
	free(line_buf);
	free_stack(stack);
	fclose(fp);
	return (0);
}
