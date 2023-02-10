/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:40:53 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/15 06:40:53 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*str;
	unsigned int	i;
	unsigned int	ssize;

	ssize = ft_strlen(s);
	if (start >= ssize)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	if (ssize - start < len)
		len = ssize - start;
	str = malloc((len + 1) * sizeof(char));
	str[len] = '\0';
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	return (str);
}
