#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>





/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;


extern stack_t *stackHead;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/**
 * doNothing - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void doNothing(stack_t **stack, unsigned int lineNumber);

/**
 * swapNodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void swapNodes(stack_t **stack, unsigned int lineNumber);

/**
 * addNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void addNodes(stack_t **stack, unsigned int lineNumber);

/**
 * subNodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void subNodes(stack_t **stack, unsigned int lineNumber);

/**
 * divNodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void divNodes(stack_t **stack, unsigned int lineNumber);

/**
 * addToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @lnNu: Integer representing the line number of the opcode.
 */
void addToStack(stack_t **newNode, __attribute__((unused))unsigned int lnNu);

/**
 * printStack - Prints the elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void printStack(stack_t **stack, unsigned int lineNumber);

/**
 * popTop - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void popTop(stack_t **stack, unsigned int lineNumber);

/**
 * printTop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printTop(stack_t **stack, unsigned int lineNumber);

/**
 * err - Prints appropriate error messages based on their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not provide a file or provides more than one
 * (2) => The provided file is not a file that can be opened or read.
 * (3) => The provided file contains an invalid instruction.
 * (4) => The program is unable to allocate more memory.
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => The stack is empty when trying to print an integer.
 * (7) => The stack is empty when trying to pop an integer.
 * (8) => The stack is too short for the operation being performed.
 */
void err(int error_code, ...);

/**
 * more_err - Handles more errors.
 * @error_code: The error codes are the following:
 * (6) => The stack is empty when trying to print an integer.
 * (7) => The stack is empty when trying to pop an integer.
 * (8) => The stack is too short for the operation being performed.
 * (9) => Division by zero.
 */
void more_err(int error_code, ...);


/**
 * string_err - handles errors in the string.
 * @error_code: The error codes are the following:
 * (10) => The value inside a node is outside the ASCII range.
 * (11) => The stack is empty.
 */
void string_err(int error_code, ...);

/**
 * main - entry point
 * @argumentCount: arguments count
 * @argumentValues: list of arguments
 * Return: always 0
 */
int main(int argumentCount, char *argumentValues[]);

/**
 * createNode - Creates a node.
 * @value: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise, NULL.
 */
stack_t *createNode(int value);

/**
 * freeStackNodes - Frees nodes in the stack.
 */
void freeStackNodes(void);

/**
 * addToQueue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @lnNu: Line number of the opcode.
 */
void addToQueue(stack_t **newNode, __attribute__((unused))unsigned int lnNu);

/**
 * multiplyNodes - Multiplies the top two elements of the stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @lineNumber: The line number of the opcode.
 */
void multiplyNodes(stack_t **stack, unsigned int lineNumber);

/**
 * modulusNodes - Calculates the modulus of the top two elements of the stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @lineNumber: The line number of the opcode.
 */
void modulusNodes(stack_t **stack, unsigned int lineNumber);

/**
 * openFile - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void openFile(char *file_name);

/**
 * readFile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readFile(FILE *fd);

/**
 * parseLine - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseLine(char *buffer, int line_number, int format);

/**
 * findFunction - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findFunction(char *opcode, char *value, int ln, int format);

/**
 * callFunction - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void callFunction(op_func func, char *op, char *val, int ln, int format);

/**
 * printAsciiValue - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void printAsciiValue(stack_t **stack, unsigned int lnNu);

/**
 * priStr - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void priStr(stack_t **stack, __attribute__((unused))unsigned int lnNu);

/**
 * rotLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void rotLeft(stack_t **stack, __attribute__((unused))unsigned int lnNu);

/**
 * rotRig - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lnNu: Integer representing the line number of the opcode.
 */
void rotRig(stack_t **stack, __attribute__((unused))unsigned int lnNu);

void free_nodes(void);



#endif
