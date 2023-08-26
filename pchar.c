#include "monty.h"
/**
 * fpchar - prints the char
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void fpchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of the range\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
