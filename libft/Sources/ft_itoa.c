/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:08:28 by mmaevani          #+#    #+#             */
/*   Updated: 2024/09/16 13:52:11 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_len(int c)
{
	int		size;
	long	nb;

	size = 0;
	nb = c;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static int	ft_alloc(char **ptr, int size)
{
	*ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!*ptr)
		return (0);
	else
		return (1);
}

static void	ft_putinarray(long long n, char **str, int size)
{
	int	i;

	i = size - 1;
	if (n < 0)
	{
		(*str)[0] = '-';
		n *= -1;
	}
	if (n == 0)
	{
		(*str)[0] = '0';
		return ;
	}
	while (n > 0 || i > 0)
	{
		(*str)[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = i_len(n);
	if (ft_alloc(&ptr, len) == 0)
	{
		return (NULL);
	}
	ft_putinarray(n, &ptr, len);
	ptr[len] = '\0';
	return (ptr);
}
