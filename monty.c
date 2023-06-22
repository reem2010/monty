#include "monty.h"
/**
 * getopcode - get the opcode
 * @s: string
 * @n: line
 */
void getopcode(stack_t **top, char *s, int n)
{
	char *temp;
	int i = 0;
	instruction_t op[] = {{"pall", pall}};

	temp = strtok(s, "\n");
	if (!temp)
		return;
	temp = strtok(temp, " ");
	if (!temp)
		return;
	while (i < 1)
	{
		if (!strcmp("push", temp))
		{
			push(top, strtok(NULL, " "), n);

			return;
		}
		if (!strcmp(s, op[i].opcod))
		{
			op[i].f(top, n);
			return;
		}
		i++;
	}
	free_list(*top);
	fprintf(stderr, "L%d: unknown instruction %s\n", n, temp);
	exit(EXIT_FAILURE);
}

/**
 * main - interpreter
 * @argv: argument
 * @argc: number of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *fp;
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

	free_list(top);
	return (0);
}

