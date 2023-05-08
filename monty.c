#include "main.h"

/**
 * main - entry point for monty interpreter
 * @ac: number of command line arguments
 * @av: monty file with opcodes
 *
 * Return: void
 */

void main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
}
