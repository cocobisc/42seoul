/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:05:19 by youpark           #+#    #+#             */
/*   Updated: 2020/10/06 23:08:16 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pd;
	unsigned char *ps;

	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	while (n > 0)
	{
		*pd++ = *ps++;
		n--;
	}
	return (dst);
}
