/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:28:23 by mmaevani          #+#    #+#             */
/*   Updated: 2024/10/15 16:49:56 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	long	total;

	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size * nmemb);
	if ((total >= -2147483648 && total <= 2147483647) && ptr)
	{
		return (ptr);
	}
	return (0);
}
