/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 06:15:48 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/14 06:15:48 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strlen(const char *s);

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	i;
	int				j;
	unsigned int	littlesize;

	littlesize = ft_strlen(little) - 1;
	if (littlesize + 1 == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && i < len - littlesize)
	{
		j = 0;
		while (little[j] != '\0')
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (j == ft_strlen(little))
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
