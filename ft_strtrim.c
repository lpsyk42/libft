/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:42:00 by lpsyk             #+#    #+#             */
/*   Updated: 2021/07/07 10:45:13 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_getlength(const char *s1, const char *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (ft_is_char_in_set(s1[i], set) == 1 && s1[i] != '\0')
		i++;
	j = i;
	while (s1[i] != '\0')
		i++;
	i -= 1;
	while (ft_is_char_in_set(s1[i], set) == 1 && &s1[i] > &s1[j])
		i--;
	j = i - j + 1;
	str = (char *)malloc(j + 1 * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s1 == (char *) NULL)
		return (NULL);
	str = ft_getlength(s1, set);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_is_char_in_set(s1[j], set) == 1 && s1[j] != '\0')
		j++;
	k = j;
	while (s1[j] != '\0')
		j++;
	j -= 1;
	while (ft_is_char_in_set(s1[j], set) == 1 && &s1[j] > &s1[k])
		j--;
	while (&s1[k] <= &s1[j])
		str[i++] = s1[k++];
	str[i] = '\0';
	return (str);
}
