/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:43:50 by lpsyk             #+#    #+#             */
/*   Updated: 2021/06/29 12:32:18 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	if (len == 0 || *haystack == 0)
		return (0);
	needle_len = ft_strlen(needle);
	if (needle_len > len)
		return (0);
	while (i <= len - needle_len)
	{
		if (ft_cmp(needle, haystack + i) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
