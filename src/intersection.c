/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:43 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/15 07:55:00 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	inter_sphere(t_Ray *ray, t_objs *sp)
{
	t_sphere_exec	sph;

	sph.oc = sub_vec(ray->origin, sp->cen);
	sph.a = dot_product(ray->dir, ray->dir);
	sph.b = 2 * dot_product(sph.oc, ray->dir);
	sph.c = dot_product(sph.oc, sph.oc) - (sp->p.x / 2) * (sp->p.x / 2);
	sph.t = sph.b * sph.b - (4 * sph.a * sph.c);
	if (sph.t < EPSYLON)
		return (-1);
	sph.t1 = (sph.b * (-1) - sqrt(sph.t)) / (2 * sph.a);
	sph.t2 = (sph.b * (-1) + sqrt(sph.t)) / (2 * sph.a);
	if (sph.t1 * sph.t2 > EPSYLON)
	{
		if (sph.t1 > EPSYLON)
			return (check_min(sph.t1, sph.t2));
		return (-1);
	}
	if (sph.t1 > EPSYLON)
		return (sph.t1);
	return (sph.t2);
}

double	inter_plane(t_Ray *ray, t_objs *pl)
{
	t_vec	x;
	t_vec	normal;
	double	t;
	double	b;
	double	a;

	normal = take_normalized(pl->dir);
	x = sub_vec(ray->origin, pl->cen);
	b = dot_product(ray->dir, normal);
	if (b != 0)
	{
		a = dot_product(x, normal);
		t = (-1 * a) / b;
		if (t < EPSYLON)
			return (-1.0);
		return (t);
	}
	return (-1.0);
}

double	limit_cy(t_cylinder_exec limit, t_Ray *ray, t_objs *cy)
{
	limit.t1 = (-limit.b + sqrt(limit.delta)) / (2 * limit.a);
	limit.t2 = (-limit.b - sqrt(limit.delta)) / (2 * limit.a);
	if (limit.t1 < EPSYLON)
		return (-1);
	if (limit.t1 > limit.t2)
		limit.t = limit.t2;
	else
		limit.t = limit.t1;
	limit.y0 = dot_product(ray->dir, limit.normal) * limit.t2
		+ dot_product(limit.oc, limit.normal);
	limit.y1 = dot_product(ray->dir, limit.normal) * limit.t1
		+ dot_product(limit.oc, limit.normal);
	if (limit.y0 >= EPSYLON && limit.y0 <= cy->p.y)
		return (limit.t2);
	if (limit.y1 >= EPSYLON && limit.y1 <= cy->p.y)
		return (limit.t1);
	return (-1);
}

double	inter_cylinder(t_Ray *r, t_objs *cy)
{
	t_cylinder_exec	cy_data;
	double			t;

	cy_data.normal = take_normalized(cy->dir);
	cy_data.oc = sub_vec(r->origin, cy->cen);
	cy_data.a = dot_product(r->dir, r->dir)
		- (dot_product(r->dir, cy_data.normal)
			* dot_product(r->dir, cy_data.normal));
	cy_data.b = 2 * (dot_product(r->dir, cy_data.oc)
			- (dot_product(r->dir, cy_data.normal)
				* dot_product(cy_data.oc, cy_data.normal)));
	cy_data.c = dot_product(cy_data.oc, cy_data.oc)
		- (dot_product(cy_data.oc, cy_data.normal)
			* dot_product(cy_data.oc, cy_data.normal))
		- (cy->p.x / 2) * (cy->p.x) / 2;
	cy_data.delta = cy_data.b * cy_data.b - 4 * cy_data.a * cy_data.c;
	if (cy_data.delta < EPSYLON)
		return (0);
	t = limit_cy(cy_data, r, cy);
	return (t);
}
