/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:06 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/08 08:36:13 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minirt.h"

double	take_min(double x, double y)
{
	if (x > y)
		return (y);
	return (x);
}

void    ft_err(char *err)
{
        printf("Error : %s\n", err);
        exit(1);
}
