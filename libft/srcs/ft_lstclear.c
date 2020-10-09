/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:36:55 by youpark           #+#    #+#             */
/*   Updated: 2020/10/09 15:40:26 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur;
	t_list *next;

	if (lst && *lst && del)
	{
		cur = *lst;
		while (cur)
		{
			next = cur->next;
			ft_lstdelone(cur, del);
			cur = next;
		}
		*lst = NULL;
	}
}
