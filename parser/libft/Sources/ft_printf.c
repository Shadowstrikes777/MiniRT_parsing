/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:23:37 by mmaevani          #+#    #+#             */
/*   Updated: 2024/07/22 19:07:18 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_conv(char *s, va_list args, int *i, int *count)
{
	int		j;
	char	specifier;

	j = *i;
	specifier = s[j + 1];
	if (specifier == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		*count += ft_ptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		*count += ft_putnbrbase(va_arg(args, int), BASE10);
	else if (specifier == 'u')
		*count += ft_puthex(va_arg(args, unsigned int), BASE10);
	else if (specifier == 'x')
		*count += ft_puthex(va_arg(args, unsigned int), BASE16);
	else if (specifier == 'X')
		*count += ft_puthex(va_arg(args, unsigned int), BASE16M);
	else if (specifier == '%')
		*count += write(1, "%", 1);
	(*i)++;
	return ;
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr(CONVC, s[i + 1]) != NULL)
		{
			ft_print_conv((char *)s, args, &i, &count);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
