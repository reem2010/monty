#include "monty.h"
/**
 * getopcode - get the opcode
 * @top: head of stack
 * @s: string
 * @n: line
 */
void getopcode(stack_t **top, char *s, int n)
{
	char *temp, *temp1;
	int i = 0;
	instruction_t op[] = {{"pall", pall},
		{"pint", pint},
		{"pop", pop}};

	temp = strtok(s, "\n");
	if (!temp)
		return;
	while (temp)
	{
		temp1 = strtok(temp, ";");
		temp = strtok(NULL, "");
		temp1 = strtok(temp1, " ");
		while (i < 3)
		{

			if (!strcmp("push", temp1))
			{
				push(top, strtok(NULL, " "), n);
				break;
			}
			if (!strcmp(temp1, op[i].opcod))
			{
				op[i].f(top, n);
				break;
			}
			i++;
		}
		if (i == 3)
		{
			fclose(fp);
			free_list(*top), fflush(stdout);
			fprintf(stderr, "L%d: unknown instruction %s\n", n, temp);
			exit(EXIT_FAILURE);
		}
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
