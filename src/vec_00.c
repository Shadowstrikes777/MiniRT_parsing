/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:16 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:07:51 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	null_vec(t_vec *v)
{
	v->x = 0;
	v->y = 0;
	v->z = 0;
}

double	dot_product(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec	vect_cross(t_vec u, t_vec v)
{
	t_vec	w;

	w.x = (u.y * v.z) - (u.z * v.y);
	w.y = (u.x * v.z) - (u.z * v.x);
	w.z = (u.x * v.y) - (u.y * v.x);
	return (w);
}

t_vec	mult_vec(t_vec v, double a)
{
	v.x = v.x * a;
	v.y = v.y * a;
	v.z = v.z * a;
	return (v);
}

t_vec	add_vec(t_vec u, t_vec v)
{
	t_vec	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}
