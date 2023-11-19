#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int print_stack(const stack_t *h);
int push_to_stack(stack_t **head, unsigned int ln, char *n);
char **strtow(char *str);
void free_args(char **s);
int get_inst_func(char **s, unsigned int ln, stack_t **stack);
void free_stack(stack_t *head);
int isInt(char *s);
int pint(stack_t **head, unsigned int ln);
int pop(stack_t **head, unsigned int ln);
int swap(stack_t **head, unsigned int ln);
int add(stack_t **head, unsigned int ln);

#endif
