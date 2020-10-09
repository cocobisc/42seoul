/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:25:58 by youpark           #+#    #+#             */
/*   Updated: 2020/10/07 21:24:28 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(int nbr)
{
	int				len;
	unsigned int	temp;

	if (nbr == 0)
		return (1);
	len = 0;
	temp = nbr;
	if (nbr < 0)
	{
		len++;
		temp = -temp;
	}
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				neg;
	unsigned int	temp;

	len = get_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	neg = 0;
	temp = n;
	if (n < 0)
	{
		neg = 1;
		str[0] = '-';
		temp = -n;
	}
	len--;
	while (len >= (neg ? 1 : 0))
	{
		str[len] = temp % 10 + '0';
		temp /= 10;
		len--;
	}
	return (str);
}
