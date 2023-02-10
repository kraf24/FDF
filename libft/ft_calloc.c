/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:54:27 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/15 12:39:36 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > 65535 && size > 65535)
		return (NULL);
	arr = malloc(nmemb * size);
	return (arr);
}
