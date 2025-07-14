/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:22 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/14 17:16:43 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cam_helper(int n, t_scene *sc)
{
	if (n == 101)
	{
		sc->render.cam.forward.y = sc->render.cam.forward.y * cos(0.0873)
			- sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (sc->render.cam.forward.y * sin(0.0873))
			+ sc->render.cam.forward.z * cos(0.0873);
	}
	if (n == 114)
	{
		sc->render.cam.forward.y = sc->render.cam.forward.y * cos(0.0873)
			+ sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (-1 * sc->render.cam.forward.y * sin(0.0873))
			+ sc->render.cam.forward.z * cos(0.0873);
	}
	if (n == 100)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873)
			+ sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (-1 * sc->render.cam.forward.x * sin(0.0873))
			+ sc->render.cam.forward.z * cos(0.0873);
	}
}

static void	objs_helper(int n, t_scene *sc)
{
	if (n == 119)
	{
		sc->selected->dir.y = sc->selected->dir.y * cos(0.0873)
			+ sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (-1 * sc->selected->dir.y * sin(0.0873))
			+ sc->selected->dir.z * cos(0.0873);
	}
	if (n == 97)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873)
			+ sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (-1 * sc->selected->dir.x * sin(0.0873))
			+ sc->selected->dir.z * cos(0.0873);
	}
	if (n == 115)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873)
			- sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (sc->selected->dir.x * sin(0.0873))
			+ sc->selected->dir.z * cos(0.0873);
	}
}

t_inter	find_inter(t_Ray *ray, t_scene *sc)
{
	t_inter	point;
	t_objs	*obj;

	point.t = -1.0;
	obj = sc->objs;
	while (obj)
	{
		if (obj->type == SP)
			point = spher_normal(point, obj, ray);
		if (obj->type == PL)
			point = plane_normal(point, obj, ray);
		if (obj->type == CY)
			point = cylinder_normal(point, obj, ray);
		obj = obj->next;
	}
	return (point);
}

void	objs_rotation(int n, t_scene *sc)
{
	if (n == 120)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873)
			- sc->selected->dir.y * sin(0.0873);
		sc->selected->dir.y = (sc->selected->dir.x * sin(0.0873))
			+ sc->selected->dir.y * cos(0.0873);
	}
	if (n == 113)
	{
		sc->selected->dir.y = sc->selected->dir.y * cos(0.0873)
			- sc->selected->dir.z * sin(0.0873);
		sc->selected->dir.z = (sc->selected->dir.y * sin(0.0873))
			+ sc->selected->dir.z * cos(0.0873);
	}
	objs_helper(n, sc);
}

void	cam_rotation(int n, t_scene *sc)
{
	if (n == 99)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873)
			+ sc->render.cam.forward.y * sin(0.0873);
		sc->render.cam.forward.y = (-1 * sc->render.cam.forward.x * sin(0.0873))
			+ sc->render.cam.forward.y * cos(0.0873);
	}
	if (n == 118)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873)
			- sc->render.cam.forward.y * sin(0.0873);
		sc->render.cam.forward.y = (sc->render.cam.forward.x * sin(0.0873))
			+ sc->render.cam.forward.y * cos(0.0873);
	}
	cam_helper(n, sc);
}
