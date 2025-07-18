/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:02 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:07:51 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	spher_normal(t_inter hold, t_objs *obj, t_Ray *ray)
{
	t_inter	inter;

	inter.t = inter_sphere(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPSYLON))
	{
		inter.col = obj->col;
		inter.hit = add_vec(ray->origin, mult_vec(ray->dir, inter.t));
		inter.norm = take_normalized(sub_vec(inter.hit, obj->cen));
		hold = inter;
	}
	return (hold);
}

t_inter	plane_normal(t_inter hold, t_objs *obj, t_Ray *ray)
{
	t_inter	inter;

	inter.t = inter_plane(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPSYLON))
	{
		inter.col = obj->col;
		inter.hit = add_vec(ray->origin, mult_vec(ray->dir, inter.t));
		inter.norm = obj->dir;
		if (dot_product(ray->dir, inter.norm) > 0)
			inter.norm = take_normalized(mult_vec(obj->dir, -1));
		hold = inter;
	}
	return (hold);
}

t_inter	cylinder_normal(t_inter hold, t_objs *obj, t_Ray *ray)
{
	t_inter	inter;
	double	m;
	t_vec	oc;

	inter.t = inter_cylinder(ray, obj);
	if (((hold.t > inter.t || hold.t == -1) && inter.t > EPSYLON))
	{
		inter.col = obj->col;
		inter.hit = add_vec(ray->origin, mult_vec(ray->dir, inter.t));
		oc = take_normalized(obj->dir);
		m = dot_product(ray->dir, mult_vec(oc, inter.t))
			+ dot_product(sub_vec(ray->origin, obj->cen), oc);
		inter.norm = take_normalized(sub_vec(sub_vec(inter.hit, obj->cen),
					mult_vec(oc, m)));
		hold = inter;
	}
	return (hold);
}
