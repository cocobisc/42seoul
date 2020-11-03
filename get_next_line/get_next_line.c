/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:50:06 by youpark           #+#    #+#             */
/*   Updated: 2020/11/03 23:55:23 by youpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_newline_idx(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i++] == '\n')
			return (i - 1);
	}
	return (-1);
}

int		split(char **backup, char **line, int idx)
{
	int		rest_len;
	char	*p;
	char	*temp;

	temp = *backup;
	backup += idx + 1;
	rest_len = ft_strlen(*backup);
	if (rest_len)
		p = ft_strdup(*backup);
	free(temp);
	*backup = rest_len ? p : 0;
	return (1);
}

int		free_all(char **backup, char **line)
{
	int	idx;

	if (*backup)
	{
		idx = get_newline_idx(*backup);
		if (idx != -1)
			return split(backup, line, idx);
		else
		{
			*line = *backup;
			*backup = 0;
			return (0);
		}
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	int			size;
	int			idx;
	char		buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || (fd < 0) || line == 0)
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = 0;
		backup[fd] = ft_strjoin(backup[fd], buff);
		idx = get_newline_idx(backup[fd]);
		if (idx != -1)
		{
			backup[idx] = 0;
			*line = ft_strdup(backup[idx]);
			return (split(&backup[fd], line, idx));
		}
	}
	if (size < 0)
		return (-1);
	return (free_all(&backup[fd], line));
}
