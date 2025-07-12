/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:49 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:07:51 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

double	get_norm2(t_vec v)
{
	double	result;

	result = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	return (result);
}

void	normalize(t_vec *v)
{
	double	norm;

	norm = sqrt(get_norm2(*v));
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
}

t_vec	take_normalized(t_vec v)
{
	t_vec	v1;

	v1 = v;
	normalize(&v1);
	return (v1);
}
