#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @size: new size in bytes of the allocated space
 *
 * Return: pointer to the new memory block
 */
void *_realloc(void *ptr, size_t size)
{
	void *y_ptr = NULL;

	if (ptr == NULL)
	{
		y_ptr = malloc(size);
		if (y_ptr == NULL)
			return (NULL);
		return (y_ptr);
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	y_ptr = malloc(size);
	if (y_ptr == NULL)
		return (NULL);
	free(ptr);
	return (y_ptr);
}
