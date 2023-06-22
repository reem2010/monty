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
		fprintf(stderr, "L%d: can't pint, stack empty", l);
		fclose(fp), exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
