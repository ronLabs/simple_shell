#include "shell.h"
/**
* _strcpy - function that copy a string
* @dest: copy to string
* @src: copy from string
* @n: at parameter
*
* Description: copies a string to the nth value.
* Return: dest
*/
char *_strcpy(char *dest, char *src)
{
	int len;

	for (len = 0; src[len]; len++)
	{
		if (n > len)
		dest[len] = src[len];
	}
	for ( ; n > len; len++)
	{
		dest[len] = '\0';
	}
	return (dest);
}
/**
* _strlen - function
* @s: first operand & pointer
*
* Description: function that returns the length of a string
* Return: Always 0
*/
int _strlen(char *s)
{
	int index = 0;

	while (*s != '\0')
	{
		index++;
		s++;
	}
	return (index);
}
/**
  * _strcmp - compares two strings.
  * @s1: first string.
  * @s2: second string.
  * Return: j
  */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s1[i] != 0)
	{
		j = s1[i] - s2[i];
		if (j != 0)
			return (j);
		i++;
	}
	return (j);
}

/**
* _strcat - function
* @dest: string to add to
* @src: string to add
*
* Description: functions to concat two strings
* Return: string
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (i = 0 ; dest[i] != '\0' ; i++)
	{
	}
	for (j = 0 ; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}

/**
 *_strdup - duplicates a string
 *@str: string to dupplicate
 *Return: NULL on error or empty, return duplicated string.
 */

char *_strdup(char *str)
{
	int i;
	int j;
	char *c;

	if (str == 0)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	c = malloc(sizeof(char) * (i + 1));
	if (c == 0)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		c[j] = str[j];
	}
	c[j] = '\0';
	return (c);
}
