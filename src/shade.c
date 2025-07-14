/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:59 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:36:11 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_inside(t_vec ray, t_vec norm)
{
	if (dot_product(ray, norm) > 0)
		return (1);
	return (0);
}

int	shade(t_scene *sc, t_inter inter, t_light_exec *light)
{
	t_vec	hit_light;
	t_Ray	sh_ray;
	t_inter	shadow;
	t_vec	hit_sh;

	hit_light = sub_vec(light->src, inter.hit);
	sh_ray.origin = inter.hit;
	sh_ray.dir = take_normalized(hit_light);
	shadow = find_inter(&sh_ray, sc);
	hit_sh = sub_vec(shadow.hit, sh_ray.origin);
	if (shadow.t > EPSYLON && (module_v(hit_light) > module_v(hit_sh)))
		return (1);
	return (0);
}

t_vec	diffuse(t_inter inter, t_light_exec *light, double d)
{
	t_vec	diff;

	diff = add_coef(inter.col, light->col, d * light->ratio);
	return (diff);
}
