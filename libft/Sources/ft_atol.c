/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:11:16 by mmaevani          #+#    #+#             */
/*   Updated: 2024/12/13 14:17:40 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int			i;
	long long	nb;
	int			sign;
	const char	*p;

	nb = 0;
	i = 0;
	sign = 1;
	p = str;
	while (p[i] == ' ' || (p[i] >= 9 && p[i] <= 13))
		i++;
	if (p[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (p[i] == '+')
		i++;
	while (p[i] >= '0' && p[i] <= '9')
	{
		nb = nb * 10 + (p[i] - '0');
		i++;
	}
	return ((long)sign * nb);
}
