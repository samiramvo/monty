#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define  _POSIX_C_SOURCE 200809L
/**
 * struct stack_s - doubled linked list
 * @n: integer
 * @prev: points to the previous element
 * @next: points to the next element
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line
 * @arg: value
 * @file: pointer
 * @content: line content
 * @lifi: flag change stack
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and functions
 * @opcode: the opcode
 * @f: function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void fpush(stack_t **head, unsigned int number);
void fpall(stack_t **head, unsigned int number);
void fpint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void freestack(stack_t *head);
void fpop(stack_t **head, unsigned int counter);
void fswap(stack_t **head, unsigned int counter);
void fadd(stack_t **head, unsigned int counter);
void fnop(stack_t **head, unsigned int counter);
void fsub(stack_t **head, unsigned int counter);
void fdiv(stack_t **head, unsigned int counter);
void fmul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void fpchar(stack_t **head, unsigned int counter);
void fpstr(stack_t **head, unsigned int counter);
void frotl(stack_t **head, unsigned int counter);
void frotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void fqueue(stack_t **head, unsigned int counter);
void fstack(stack_t **head, unsigned int counter);
#endif

