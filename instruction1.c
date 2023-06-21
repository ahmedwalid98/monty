#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *op;
	int num;

	if (element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	if (op == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = _strtol(op, line_number);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
 * _pall - prints all values on the stack, starting from top
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	UNUSED(line_number);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}
/**
 * _pint - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
