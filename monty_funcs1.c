#include "monty.h"
/**
 * _mod - computes the rest of the division
 * @head: stack head
 * @counter: the counter
*/
void _mod(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
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
aux = ST->next->n % ST->n;
ST->next->n = aux;
*head = ST->next;
free(ST);
}

/**
 * _mul - multiplies the top two elements of the stack.
 * @head: head of the stack
 * @counter: line counter
*/
void _mul(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
ST = *head;
aux = ST->next->n * ST->n;
ST->next->n = aux;
*head = ST->next;
free(ST);
}

/**
 * _nop- IDK
 * @head: head of the stack
 * @counter: line counter
 */
void _nop(stack_t **head, unsigned int counter)
{
(void) counter;
(void) head;
}

/**
 * _pall - prints all of the stack
 * @head: head of the stack
 * @counter: IDK
*/
void _pall(stack_t **head, unsigned int counter)
{
stack_t *ST;
(void)counter;
ST = *head;
if (ST == NULL)
{
return;
}
while (ST)
{
printf("%d\n", ST->n);
ST = ST->next;
}
}

/**
 * _char - prints char
 * @head: head of the stack
 * @counter: IDK
*/
void _pchar(stack_t **head, unsigned int counter)
{
stack_t *ST;
ST = *head;
if (!ST)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
if (ST->n > 127 || ST->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", ST->n);
}
