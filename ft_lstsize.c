/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:42:44 by lpsyk             #+#    #+#             */
/*   Updated: 2021/06/29 16:12:47 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_len;

	if (!lst)
		return (0);
	lst_len = 1;
	while (lst->next != NULL)
	{
		lst_len++;
		lst = lst->next;
	}
	return (lst_len);
}
