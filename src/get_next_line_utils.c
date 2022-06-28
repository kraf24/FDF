/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:03:15 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/06/06 19:16:27 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		++count;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0)
	{
		while (src[count])
				count++;
		return (count);
	}
	while (src[count] != '\0' && count < dstsize - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (count);
}

char	*ft_new_string(char *string)
{
	size_t		size;
	char		*str;

	size = 0;
	if (!string[size])
		return (NULL);
	while (string[size] != '\n' && string[size])
		size++;
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, string, size + 2);
	return (str);
}

char	*ft_get_new_string(char *string)
{
	size_t	size;
	int		i;
	char	*new_str;

	i = 0;
	size = ft_strlen(string);
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (size - i));
	if (!new_str)
		return (NULL);
	i++;
	ft_strlcpy(new_str, &string[i], size - i + 1);
	free(string);
	return (new_str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i++])
		if (s[i] == (char)c)
			return (&s[i]);
	return (NULL);
}
