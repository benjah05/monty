#include "monty.h"
/**
 * swap - swap the top 2 elements
 * @stack: double pointer to the head
 * @line_number: line number we're on
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = *stack;
}
