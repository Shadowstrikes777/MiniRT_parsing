/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:57:44 by mmaevani          #+#    #+#             */
/*   Updated: 2024/07/22 19:07:22 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &d, 1);
	return (1);
}

int	ft_puthex(unsigned long long n, const char *base)
{
	unsigned long long	nbr;
	int					count;
	int					basen;
	char				c;

	nbr = n;
	count = 0;
	basen = ft_strlen(base);
	if (nbr / basen != 0)
		count += ft_puthex(nbr / basen, base);
	c = base[nbr % basen];
	count += ft_putchar(c);
	return (count);
}

int	ft_ptr(void *stuff)
{
	int	count;

	count = 0;
	if (stuff == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	if (stuff == (void *)-1)
	{
		count += write(1, "0xffffffffffffffff", 18);
		return (count);
	}
	count = write(1, "0x", 2);
	count += ft_puthex((unsigned long long)stuff, BASE16);
	return (count);
}
