/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:17:47 by mmaevani          #+#    #+#             */
/*   Updated: 2024/10/15 16:49:49 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	const char	*p;
	long		nb;
	int			sign;

	nb = 0;
	sign = 1;
	p = nptr;
	while (*p == ' ' || (*p >= 9 && *p <= 13))
		p++;
	if (*p == '-')
	{
		sign *= -1;
		p++;
	}
	else if (*p == '+')
		p++;
	while (*p >= '0' && *p <= '9')
	{
		nb = nb * 10 + (*p - '0');
		p++;
	}
	return (sign * nb);
}
