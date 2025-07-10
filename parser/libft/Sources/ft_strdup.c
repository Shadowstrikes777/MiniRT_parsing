/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:10:34 by mmaevani          #+#    #+#             */
/*   Updated: 2025/01/11 15:18:25 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;

	if (!s)
	{
		ptr = malloc(1);
		*ptr = '\0';
		return (ptr);
	}
	ptr = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (ptr)
		ft_strcpy(ptr, s);
	return (ptr);
}
