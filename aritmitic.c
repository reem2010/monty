#include "monty.h"
/**
 * add - add two numbers
 * @stack: top element
 * @l: number of line
 */
void add(stack_t **stack, unsigned int l)
{
	int sum;

	if (!(*stack) || !((*stack)->prev))
	{
		free_list(*stack), fflush(stdout);
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	sum = ((*stack)->n) + (((*stack)->prev)->n);
	pop(stack, l);
	(*stack)->n = sum;
}
/**
 * sub - sub two numbers
 * @stack: top element
 * @l: number of line
 */
void sub(stack_t **stack, unsigned int l)
{
	int sub;

	if (!(*stack) || !((*stack)->prev))
	{
		free_list(*stack), fflush(stdout);
		fprintf(stderr, "L%d: can't sub, stack too short\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	sub = (((*stack)->prev)->n) - ((*stack)->n);
	pop(stack, l);
	(*stack)->n = sub;
}
/**
 * mul - multiply two numbers
 * @stack: top element
 * @l: number of line
 */
void mul(stack_t **stack, unsigned int l)
{
	int mul;

	if (!(*stack) || !((*stack)->prev))
	{
		free_list(*stack), fflush(stdout);
		fprintf(stderr, "L%d: can't mul, stack too short\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	mul = ((*stack)->n) * (((*stack)->prev)->n);
	pop(stack, l);
	(*stack)->n = mul;
}
/**
 * divide - divide two numbers
 * @stack: top element
 * @l: number of line
 */
void divide(stack_t **stack, unsigned int l)
{
	int div;

	if (!(*stack) || !((*stack)->prev))
	{
		free_list(*stack), fflush(stdout);
		fprintf(stderr, "L%d: can't div, stack too short\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}

	if (!((*stack)->n))
	{
		free_list(*stack), fflush(stdout);
		fprintf(stderr, "L%d: division by zero\n", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	div = (((*stack)->prev)->n) / ((*stack)->n);
	pop(stack, l);
	(*stack)->n = div;
}
