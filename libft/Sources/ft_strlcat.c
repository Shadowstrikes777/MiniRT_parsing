/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:01:55 by mmaevani          #+#    #+#             */
/*   Updated: 2024/09/16 13:54:14 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	res;

	i = 0;
	len = 0 ;
	while (dst[len] && len < size)
		len++;
	res = len;
	while (len + 1 < size && src[i] != '\0')
	{
		dst[len] = src [i];
		i++;
		len++;
	}
	if (res < size)
	{
		dst[len] = '\0';
		return (res + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
