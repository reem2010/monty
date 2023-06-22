#include "monty.h"
/**
 * getopcode - get the opcode
 * @top: head of stack
 * @s: string
 * @n: line
 */
void getopcode(stack_t **top, char *s, int n)
{
	char *temp;
	int i = 0;
	instruction_t op[] = {{"pall", pall},
		{"pint", pint}, {"sub", sub},
		{"pop", pop}, {"add", add},
		{"swap", swap}, {"mul", mul},
		{"nop", nop}, {"div", divide}};

	temp = strtok(s, "\n");
	if (!temp)
		return;
	temp = strtok(temp, " ");
	if (!temp)
		return;
	while (i < 9)
	{
		if (!strcmp("push", temp))
		{
			push(top, strtok(NULL, " "), n);
			return;
		}
		if (!strcmp(temp, op[i].opcod))
		{
			op[i].f(top, n);
			return;
		}
		i++;
	}
	fclose(fp);
	free_list(*top), fflush(stdout);
	fprintf(stderr, "L%d: unknown instruction %s\n", n, temp);
	exit(EXIT_FAILURE);
}
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
 * main - interpreter
 * @argv: argument
 * @argc: number of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char op[1024];
	int n = 0;
	stack_t *top = NULL;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(op, 1024, fp))
	{
		n++, getopcode(&top, op, n);
	}
	fclose(fp);
	free_list(top);
	return (0);
}
