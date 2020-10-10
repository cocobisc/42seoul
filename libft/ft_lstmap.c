/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:24:28 by youpark           #+#    #+#             */
/*   Updated: 2020/10/09 16:28:53 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*src;
	t_list	*dst;

	if (!lst || !f || !del)
		return (NULL);
	if (!(dst = ft_lstnew(f(lst->content))))
		return (NULL);
	src = dst;
	while (lst)
	{
		if (lst->next)
		{
			if (!(dst->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&src, del);
				return (0);
			}
			dst = dst->next;
		}
		lst = lst->next;
	}
	dst->next = NULL;
	return (src);
}
