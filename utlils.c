#include "monty.h"

/**
 * isInt - Entry point
 * @s: list
 * Description: hi
 * Return: void
 */

int isInt(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i == 0)
		{
			if (s[i] != '-' && !isdigit(s[i]))
				return (0);
		}
		else if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}

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

int get_inst_func(char **s, unsigned int ln, stack_t **stack)
{
	int output;

	output = 2;
	if (strcmp(s[0], "push") == 0)
		output = push_to_stack(stack, ln, s[1]);
	if (strcmp(s[0], "pall") == 0)
		output = print_stack(stack[0]);
	if (strcmp(s[0], "nop") == 0)
	{};
	if (strcmp(s[0], "pint") == 0)
		output = pint(stack, ln);
	if (strcmp(s[0], "pop") == 0)
		output = pop(stack, ln);
	if (strcmp(s[0], "swap") == 0)
		output = swap(stack, ln);
	if (output == 2)
	{
		fprintf(stderr, "%s%d%s%s%s", "L", ln, ": unknown instruction ", s[0], "\n");
		output = 1;
	}
	free_args(s);
	return (output);
}

/**
 * free_stack - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = NULL;

	tmp = head;
	while (tmp != NULL)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
