/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:15:14 by youpark           #+#    #+#             */
/*   Updated: 2020/10/09 14:52:12 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**free_all(char **word_list)
{
	unsigned int	i;

	i = 0;
	while (word_list[i])
		free(word_list[i++]);
	free(word_list);
	return (NULL);
}

unsigned int		ft_get_str_cnt(char const *s, char c)
{
	unsigned int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s && *s == c)
				s++;
			continue;
		}
		cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

void				ft_jump_ws(char **ptr, char c)
{
	while (**ptr && **ptr == c)
		(*ptr)++;
}

unsigned int		get_word_len(char *ptr, char c)
{
	unsigned int	len;

	len = 0;
	while (*ptr && *ptr == c)
		ptr++;
	while (*ptr && *ptr != c)
	{
		len++;
		ptr++;
	}
	return (len);
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
	if (!(word_list = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (NULL);
	i = 0;
	word = (char *)s;
	while (i < cnt)
	{
		ft_jump_ws(&word, c);
		len = get_word_len(word, c);
		if (!(word_list[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (free_all(word_list));
		ft_strlcpy(word_list[i], word, len + 1);
		word += len;
		i++;
	}
	word_list[i] = NULL;
	return (word_list);
}
