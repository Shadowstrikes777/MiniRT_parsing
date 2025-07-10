/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:43 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/08 08:45:36 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minirt.h"

double	inter_sphere(t_CamRay *ray, t_objs *sp)
{
	t_sphere	sph;

	sph.oc = sub_vec(ray->origin, sp->cen);
	sph.a = dot_product(ray->dir, ray->dir);
	sph.b = 2.0 * dot_product(sph.oc, ray->dir);
	sph.c = dot_product(sph.oc, sph.oc) - (sp->p.x / 2.0) * (sp->p.x / 2.0);
	sph.t = sph.b * sph.b - (4 * sph.a * sph.c);
	if (sph.t < EPS)
		return (-1);
	sph.t1 = (sph.b * (-1.0) - sqrt(sph.t)) / (2.0 * sph.a);
	sph.t2 = (sph.b * (-1.0) + sqrt(sph.t)) / (2.0 * sph.a);
	if (sph.t1 * sph.t2 > EPS)
	{
		if (sph.t1 > EPS)
			return (take_min(sph.t1, sph.t2));
		return (-1);
	}
	if (sph.t1 > EPS)
		return (sph.t1);
	return (sph.t2);
}

double	inter_plane(t_CamRay *ray, t_objs *pl)
{
	t_vec	x;
	t_vec	normal;
	double	t;
	double	b;
	double	a;

	normal = get_normalized(pl->dir);
	x = sub_vec(ray->origin, pl->cen);
	b = dot_product(ray->dir, normal);
	if (b != 0)
	{
		a = dot_product(x, normal);
		t = -a / b;
		if (t < EPS)
			return (-1.0);
		return (t);
	}
	return (-1.0);
}


/*static double	plane(t_CamRay *ray, t_vec pos, t_vec norm)
{
	t_vec	x;
	t_vec	normal;
	double	t;
	double	b;
	double	a;

	normal = get_normalized(norm);
	x = sub_vec(ray->origin, pos);
	b = dot_product(ray->dir, normal);
	if (b != 0)
	{
		a = dot_product(x, normal);
		t = -a / b;
		if (t < EPS)
			return (-1.0);
		return (t);
	}
	return (-1.0);
}*/
/*static double disk_inter(t_CamRay *self, t_vec pos, t_vec norm, t_objs *cy)

{

	double t = plane(self, pos, norm);

	t_vec inter = ray_at(self, t);
	if (module_v(sub_vec(inter, pos)) > cy->p.x / 2)
		return -1;
	printf("je suis bien traiter\n");
	return t;
}*/
double	pick_cy_inter(t_cylinder inf, t_CamRay *ray, t_objs *cy)
{
	inf.t1 = (-inf.b + sqrt(inf.delta)) / (2 * inf.a);
	inf.t2 = (-inf.b - sqrt(inf.delta)) / (2 * inf.a);
	if (inf.t1 < EPS)
		return (-1);
	if (inf.t1 > inf.t2)
		inf.t = inf.t2;
	else
		inf.t = inf.t1;

	inf.y0 = dot_product(ray->dir, inf.normal) * inf.t2
		+ dot_product(inf.oc, inf.normal);
	inf.y1 = dot_product(ray->dir, inf.normal) * inf.t1
		+ dot_product(inf.oc, inf.normal);
	if (inf.y0 >= EPS && inf.y0 <= cy->p.y)
		return (inf.t2);
	if (inf.y1 >= EPS && inf.y1 <= cy->p.y)
		return (inf.t1);
	return (-1);
}

double	inter_cylinder(t_CamRay *r, t_objs *cy)
{
	t_cylinder	inf;
	double		t;
	//double		d;

	inf.normal = get_normalized(cy->dir);
	inf.oc = sub_vec(r->origin, cy->cen);
	inf.a = dot_product(r->dir, r->dir) - (dot_product(r->dir, inf.normal)
			* dot_product(r->dir, inf.normal));
	inf.b = 2 * (dot_product(r->dir, inf.oc) - (dot_product(r->dir, inf.normal)
				* dot_product(inf.oc, inf.normal)));
	inf.c = dot_product(inf.oc, inf.oc)
		- (dot_product(inf.oc, inf.normal) * dot_product(inf.oc, inf.normal))
		- (cy->p.x / 2) * (cy->p.x) / 2;
	inf.delta = inf.b * inf.b - 4* inf.a * inf.c;
	//d = -inf.b + sqrt(inf.delta) / 2*inf.a;
	if (inf.delta < EPS)
		return 0;
	t = pick_cy_inter(inf, r, cy);
	/*t_vec to_hit = sub_vec(ray_at(r, d), cy->cen);
	t_vec normal;
	t_vec cap_pos;
	double axi = dot_product(to_hit, cy->dir);
	if (axi < 0)
	{
		cap_pos.x = 0.49;
		cap_pos.y = 0.49;
		cap_pos.z = 0.49;
		normal = mult_vec(cy->dir, 1);
		printf("axi negative\n");
		return(disk_inter(r, cap_pos, normal, cy));
	}
	if (axi > cy->p.y)
	{
		cap_pos = add_vec(cy->cen, mult_vec(cy->dir, cy->p.y));
		normal = cy->dir;
		printf("axi ggggg\n");
		return  (disk_inter(r, cap_pos, normal, cy));
	}*/
	return (t);
}
