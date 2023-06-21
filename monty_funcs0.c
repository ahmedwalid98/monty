#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: the head of the stack
 * @counter: line counter
*/
void _add(stack_t **head, unsigned int counter)
{
stack_t *ST;
int len = 0, aux;
ST = *head;
while (ST)
{
ST = ST->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
ST = *head;
aux = ST->n + ST->next->n;
ST->next->n = aux;
*head = ST->next;
free(ST);
}

/**
 * addnode - add node to the stack head
 * @head: head of the stack
 * @n: invoke a new value
*/
void addnode(stack_t **head, int n)
{
stack_t *new_node, *aux;
aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
exit(0);
}
if (aux)
aux->prev = new_node;
new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}

/**
 * _div - divides the two top elements of the stack
 * @head: head of thee stack
 * @counter: count line number
*/
void _div(stack_t **head, unsigned int counter)
{
stack_t *ST;
int len = 0, aux;
ST = *head;
while (ST)
{
ST = ST->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
ST = *head;
if (ST->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
aux = ST->next->n / ST->n;
ST->next->n = aux;
*head = ST->next;
free(ST);
}

/**
* exe - exe the stack
* @stack: head linked list in stack
* @counter: counter of line
* @file: poiner to monty file
* @content: content of line
* Return: 1
*/
int exe(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
unsigned int i = 0;
char *op;
op = strtok(content, " \n\t");
if (op && op[0] == '#')
{
return (0);
}
bus.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, counter);
return (0);
}
i++;
}
if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
free_all(*stack);
exit(EXIT_FAILURE);
}
return (1);
}

/**
* free_all - frees all of the list
* @head: head of stack
*/
void free_all(stack_t *head)
{
stack_t *aux;
aux = head;
while (head)
{
aux = head->next;
free(head);
head = aux;
}
}
