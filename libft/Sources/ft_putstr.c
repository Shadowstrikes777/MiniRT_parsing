/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:01:30 by mmaevani          #+#    #+#             */
/*   Updated: 2024/07/22 19:07:56 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s[i])
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}
