/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:43 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:29:13 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

double	inter_sphere(t_Ray *ray, t_objs *sp)
{
	t_sphere_exec	S;

	S.oc = sub_vec(ray->origin, sp->cen);
	S.a = dot_product(ray->dir, ray->dir);
	S.b = 2 * dot_product(S.oc, ray->dir);
	S.c = dot_product(S.oc, S.oc) - (sp->p.x / 2) * (sp->p.x / 2);
	S.t = S.b * S.b - (4 * S.a * S.c);
	if (S.t < EPSYLON)
		return (-1);
	S.t1 = (S.b * (-1) - sqrt(S.t)) / (2 * S.a);
	S.t2 = (S.b * (-1) + sqrt(S.t)) / (2 * S.a);
	if (S.t1 * S.t2 > EPSYLON)
	{
		if (S.t1 > EPSYLON)
			return (check_min(S.t1, S.t2));
		return (-1);
	}
	if (S.t1 > EPSYLON)
		return (S.t1);
	return (S.t2);
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
		t = (-1*a) / b;
		if (t < EPSYLON)
			return (-1.0);
		return (t);
	}
	return (-1.0);
}

double	limit_cy(t_cylinder_exec inf, t_Ray *ray, t_objs *cy)
{
	inf.t1 = (-inf.b + sqrt(inf.delta)) / (2 * inf.a);
	inf.t2 = (-inf.b - sqrt(inf.delta)) / (2 * inf.a);
	if (inf.t1 < EPSYLON)
		return (-1);
	if (inf.t1 > inf.t2)
		inf.t = inf.t2;
	else
		inf.t = inf.t1;

	inf.y0 = dot_product(ray->dir, inf.normal) * inf.t2
		+ dot_product(inf.oc, inf.normal);
	inf.y1 = dot_product(ray->dir, inf.normal) * inf.t1
		+ dot_product(inf.oc, inf.normal);
	if (inf.y0 >= EPSYLON && inf.y0 <= cy->p.y)
		return (inf.t2);
	if (inf.y1 >= EPSYLON && inf.y1 <= cy->p.y)
		return (inf.t1);
	return (-1);
}

double	inter_cylinder(t_Ray *r, t_objs *cy)
{
	t_cylinder_exec	inf;
	double		t;

	inf.normal = take_normalized(cy->dir);
	inf.oc = sub_vec(r->origin, cy->cen);
	inf.a = dot_product(r->dir, r->dir) - (dot_product(r->dir, inf.normal)
			* dot_product(r->dir, inf.normal));
	inf.b = 2 * (dot_product(r->dir, inf.oc) - (dot_product(r->dir, inf.normal)
				* dot_product(inf.oc, inf.normal)));
	inf.c = dot_product(inf.oc, inf.oc)
		- (dot_product(inf.oc, inf.normal) * dot_product(inf.oc, inf.normal))
		- (cy->p.x / 2) * (cy->p.x) / 2;
	inf.delta = inf.b * inf.b - 4* inf.a * inf.c;
	if (inf.delta < EPSYLON)
		return 0;
	t = limit_cy(inf, r, cy);
	return (t);
}
