#include "main.h"

/**
 * add_dnodeint_end - add a node at the end of a list
 * @head: first position of list
 * @n: data
 * Return: a linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *aux;

	if (head == NULL)
		return NULL;
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glov();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return *head;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return aux->next;
}

/**
 * add_dnodeint - add a note at the beginning
 * @head: first position of list
 * @n: data
 * Return: a linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return NULL;
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glov();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_dlistint - frees the list
 *
 * @head: head of the list
 * 
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
