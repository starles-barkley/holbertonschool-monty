#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * push_m - create a new node on the stack
 * @head: the top of the stack
 * @data: the data contained in the new node
*/
void push_m(stack_t **head, unsigned int data)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	if (*head == NULL)
	{
		free(new_node);
		*head = malloc(sizeof(stack_t));
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*head)->n = data;
	}
	else
	{
		new_node->next = *head;
		new_node->prev = NULL;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

/**
 * pall_m - print the data of all current nodes in the stack
 * @head: the top of the stack
*/

void pall_m(stack_t **head, unsigned int data __attribute__((unused)))
{
	stack_t *temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint_m - print the data of the top node of the stack
 * @head: a stack node, the top of the stack
 * @line: the current file line number, for error handling
*/
void pint_m(stack_t **head, unsigned int line)
{
	if (*head == NULL)
		pint_err(line);
	printf("%u\n", (*head)->n);
}

/**
 * pop_m - pop the top node off the stack
 * @head: the stack top
 * @line: the current file line number
*/
void pop_m(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;
	if (*head == NULL)
		pop_err(line);
	temp = *head;
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
	}
	else
	{
		*head = NULL;
	}
	free(temp);
	temp = NULL;
}

/**
 * swap_m - swap the values of the top two nodes in the stack
 * @head: the top node of the stack
 * @line: the current file line number
*/
void swap_m(stack_t **head, unsigned int line)
{
	int temp = 0;
	
	if (*head == NULL)
		swap_err(line);
	if ((*head)->next == NULL)
		swap_err(line);

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}

/**
 * add_m - adds the value held in the top node to the second node, then pops.
 * @head: the top node of the stack
 * @line: the current file line number
*/
void add_m(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;

	if (*head == NULL)
		add_err(line);
	temp = *head;
	if ((*head)->next == NULL)
		add_err(line);

	(*head)->next->n += (*head)->n;
	*head = (*head)->next;
	free(temp);
}
