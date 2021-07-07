/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:30:37 by lpsyk             #+#    #+#             */
/*   Updated: 2021/06/28 13:07:13 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_of_digits(long int n)
{
	size_t	digits;

	digits = 1;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n >= 10)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

static void	putnbr_to_str(unsigned int n, char *str, int pos)
{
	if (n >= 10)
	{
		putnbr_to_str(n / 10, str, pos - 1);
		putnbr_to_str(n % 10, str, pos);
	}
	else
		str[pos] = n + '0';
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			strlen;
	unsigned int	nbr;

	strlen = nbr_of_digits(n);
	str = (char *)malloc(strlen + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr = (unsigned int)(-n);
	}
	else
		nbr = (unsigned int)n;
	str[strlen] = 0;
	putnbr_to_str(nbr, str, strlen - 1);
	return (str);
}
