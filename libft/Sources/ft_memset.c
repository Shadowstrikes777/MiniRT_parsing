/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:13:46 by mmaevani          #+#    #+#             */
/*   Updated: 2024/09/16 13:52:58 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	d;
	size_t			i;

	p = s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p[i] = d;
		i++;
	}
	return (p);
}
