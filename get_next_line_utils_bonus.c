/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:26:45 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/28 19:09:14 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char		*ft_strchr(const char *s, int c)
{
	char	*pos;
	char	*str;

	str = (char *)s;
	pos = NULL;
	if (s == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

char		*ft_strdup(const char *src)
{
	char	*str;
	char	*p;

	str = (char *)malloc(ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	p = str;
	while (*src)
		*(p++) = *(src++);
	*p = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	unsigned	i;
	unsigned	j;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	if (!(sub = (char *)malloc(len + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
