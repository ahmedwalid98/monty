#include "monty.h"
/**
 * _pint - prints from top
 * @head: Head Of The Stack
 * @counter: Line Counter
*/
void _pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

/**
 * _pop - Le Pop
 * @head: Head Of The Stack
 * @counter: Line Counter
*/
void _pop(stack_t **head, unsigned int counter)
{
stack_t *ST;
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
ST = *head;
*head = ST->next;
free(ST);
}

/**
 * _pstr - prints the string starting at the top 
 * @head: head of the stack
 * @counter: Line NUmber
*/
void _pstr(stack_t **head, unsigned int counter)
{
stack_t *ST;
(void)counter;
ST = *head;
while (ST)
{
if (ST->n > 127 || ST->n <= 0)
{
break;
}
printf("%c", ST->n);
ST = ST->next;
}
printf("\n");
}

/**
 * _push - push a node to the stack
 * @head: head of the stack
 * @counter: Line Counter
*/
void _push(stack_t **head, unsigned int counter)
{
int n, j = 0, flag = 0;
if (bus.arg)
{
if (bus.arg[0] == '-')
{
j++;
}
for (; bus.arg[j] != '\0'; j++)
{
if (bus.arg[j] > 57 || bus.arg[j] < 48)
flag = 1;
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
n = atoi(bus.arg);
if (bus.lifi == 0)
{
addnode(head, n);
}
else
{
addqueue(head, n);
}
}

/**
 * _queue - prints in queue
 * @head: head of the stack
 * @counter: line counter
*/
void _queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 1;
}
