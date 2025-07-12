/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:36:29 by mmaevani          #+#    #+#             */
/*   Updated: 2024/08/15 07:18:37 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static void	ft_free(char **ptr, int nb_words)
{
	int	i;

	i = 0;
	while (i < nb_words)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static char	**ft_alloc(char ***ptr, int *nb_words, char const *s, char c)
{
	if (!s)
		return (NULL);
	*nb_words = ft_nbwords((char *)s, c);
	*ptr = (char **)malloc(sizeof(char *) * (*nb_words + 1));
	if (!*ptr)
		return (NULL);
	(*ptr)[*nb_words] = NULL;
	return (*ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		nb_words;
	char	*start;

	ptr = ft_alloc(&ptr, &nb_words, s, c);
	if (!ptr)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			*ptr++ = ft_substr(start, 0, s - start);
			if (!*(ptr - 1))
			{
				ft_free(ptr - nb_words, nb_words);
				return (NULL);
			}
		}
	}
	return (ptr - nb_words);
}
