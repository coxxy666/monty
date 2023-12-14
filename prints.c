#include "monty.h"

/**
 * printAsciiValue - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void printAsciiValue(stack_t **stack, unsigned int lnNu)
{
int ascii;

if (stack == NULL || *stack == NULL)
string_err(11, lnNu);

ascii = (*stack)->n;
if (ascii < 0 || ascii > 127)
string_err(10, lnNu);
printf("%c\n", ascii);
}

/**
 * priStr - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void priStr(stack_t **stack, __attribute__((unused))unsigned int lnNu)
{
int ascii;
stack_t *tmp;

if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}

tmp = *stack;
while (tmp != NULL)
{
ascii = tmp->n;
if (ascii <= 0 || ascii > 127)
break;
printf("%c", ascii);
tmp = tmp->next;
}
printf("\n");
}

/**
 * rotLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void rotLeft(stack_t **stack, __attribute__((unused))unsigned int lnNu)
{
stack_t *tmp;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;

tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *stack;
(*stack)->prev = tmp;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}

/**
 * rotRig - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void rotRig(stack_t **stack, __attribute__((unused))unsigned int lnNu)
{
stack_t *tmp;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;

tmp = *stack;

while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *stack;
tmp->prev->next = NULL;
tmp->prev = NULL;
(*stack)->prev = tmp;
(*stack) = tmp;
}

