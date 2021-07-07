/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:43:01 by lpsyk             #+#    #+#             */
/*   Updated: 2021/07/02 12:14:45 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_c(char *str, char end)
{
	size_t	len;

	len = 0;
	while (str[len] != 0 && str[len] != end)
		len++;
	return (len);
}

static int	ft_nb_parts(const char *s, char c)
{
	size_t	i;
	size_t	parts;

	i = 0;
	parts = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			parts++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (parts);
}

static void	free_all(char ***ptr, size_t n)
{
	while (*ptr[0])
	{
		free(*ptr[n]);
		n--;
	}
	free(*ptr);
	ptr = 0;
}

static int	next_part(const char *s, char c, size_t *i)
{
	while (s[*i] == c && s[*i] != 0)
		*i = *i + 1;
	if (s[*i] == 0)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	n;
	size_t	len;
	char	**strings;

	if (!s)
		return (0);
	strings = (char **)ft_calloc(sizeof(char *), (ft_nb_parts(s, c) + 1));
	if (!strings)
		return (0);
	i = 0;
	n = 0;
	while (s[i])
	{
		if (!next_part(s, c, &i))
			break ;
		len = ft_strlen_c((char *)s + i, c);
		strings[n] = ft_substr(s, i, len);
		if (strings[n] == 0 && s[i] != 0)
			free_all(&strings, n);
		n++;
		i = i + len;
	}
	return (strings);
}
