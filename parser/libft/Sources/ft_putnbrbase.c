/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:55:00 by mmaevani          #+#    #+#             */
/*   Updated: 2024/08/15 07:18:52 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase(int n, const char *base)
{
	long long	nbr;
	int			count;
	int			basen;
	char		c;

	nbr = n;
	count = 0;
	basen = ft_strlen(base);
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr / basen != 0)
		count += ft_putnbrbase(nbr / basen, base);
	c = base[nbr % basen];
	count += ft_putchar(c);
	return (count);
}
