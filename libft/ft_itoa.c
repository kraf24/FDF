/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:13:30 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/18 09:13:30 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	nbrlen(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	convert_nbr(char *str, int n, int size, int isovf)
{
	int	count;

	count = size;
	while (n > 0)
	{
		str[count - 1] = n % 10 + '0';
		n /= 10;
		count--;
	}
	if (isovf == 1)
		str[size - 1]++;
}

static char	*neg_num(int n)
{
	char	*str;
	int		isovf;
	int		size;

	isovf = 0;
	if (n == -2147483648)
	{
		n += 1;
		isovf = 1;
	}
	n *= -1;
	size = nbrlen(n) + 1;
	str = malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	str[0] = '-';
	convert_nbr(str, n, size, isovf);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n > 0)
	{
		size = nbrlen(n);
		str = malloc((size + 1) * sizeof(char));
		str[size] = '\0';
		convert_nbr(str, n, size, 0);
	}
	else if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = 0 + '0';
		str[1] = '\0';
	}
	else
		str = neg_num(n);
	return (str);
}
