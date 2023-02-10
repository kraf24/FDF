/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odouhri <odouhri@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:19:49 by odouhri           #+#    #+#             */
/*   Updated: 2022/12/14 07:19:49 by odouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	convert_num(char c, int num)
{
	num *= 10;
	num += c - 48;
	return (num);
}

static int	ignore_space(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] != '\0' || (nptr[i] >= 48 && nptr[i] <= 57))
	{
		if (nptr[i] != ' ' && nptr[i] != '\t' && nptr[i] != '\v'
			&& nptr[i] != '\n' && nptr[i] != '\r' && nptr[i] != '\f')
			break ;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	isneg;

	num = 0;
	i = ignore_space(nptr);
	isneg = 0;
	while (nptr[i] != '\0')
	{		
		if ((nptr[i] == '-' || nptr[i] == '+')
			&& (nptr[i + 1] >= 48 && nptr[i + 1] <= 57))
		{
			if (nptr[i] == '-')
				isneg = 1;
		}
		else if (nptr[i] >= 48 && nptr[i] <= 57)
			num = convert_num(nptr[i], num);
		else
			break ;
		i++;
	}
	if (isneg == 1)
		num *= -1;
	return (num);
}
