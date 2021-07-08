/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:57:15 by lpsyk             #+#    #+#             */
/*   Updated: 2021/07/08 10:42:45 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	s_len;

	if (!s || !f)
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		f(i, &s[i]);
		i++;
	}
}
