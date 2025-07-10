/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:08:54 by mmaevani          #+#    #+#             */
/*   Updated: 2024/07/22 19:07:43 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	topos(int nb, int fd)
{
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_fd('-', fd);
	}
	return (nb);
}

static void	ft_digit(int nb, int fd)
{
	int	digit;
	int	stacked_digit;

	digit = nb / 10;
	stacked_digit = nb % 10;
	if (digit != 0)
	{
		ft_digit(digit, fd);
	}
	ft_putchar_fd('0' + stacked_digit, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	posnb;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		posnb = topos(n, fd);
		ft_digit(posnb, fd);
	}
}
