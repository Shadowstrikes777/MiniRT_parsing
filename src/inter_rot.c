/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:22 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:07:51 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	find_inter(t_Ray *ray, t_scene *sc)
{
	t_inter	hold;
	t_objs	*obj;

	hold.t = -1.0;
	obj = sc->objs;
	while (obj)
	{
		if (obj->type == SP)
			hold = spher_normal(hold, obj, ray);
		if (obj->type == PL)
			hold = plane_normal(hold, obj, ray);
		if (obj->type == CY)
			hold = cylinder_normal(hold, obj, ray);
		obj = obj->next;
	}
	return (hold);
}

void objs_rotation(int n, t_scene *sc)
{
	if (n == 122)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873) + sc->selected->dir.y * sin(0.0873);
		sc->selected->dir.y = (-1*sc->selected->dir.x * sin(0.0873)) + sc->selected->dir.y * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (n == 120)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873) - sc->selected->dir.y * sin(0.0873);
		sc->selected->dir.y = (sc->selected->dir.x * sin(0.0873)) + sc->selected->dir.y * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
		if (n == 113)
	{
		sc->selected->dir.y = sc->selected->dir.y * cos(0.0873) - sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (sc->selected->dir.y * sin(0.0873)) + sc->selected->dir.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (n == 119)
	{
		sc->selected->dir.y = sc->selected->dir.y * cos(0.0873) + sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (-1*sc->selected->dir.y * sin(0.0873)) + sc->selected->dir.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (n == 97)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873) + sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (-1*sc->selected->dir.x * sin(0.0873)) + sc->selected->dir.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (n == 115)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873) - sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (sc->selected->dir.x * sin(0.0873)) + sc->selected->dir.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
}


void cam_rotation(int n, t_scene *sc)
{

if (n == 99)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873) + sc->render.cam.forward.y * sin(0.0873);
		sc->render.cam.forward.y = (-1*sc->render.cam.forward.x * sin(0.0873)) + sc->render.cam.forward.y * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (n == 118)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873) - sc->render.cam.forward.y * sin(0.0873);
		sc->render.cam.forward.y = (sc->render.cam.forward.x * sin(0.0873)) + sc->render.cam.forward.y * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
		if (n == 101)
	{
		sc->render.cam.forward.y = sc->render.cam.forward.y * cos(0.0873) - sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (sc->render.cam.forward.y * sin(0.0873)) + sc->render.cam.forward.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (n == 114)
	{
		sc->render.cam.forward.y = sc->render.cam.forward.y * cos(0.0873) + sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (-1*sc->render.cam.forward.y * sin(0.0873)) + sc->render.cam.forward.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
		if (n == 100)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873) + sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (-1*sc->render.cam.forward.x * sin(0.0873)) + sc->render.cam.forward.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (n == 102)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873) - sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (sc->render.cam.forward.x * sin(0.0873)) + sc->render.cam.forward.z * cos(0.0873);
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}	
}
