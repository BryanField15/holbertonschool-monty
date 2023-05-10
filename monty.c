#include "monty.h"

//extern int g_push_arg;


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
	int g_push_arg;
	int num_to_push;
	
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
//need to handle if line_tokens[1] == NULL here
		if (is_num(line_tokens[1]) == 1)
		{
			num_to_push = atoi(line_tokens[1]);
			g_push_arg = num_to_push;
//			printf("global var int inside loop: %d", g_push_arg);
		}
		else
		{
			g_push_arg = -1;
		}
		printf("[%u][0]: %s\t[%u][1]: %s\t global var: %d\n", current_line_number, line_tokens[0], current_line_number, line_tokens[1], g_push_arg);
		func_check = check_op_func(line_tokens[0], current_line_number);

		free(line_buf);
		line_buf = NULL;
		line_size = getline(&line_buf, &line_buf_size, fp);
		
	}
	free(line_buf);
	return (0);
}
