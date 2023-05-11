#include "monty.h"

/**
 *
 *
 *
 *
 */

void _push(stack_t **stack, unsigned int line_number)
{

//	printf("global var in _push func: %d\n", g_push_arg);
	printf("memory address of stack head: [%p]\n", stack);

//	printf("we are in the push func\n");
	stack_t *new_node;

	if (stack == NULL)
	{
		return;
	}
	printf("line 20 flag\n");
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL)
	{
		return;
	}
	printf("new node address %p", new_node);
	printf("line 25 flag\n");
	new_node->n = g_push_arg;
	printf("line 27 flag\n");
	new_node->next = *stack;
	printf("line 29 flag\n");
	new_node->prev = NULL;
	printf("line 30 flag\n");
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	printf("line 36 flag\n");
	printf("this the is new node [%d]\n",(*stack)->n);
//	while (*stack != NULL)
//	{
	printf("From node %d\n", (*stack)->n);
	if ((*stack)->next != NULL)
	{
		printf("From node %d\n", (*stack)->next->n);
	}


//		*stack = (*stack)->next;
//	}
	printf("line 44 flag\n");
	printf("memory address of stack head end: [%p]\n", stack);

}
