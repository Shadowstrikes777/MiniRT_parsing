/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:40 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/14 16:51:28 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	calcul_color(t_scene *sc, t_inter inter, t_vec amb)
{
	t_light_exec	*light;
	t_vec			ret;
	t_vec			hit_light;
	double			d;

	ret = make_vec(0, 0, 0);
	light = &sc->light;
	if (!light)
		return (amb);
	if (shade(sc, inter, light))
		ret = add_color(ret, amb);
	else
	{
		hit_light = sub_vec(light->src, inter.hit);
		d = dot_product(take_normalized(hit_light), inter.norm);
		ret = add_color(ret, amb);
		if (d > 0)
			ret = add_color(ret, diffuse(inter, light, d));
	}
	return (ret);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_vec	add_coef(t_vec col1, t_vec col2, double ratio)
{
	t_vec	ret;

	ret.x = col1.x * (col2.x / 255) * ratio;
	ret.y = col1.y * (col2.y / 255) * ratio;
	ret.z = col1.z * (col2.z / 255) * ratio;
	return (ret);
}

t_vec	add_color(t_vec col1, t_vec col2)
{
	t_vec	res;

	res = add_vec(col1, col2);
	if (res.x > 255)
		res.x = 255;
	if (res.y > 255)
		res.y = 255;
	if (res.z > 255)
		res.z = 255;
	return (res);
}

t_vec	ray_color(t_Ray *ray, t_scene *sc)
{
	t_inter	inter;
	t_vec	px_col;
	t_vec	amb;

	inter = find_inter(ray, sc);
	if (inter.t > EPSYLON)
	{
		amb = add_coef(inter.col, sc->amb.col, sc->amb.ratio);
		if (is_inside(ray->dir, inter.norm))
			inter.norm = mult_vec(inter.norm, -1);
		px_col = calcul_color(sc, inter, amb);
		return (px_col);
	}
	return (mult_vec(sc->amb.col, sc->amb.ratio));
}
