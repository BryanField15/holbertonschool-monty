#include "monty.h"

/**
 *is_num - checks if string is number
 *@str: string to test
 *
 *Return: 1 for number, 0 not number
 */
int is_num(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (isdigit(str[i]) == 0)
		{
			return (0);
		}
		i = i + 1;
	}
	return (1);
}
