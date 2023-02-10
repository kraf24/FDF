/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:11:53 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/18 13:11:53 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nums[11];
	int		mod;
	int		i;

	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
		write(fd, "-", 1);
	i = 0;
	while (n != 0)
	{
		mod = n % 10;
		n /= 10;
		if (mod < 0)
			mod *= -1;
		nums[i] = mod + 48;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &nums[i], 1);
		i--;
	}
}
