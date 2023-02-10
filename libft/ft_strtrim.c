/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:45:59 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/19 08:54:29 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	check_char(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s1[i] != '\0')
	{
		if (check_char(set, s1[i]) != 1)
			size++;
		i++;
	}
	str = malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	size = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (check_char(set, s1[i]) != 1)
			str[size++] = s1[i];
		i++;
	}
	return (str);
}
