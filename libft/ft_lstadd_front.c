/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:23:34 by youpark           #+#    #+#             */
/*   Updated: 2020/10/09 15:29:23 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else if (*lst && new)
	{
		temp = *lst;
		new->next = temp;
		*lst = new;
	}
}
