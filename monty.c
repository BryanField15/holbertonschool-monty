#include "monty.h"




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
	char *line_tokens[2];
	int func_check;
	
	stack = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
	}

	line_size = getline(&line_buf, &line_buf_size, fp);

	while (line_size >= 0)
	{
		current_line_number = current_line_number + 1;
		printf("[%u]: %s", current_line_number, line_buf);
		line_tokens[0] = strtok(line_buf, " \n\t");
		line_tokens[1] = strtok(NULL, " \n\t");
		printf("[%u][0]: %s\t[%u][1]: %s\n", current_line_number, line_tokens[0], current_line_number, line_tokens[1]);

		func_check = check_op_func(line_tokens[0], current_line_number);

		free(line_buf);
		line_buf = NULL;
		line_size = getline(&line_buf, &line_buf_size, fp);
		
	}
	free(line_buf);
	return (0);
}
