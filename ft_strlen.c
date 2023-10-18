/**
 * ft_strlen - calculate the length of a string
 * @str: string
 * Return: length of the string
 */
int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
