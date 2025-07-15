/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:32 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/15 07:55:46 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera_exec	set_camera(t_scene *sc)
{
	t_camera_exec	cam;

	cam.orig = sc->cam.cen;
	cam.aspect_ration = (double)WIDTH / (double)HEIGHT;
	cam.on_v = sc->cam.fov * M_PI / 180;
	cam.he = tan(cam.on_v / 2);
	cam.wid = cam.aspect_ration * cam.he;
	cam.forward = sc->cam.dir;
	cam.forward.x += EPSYLON;
	cam.uper = take_normalized(vect_cross(cam.forward, make_vec(0, 1, 0)));
	cam.ri = take_normalized(vect_cross(cam.forward, cam.uper));
	return (cam);
}

t_Ray	ray_primary(t_camera_exec *cam, double v, double u)
{
	t_Ray	ray;

	ray.origin = cam->orig;
	ray.dir = add_vec(add_vec(mult_vec(cam->uper, v * cam->he),
				mult_vec(cam->ri, u
					* cam->wid)), cam->forward);
	ray.dir = take_normalized(ray.dir);
	return (ray);
}

t_vec	colorize(double r, double g, double b)
{
	t_vec	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

t_vec	ray_at(t_Ray *ray, double t)
{
	t_vec	target;

	target.x = ray->origin.x + t * ray->dir.x;
	target.y = ray->origin.y + t * ray->dir.y;
	target.z = ray->origin.z + t * ray->dir.z;
	return (target);
}
