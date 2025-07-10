/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:17:30 by mmaevani          #+#    #+#             */
/*   Updated: 2024/10/18 14:24:47 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*final;

	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	i = gnl_strlen(s1) + gnl_strlen(s2);
	j = 0;
	final = (char *)malloc(sizeof(char) * (i + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (s1[i])
		final[i++] = s1[j++];
	j = 0;
	while (s2[j])
		final[i++] = s2[j++];
	final[i] = '\0';
	free((char *)s1);
	return (final);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s)
{
	char	*ptr;
	int		len;

	len = gnl_strlen(s);
	ptr = malloc(sizeof(*s) * (len + 1));
	if (ptr)
		ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (start >= s_len)
	{
		p = (char *)malloc(sizeof(char) * 1);
		if (!p)
			return (NULL);
		*p = '\0';
		return (p);
	}
	if (len > s_len - start)
		len = s_len - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	gnl_strlcpy(p, s + start, len + 1);
	return (p);
}
