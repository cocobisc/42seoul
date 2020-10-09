/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:12:13 by youpark           #+#    #+#             */
/*   Updated: 2020/10/07 19:14:37 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = 0;
	while (*s)
	{
		if (*s == c)
			pos = (char*)s;
		++s;
	}
	if (pos)
		return (pos);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
