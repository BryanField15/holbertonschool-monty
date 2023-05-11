#include "monty.h"

void _swap(stack_t **stack, unsigned int line_no)
{
	int temp_int;

	if (stack == NULL)
        {
                printf("L%u: can't swap, stack too short\n", line_no);
                exit (EXIT_FAILURE);
        }
        else if ((*stack)->next == NULL)
        {
                printf("L%u: can't swap, stack too short\n", line_no);
                exit (EXIT_FAILURE);
        }

	temp_int = (*stack)-> n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_int;

}
