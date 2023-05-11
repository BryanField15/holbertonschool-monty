#include "monty.h"

void _add(stack_t **stack, unsigned int line_no)
{
        if (stack == NULL)
        {
                printf("L%u: can't add, stack too short\n", line_no);
                exit (EXIT_FAILURE);
        }
        else if ((*stack)->next == NULL)
        {
                printf("L%u: can't add, stack too short\n", line_no);
                exit (EXIT_FAILURE);
        }

        (*stack)->next->n = (*stack)->next->n + (*stack)->n;
	(*stack) = (*stack)->next;
	free ((*stack)->prev);
	(*stack)->prev = NULL;
	printf("we are in the add function \n");

}
