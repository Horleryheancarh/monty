#include "main.h"

/**
 * _calloc - concatenate strings
 * @nmem: number of elements
 * @size: type of elements
 * Return: void
 */
void *_calloc(unsigned int nmem, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (nmem == 0 || size == 0)
	{
		return NULL;
	}
	p = malloc(nmem * size);
	if (p == NULL)
	{
		return NULL;
	}
	for (i = 0; i < (nmem * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return p;
}


/**
 * _realloc - change size and copy content
 * @p: malloc pointer
 * @old: old bytes
 * @new: new bytes
 * Return: void
 */
void *_realloc(void *p, unsigned int old, unsigned int new)
{
	char *p = NULL;
	unsigned int i;

	if (new == old)
		return p;
	if (p == NULL)
	{
		p = malloc(new);
		if (!p)
			return NULL;
		return p;
	}
	if (new == 0 && p != NULL)
	{
		free(p);
		return NULL;
	}
	if (new > old)
	{
		p = malloc(new);
		if (!p)
			return NULL;
		for (i = 0; i < new; i++)
			p[i] = *((char *)p + i);
		free(p);
	}
	return p;
}
