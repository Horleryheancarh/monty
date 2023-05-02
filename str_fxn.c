#include "main.h"

/**
 * _strcmp - fxn that compares strings
 * @str1: string 1
 * @str2: string 2
 * 
 * Return: 0 if strings are equal or 1 else
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;

	if (str[i] > str2[i])
		return 1;
	if (str[i] < str2[i])
		return 1;
	return 0;
}

/**
 * _sch - search if a char is inside a string
 * @str: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *str, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			break;
		i++;
	}

	if (s[i] == c)
		return 1;
	else
		return 0;
}

/**
 * _strtoky - fxn to cut a str into tokens
 * @str: string to cut in parts
 * @dec: delimiters
 * Return: first partition
 */
char *_strtoky(char *str, char *dec)
{
	static char *dstr;
	int i = 0, j = 0;

	if (!str)
		str = dstr;
	while (str[i] != '\0')
	{
		if (_sch(dec, str[i]) == 0 && str[i + 1] == '\0')
		{
			dstr = str + i + 1;
			*dstr = '\0';
			str = str + j;
			return str;
		}
		else if (_sch(dec, str[i]) == 0 && _sch(dec, str[i + 1]) == 0)
			i++;
		else if (_sch(dec, str[i]) == 0 && _sch(dec, str[i + 1]) == 1)
		{
			dstr = str + i + 1;
			*dstr = '\0';
			dstr++;
			str = str + j;
			return str;
		}
		else if (_sch(dec, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return NULL;
}
