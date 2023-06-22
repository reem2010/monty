#include "monty.h"
/**
 * free_list - free the stack
 * @top: top of the stack
 */
void free_list(stack_t *top)
{
	stack_t *temp, *temp1;

	temp = top;
	while (temp)
	{
		temp1 = temp;
		temp = temp->prev;
		free(temp1);
	}
}
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
		free_list(*stack);
		fprintf(stderr, "L%d: usage: push integer", l);
		exit(EXIT_FAILURE);
	}
	if (data[i] == '-')
		data = strtok(data, "-"), mul = -1;
	while (i < strlen(data))
	{
		if (data[i] < 48 || data[i] > 57)
		{
			free_list(*stack);
			fprintf(stderr, "L%d: usage: push integer", l);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_list(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->n = atoi(data) * mul;
	if (!(*stack))
		*stack = new;
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

		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
