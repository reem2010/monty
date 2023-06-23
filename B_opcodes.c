#include "monty.h"
/**
 * pint -  prints the value at the top of the stack
 * @stack: top element
 * @l: number of line
 */
void pint(stack_t **stack, unsigned int l)
{
	if (!(*stack))
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pint, stack empty\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * swap - swap two elements
 * @stack: top element
 * @l: number of line
 */
void swap(stack_t **stack, unsigned int l)
{
	stack_t *tmp;

	if (!(*stack) || !((*stack)->prev))
	{
		free_list(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	tmp = (*stack)->prev;
	(*stack)->prev = ((*stack)->prev)->prev;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	tmp->next = NULL;
	if ((*stack)->prev)
		((*stack)->prev)->next = *stack;
	*stack = tmp;
}
/**
 * nop - nothing
 * @stack: top element
 * @l: number of line
 */
void nop(stack_t **stack, unsigned int l)
{
	(void)(*stack);
	(void)l;
}
/**
 * pchar -  prints the char at the top of the stack
 * @stack: top element
 * @l: number of line
 */
void pchar(stack_t **stack, unsigned int l)
{
	char c;

	if (!(*stack))
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fflush(stdout);
	fprintf(stderr, "L%d: can't pchar, value out of range\n", l);
	fclose(fp), exit(EXIT_FAILURE);
}
