/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:15:14 by youpark           #+#    #+#             */
/*   Updated: 2020/10/09 14:00:34 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_get_str_cnt(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			while (s[i] && s[i] == c)
				i++;
			continue;
		}
		cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

char				**ft_split(char const *s, char c)
{
	char			**word_list;
	char			*word;
	unsigned int	i;
	unsigned int	len;
	unsigned int	cnt;

	if (!s)
		return (NULL);
	cnt = ft_get_str_cnt(s, c);
	i = 0;
	len = 0;
	word = (char *)s;
	while (i < cnt)
	{

	}
}
