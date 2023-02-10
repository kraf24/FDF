/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:39:27 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/14 00:39:27 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	i = n;
	while (i > 0)
	{
		*((char *) dest + i - 1) = *((char *) src + i - 1);
		i--;
	}
	return (dest);
}

// while (i < n)
// {
// 	*((char *) dest + i) = '\0';
// 	i++;
// }