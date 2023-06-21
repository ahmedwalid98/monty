#include "monty.h"

/**
 * addqueue - add node to the queue stack
 * @n: le new vl
 * @head: head of the stack
*/
void addqueue(stack_t **head, int n)
{
stack_t *new_node, *aux;
aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (aux)
{
while (aux->next)
{
aux = aux->next;
}
}
if (!aux)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
aux->next = new_node;
new_node->prev = aux;
}
}

/**
  * _rotr - rotates the stack to the bottom
  * @head: head of the stack
  * @counter: New nmber line
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *copy;
copy = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
while (copy->next)
{
copy = copy->next;
}
copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
}

/**
 * _stack - prints the top
 * @head: hjead of the tack
 * @counter: line counter
*/
void _stack(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 0;
}

/**
  * _sub - sus
  * @head: Head of the stack
  * @counter: Line Counter
 */
void _sub(stack_t **head, unsigned int counter)
{
stack_t *aux;
int sus, nodes;
aux = *head;
for (nodes = 0; aux != NULL; nodes++)
{
aux = aux->next;
}
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
aux = *head;
sus = aux->next->n - aux->n;
aux->next->n = sus;
*head = aux->next;
free(aux);
}

/**
 * _swap - adds the top two elements of the stack.
 * @head: head of the stack
 * @counter: Line counter
*/
void _swap(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_all(*head);
exit(EXIT_FAILURE);
}
ST = *head;
aux = ST->n;
ST->n = ST->next->n;
ST->next->n = aux;
}
