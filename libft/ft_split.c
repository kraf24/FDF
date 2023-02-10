/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:47:30 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/19 17:46:38 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ignore_delimeter(const char *s, char c, int index)
{
	while (s[index] != '\0')
	{
		if (s[index] != c)
			return (index);
		index++;
	}
	return (index);
}

static char	*create_string(const char *s, char c, int start, int *size)
{
	char	*str;
	int		i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
	{
		i++;
	}
	*size = i;
	str = malloc(*size + 1);
	str[*size] = '\0';
	i = 0;
	while (i < *size)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

static char	**create_arr_strings(const char *s, char c)
{
	char	**str;
	int		size;
	int		i;

	size = 0;
	i = 0;
	i = ignore_delimeter(s, c, i);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i = ignore_delimeter(s, c, i);
			if (s[i] != '\0')
				size++;
		}
		else
			i++;
	}
	size++;
	str = (char **) malloc((size * sizeof(char *)) + sizeof(char *));
	str[size] = NULL;
	return (str);
}

static char	**delimeter(const char *s, char c)
{
	char	**str;
	int		size;
	int		i;
	int		index;

	str = create_arr_strings(s, c);
	size = 0;
	index = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i = ignore_delimeter(s, c, i);
		if (s[i] == '\0')
			break ;
		str[index] = create_string(s, c, i, &size);
		i += size;
		index++;
	}
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	str = malloc(sizeof(char *));
	str[0] = NULL;
	if (s[0] == '\0')
		return (str);
	free(str);
	str = delimeter(s, c);
	return (str);
}
