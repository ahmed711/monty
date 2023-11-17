#include "monty.h"

/**
 * free_args - Entry point
 * @s: list
 * Description: hi
 * Return: void
 */

void free_args(char **s)
{
	int i;

	for (i = 0; s[i] != NULL; i++)
	{
		free(s[i]);
	}
	free(s);
}

/**
 * get_inst_func - Entry point
 * @s: char
 * @ln: line Number
 * @stack: stack
 * Description: 'fill the first n bytes of s with b'
 * Return: Always 0 (Success)
 */

stack_t *get_inst_func(char **s, unsigned int ln, stack_t **stack)
{
	stack_t *tmp;

	if (strcmp(s[0], "push") == 0)
	{
		if (!atoi(s[1]))
		{
			fprintf(stderr, "%s%d%s", "L<", ln, ">: usage: push integer\n");
			exit(EXIT_FAILURE);
		}
		return (push_to_stack(stack, atoi(s[1])));
	}
	if (strcmp(s[0], "pall") == 0)
	{
		print_stack(stack[0]);
		return (NULL);
	}
	if (strcmp(s[0], "nop") == 0)
		return (NULL);
	if (strcmp(s[0], "pint") == 0)
	{
		if (!stack || !stack[0])
		{
			fprintf(stderr, "%s%d%s", "L<", ln, ">: usage: pint stack empty\n");
			exit(EXIT_FAILURE);
		}
		printf("%d\n", stack[0]->n);
	}
	if (strcmp(s[0], "pop") == 0)
	{
		if (!stack || !stack[0])
		{
			fprintf(stderr, "%s%d%s", "L<", ln, ">: usage: can't pop an empty stack\n");
			exit(EXIT_FAILURE);
		}
		tmp = stack[0];
		free(stack[0]);
		stack[0] = tmp->next;
		free(stack[0]->prev);
	}
	return (NULL);
}

/**
 * free_stack - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
