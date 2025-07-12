/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:03:41 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/25 14:13:27 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	ft_atof(const char *nptr)
{
	float	f;
	int		dec_exp;
	int		sign;

	f = 0.0;
	dec_exp = 10;
	sign = 1;
	while (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -sign;
	while (*nptr >= '0' && *nptr <= '9')
		f = f * 10 + (*nptr++ - '0');
	if (*nptr == '.')
	{
		while (*++nptr >= '0' && *nptr <= '9')
		{
			f += (*nptr - '0') / (float)dec_exp;
			dec_exp *= 10;
		}
	}
	return (sign * f);
}

int	check_float(char *line, char end_char)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (line[i] == '-')
		i++;
	if (!ft_isdigit(line[i]))
		return (-1);
	while (line[i] && line[i] != end_char)
	{
		if (line[i] == '.')
		{
			if (dot || !ft_isdigit(line[i - 1]) || !ft_isdigit(line[i + 1]))
				return (-1);
			dot = 1;
		}
		else if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	if (line[i] != end_char)
		return (-1);
	return (1);
}

int	check_int(char *line, char end_char)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != end_char)
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	if (line[i] != end_char)
		return (-1);
	return (1);
}
