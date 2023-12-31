#include <stdlib.h>

/**
 * ft_strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *ft_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}

/**
 * ft_strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: difference between first non-matching characters
 */
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}

	return (s1[i] - s2[i]);
}

#include <stdlib.h>

/**
 * ft_strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to duplicated string
 */
char *ft_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	if (!str)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * ft_strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to append
 * Return: pointer to concatenated string
 */
char *ft_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return (dest);
}

/**
 * ft_strncmp - compares two strings up to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 * Return: difference between first non-matching characters
 */
int ft_strncmp(char *s1, char *s2, int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (s1[i] - s2[i]);
}
