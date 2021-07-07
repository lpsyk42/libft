/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:18:15 by lpsyk             #+#    #+#             */
/*   Updated: 2021/06/29 13:44:30 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_space(char c)
{
	if ((c == ' ') || (c == '\n')
		|| (c == '\t') || (c == '\v')
		|| (c == '\r') || (c == '\f'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
