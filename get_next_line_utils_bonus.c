/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouali <isouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:15:03 by isouali           #+#    #+#             */
/*   Updated: 2022/02/16 17:02:07 by isouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc((len1 + len2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		p[i + len1] = s2[i];
		i++;
	}
	p[i + len1] = '\0';
	return (p);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(s);
	if (!s)
		return (NULL);
	p = malloc((n + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < (int)n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		p = malloc((ft_strlen(s + start) + 1) * sizeof(char));
	else
		p = malloc(((int)len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[start] && i < (int)len && ft_strlen(s) >= start)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
