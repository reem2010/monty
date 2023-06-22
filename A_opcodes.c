#include "monty.h"
/**
 * push - push element
 * @stack: top element
 * @data: argument
 * @l: line
 */
void push(stack_t **stack, char *data, int l)
{
	stack_t *new, *temp;
	size_t i = 0;
	int mul = 1;

	if (!data)
	{
		free_list(*stack), fflush(stdout);
		fprintf(stderr, "L%d: usage: push integer\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	if (data[i] == '-')
		data = strtok(data, "-"), mul = -1;
	while (i < strlen(data))
	{
		if (data[i] < 48 || data[i] > 57)
		{
			free_list(*stack), fflush(stdout);
			fprintf(stderr, "L%d: usage: push integer\n", l);
			fclose(fp), exit(EXIT_FAILURE);
		} i++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_list(*stack), fflush(stdout);
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fp), exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->n = atoi(data) * mul;
	if (!(*stack))
		*stack = new, (*stack)->next = NULL, (*stack)->prev = NULL;
	else
	{
		temp = (*stack);
		new->prev = temp;
		temp->next = new;
		(*stack) = new;
	}
}
/**
 * pall - print all elements
 * @stack: top element
 * @l: number of line
 */
void pall(stack_t **stack, unsigned int l)
{
	stack_t *temp;
	(void)l;

	if (!stack)
		return;
	temp = (*stack);
	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->prev;
	}
}
void pop(stack_t **stack, unsigned int l)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pop an empty stack\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	tmp = (*stack)->prev;
	if (tmp)
		tmp->next = NULL;
	free(*stack);
	(*stack) = tmp;
}
