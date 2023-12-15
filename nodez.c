#include "monty.h"

/**
 * multiplyNodes - Multiplies the top two elements of the stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @lineNumber: The line number of the opcode.
 */
void multiplyNodes(stack_t **stack, unsigned int lineNumber)
{
int product;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_err(8, lineNumber, "mul");

(*stack) = (*stack)->next;
product = (*stack)->n * (*stack)->prev->n;
(*stack)->n = product;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * modulusNodes - Calculates the modulus of the top two elements of the stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @lineNumber: The line number of the opcode.
 */
void modulusNodes(stack_t **stack, unsigned int lineNumber)
{
int remainder;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_err(8, lineNumber, "mod");

if ((*stack)->n == 0)
more_err(9, lineNumber);

(*stack) = (*stack)->next;
remainder = (*stack)->n % (*stack)->prev->n;
(*stack)->n = remainder;
free((*stack)->prev);
(*stack)->prev = NULL;
}

