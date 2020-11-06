/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <likilaki_@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:59:09 by youpark           #+#    #+#             */
/*   Updated: 2020/11/06 16:59:24 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t dest_len)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len])
		len++;
	if (!dest_len)
		return (len);
	i = 0;
	while (src[i] && i < (dest_len - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (src[i] && dest_len + i + 1 < dstsize)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dstsize < dest_len)
		return (dstsize + src_len);
	return (dest_len + src_len);
}

char		*ft_strdup(char *s1)
{
	char	*result;
	int		i;

	i = ft_strlen(s1);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	result[i] = 0;
	return (result);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		len1;
	int		len2;

	if (!(s1) && !(s2))
		return (0);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(p = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_strlcpy(p, s1, len1 + 1);
	free(s1);
	ft_strlcat(p + len1, s2, len2 + 1);
	return (p);
}
