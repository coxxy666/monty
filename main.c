#include "monty.h"
stack_t *stackHead = NULL;

/**
 * main - entry point
 * @argumentCount: arguments count
 * @argumentValues: list of arguments
 * Return: always 0
 */
int main(int argumentCount, char *argumentValues[])
{
if (argumentCount != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
openFile(argumentValues[1]);
freeStackNodes();
return (0);
}

/**
 * createNode - Creates a node.
 * @value: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise, NULL.
 */
stack_t *createNode(int value)
{
stack_t *node;

node = malloc(sizeof(stack_t));
if (node == NULL)
err(4);
node->next = NULL;
node->prev = NULL;
node->n = value;
return (node);
}

/**
 * freeStackNodes - Frees nodes in the stack.
 */
void freeStackNodes(void)
{
stack_t *tmp;

if (stackHead == NULL)
return;

while (stackHead != NULL)
{
tmp = stackHead;
stackHead = stackHead->next;
free(tmp);
}
}

/**
 * addToQueue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @lnNu: Line number of the opcode.
 */
void addToQueue(stack_t **newNode, __attribute__((unused))unsigned int lnNu)
{
stack_t *tmp;

if (newNode == NULL || *newNode == NULL)
exit(EXIT_FAILURE);
if (stackHead == NULL)
{
stackHead = *newNode;
return;
}
tmp = stackHead;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *newNode;
(*newNode)->prev = tmp;
}

