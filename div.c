#include "monty.h"
/**
 * custom_div - subtract the top elemenet from the second
 * @stack: double pointer to the first element
 * @line_number: line muber we're on
 * Return: void
 */
void custom_div(stack_t **stack, unsigned int line_number)
{
	int quot;
	stack_t *tmp = *stack, *firstNode = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quot = (tmp->next)->n / tmp->n;
	tmp->next->n = quot;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(firstNode);
}
/**
 * mul - subtract the top elemenet from the second
 * @stack: double pointer to the first element
 * @line_number: line muber we're on
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int prod;
	stack_t *tmp = *stack, *firstNode = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	prod = (tmp->next)->n * tmp->n;
	tmp->next->n = prod;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(firstNode);
}
/**
 * mod -  subtract the top elemenet from the second
 * @stack: double pointer to the first element
 * @line_number: line muber we're on
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int rem;
	stack_t *tmp = *stack, *firstNode = *stack;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	rem = (tmp->next)->n % tmp->n;
	tmp->next->n = rem;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(firstNode);
}
