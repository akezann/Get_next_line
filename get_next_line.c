/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:52:04 by akezanna          #+#    #+#             */
/*   Updated: 2019/12/12 16:36:32 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		ft_memdel(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned	lens1;
	unsigned	lens2;
	char		*sj;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(sj = (char *)malloc(lens1 + lens2 + 1)))
		return (0);
	ft_memcpy(sj, s1, lens1);
	ft_memcpy(sj + lens1, s2, lens2);
	sj[lens1 + lens2] = '\0';
	return (sj);
}

static	int		findline(char **rest, char **line)
{
	int		size;
	char	*perm;

	size = 0;
	while ((*rest)[size] != '\n' && (*rest)[size] != '\0')
		size++;
	if ((*rest)[size] == '\n')
	{
		*line = ft_substr(*rest, 0, size);
		perm = ft_strdup(ft_strchr(*rest, '\n') + 1);
		ft_memdel(rest);
		*rest = perm;
	}
	else
	{
		*line = ft_strdup(*rest);
		ft_memdel(rest);
	}
	return (1);
}

static	int		returnvalue(char **rest, char **line, int readres)
{
	if (readres < 0)
		return (-1);
	else if (*rest == NULL || **rest == '\0')
		return (0);
	else
		return (findline(rest, line));
}

int				get_next_line(int fd, char **line)
{
	int				res;
	char			buff[BUFFER_SIZE + 1];
	static	char	*rest;
	char			*perm;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';
		perm = ft_strjoin(rest, buff);
		if (rest)
		{
			free(rest);
			rest = NULL;
		}
		rest = perm;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (returnvalue(&rest, line, res));
}
