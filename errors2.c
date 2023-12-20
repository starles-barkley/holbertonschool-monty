#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop_err - error for invalid pop command
 * @line: the current file line number
*/
void pop_err(unsigned int line)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}
/**
 * swap_err - error for invalid swap command
 * @line: the current file line number
*/
void swap_err(unsigned int line)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * add_err - error for invalid add command
 * @line: the current file line number
*/
void add_err(unsigned int line)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}
