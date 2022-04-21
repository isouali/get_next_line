/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouali <isouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:13:53 by isouali           #+#    #+#             */
/*   Updated: 2022/02/16 17:02:18 by isouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line(char *keep)
{
	char	*line;
	int		index;
	int		i;

	if (ft_strlen(keep) <= 0)
		return (NULL);
	index = find_new_line(keep);
	if (index == -1)
	{
		line = ft_strdup(keep);
		return (line);
	}
	line = (char *)malloc((index + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (keep[i] != '\n')
	{
		line[i] = keep[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_keep(char *keep)
{
	int		len;
	int		index;
	char	*tmp;

	if (!keep)
		return (NULL);
	len = ft_strlen(keep);
	index = find_new_line(keep);
	if (index != -1)
	{
		tmp = ft_substr(keep, (index + 1), (len - index - 1));
		free(keep);
		keep = tmp;
		return (keep);
	}
	free(keep);
	return (NULL);
}

char	*ft_read_line(int fd, char *buff, char *keep)
{
	char	*tmp;
	int		n;

	n = 0;
	while (find_new_line(keep) == -1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n > 0)
		{
			buff[n] = '\0';
			tmp = ft_strjoin(keep, buff);
			if (keep)
				free(keep);
			keep = tmp;
		}
		else
			break ;
	}
	free(buff);
	if (n == -1)
		return (NULL);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep[65535];
	char		*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	keep[fd] = ft_read_line(fd, buff, keep[fd]);
	line = ft_line(keep[fd]);
	keep[fd] = ft_keep(keep[fd]);
	return (line);
}
