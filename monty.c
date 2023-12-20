#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

/**
 * main - main body of program
 * @argc: the count of arguments passed to program
 * @argv: the list of arguments passed to program
 *
 * Return: 0 on success, 1 on error
*/

int main(int argc, char *argv[])
{
	size_t buffsize = 512;
	unsigned int data = 0, line_count = 0;
	char *buffer = malloc(buffsize * sizeof(char)), *temp = NULL, *cmd;
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");
	void (*op_func)(stack_t **, unsigned int);

	if (argc != 2)
		count_error();
	if (file == NULL)
		null_file(argv[1]);

	while (getline(&buffer, &buffsize, file) != -1)
	{
		line_count += 1;
		cmd = cmdstr(strtok(buffer, " \n"));
		if (strcmp(cmd, "empty") == 0)
			continue;
		if (strcmp(cmd, "push") == 0)
		{
			temp = strtok(0, " \n");
			if (temp == NULL)
				null_int(line_count);
			data = cmdval(temp, line_count);
			push_m(&stack, data);
			continue;
		}
		op_func = get_command(cmd, line_count);
		op_func(&stack, line_count);
	}
	free_stack(stack);
	free(buffer);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * free_stack - frees a stack if the program closes with remaining nodes
 * @head: the top of the stack
*/

void free_stack(stack_t *head)
{
		stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * cmdstr - checks if a passed string is empty
 * @str: the checked string
 * Return: the string "empty", to inform the loop to skip the current iteration
*/

char *cmdstr(char *str)
{
	if (str == NULL)
		return ("empty");
	return (str);
}

/**
 * cmdval - checks if a passed string can be converted into a valid integer
 * @str: the checked string
 * @count: the current line count, for error handling purposes
 * Return: if the checked string was a valid number, return it as an integer
 * otherwise, throw an error
*/

int cmdval(char *str, unsigned int line)
{
	int i = 0;
	int valcheck = strcmp(str, "");

	if (str == NULL || valcheck == 0)
		null_int(line);
	while (str[i] != '\0')
	{
		if (str[i] < '-' || str[i] > '9')
			null_int(line);
		i++;
	}
	return (atoi(str));
}

/**
 * nop_m - does nothing
 * @stack: a stack node, unused
 * @line: the current line number, unused
*/
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
