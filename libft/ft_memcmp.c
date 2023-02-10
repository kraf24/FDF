/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 05:43:38 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/14 05:43:38 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*((char *) s1 + i) - *((char *) s2 + i) != 0)
			return (*((unsigned char *) s1 + i) - *((unsigned char *) s2 + i));
		i++;
	}
	return (0);
}
