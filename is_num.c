#include "monty.h"

/**
 *is_num - checks if string is number
 *@str: string to test
 *@line_no: current line number
 *Return: 1 for number, 0 not number
 */
int is_num(char *str, unsigned int line_no)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i = i + 1;
		}

		else if (isdigit(str[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		i = i + 1;
	}
	return (1);
}
