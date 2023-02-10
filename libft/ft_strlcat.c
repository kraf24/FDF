/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:24:51 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/14 01:24:51 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dstsize;
	unsigned int	srcsize;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (size == 0 || size < dstsize)
		return (srcsize + size);
	i = 0;
	while (src[i] != '\0' && dstsize + i < size - 1)
	{
		dst[dstsize + i] = src[i];
		i++;
	}
	dst[dstsize + i] = '\0';
	return (dstsize + srcsize);
}
