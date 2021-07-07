/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:33:59 by lpsyk             #+#    #+#             */
/*   Updated: 2021/07/07 10:38:23 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (src == (char *) NULL)
		return ((size_t) NULL);
	src_len = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (!size)
		return (src_len);
	while (*(src + i) != '\0' && i < (size - 1) && size > 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size < src_len)
		*(dest + size - 1) = '\0';
	else if (size != 0)
		*(dest + i) = '\0';
	return (src_len);
}
