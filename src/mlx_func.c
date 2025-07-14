/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:46 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/14 16:51:09 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static void	translation(t_scene *sc, int key)
{
	if (key == 65362)
		sc->selected->cen.z += 0.2;
	if (key == 65364)
		sc->selected->cen.z -= 0.2;
	if (key == 65361)
		sc->selected->cen.x += 0.2;
	if (key == 65363)
		sc->selected->cen.x -= 0.2;
	if (key == 65365)
		sc->selected->cen.y += 0.2;
	if (key == 65366)
		sc->selected->cen.y -= 0.2;
	light_translation(key, sc);
	objs_rotation(key, sc);
	cam_rotation(key, sc);
	if (key == 102)
	{
		sc->render.cam.forward.x = sc->render.cam.forward.x * cos(0.0873)
			- sc->render.cam.forward.z * sin(0.0873);
		sc->render.cam.forward.z = (sc->render.cam.forward.x * sin(0.0873))
			+ sc->render.cam.forward.z * cos(0.0873);
	}
}

void	light_translation(int key, t_scene *sc)
{
	if (key == 65379)
		sc->light.src.z += 0.2;
	if (key == 65360)
		sc->light.src.z -= 0.2;
	if (key == 65535)
		sc->light.src.x += 0.2;
	if (key == 65367)
		sc->light.src.x -= 0.2;
	if (key == 65407)
		sc->light.src.y += 0.2;
	if (key == 65455)
		sc->light.src.y -= 0.2;
	if (key == 122)
	{
		sc->selected->dir.x = sc->selected->dir.x * cos(0.0873)
			+ sc->selected->dir.y * sin(0.0873);
		sc->selected->dir.y = (-1 * sc->selected->dir.x * sin(0.0873))
			+ sc->selected->dir.y * cos(0.0873);
	}
}

int	handle_key(int key, t_scene *sc)
{
	if (key == 110)
		if (sc->selected->next != NULL)
			sc->selected = sc->selected->next;
	if (key == 112)
		if (sc->selected->prev != NULL)
			sc->selected = sc->selected->prev;
	translation(sc, key);
	if (key == 65307)
		return (red_button(sc));
	if (key == 65431)
		sc->render.cam.orig.z += 0.2;
	if (key == 65433)
		sc->render.cam.orig.z -= 0.2;
	if (key == 65430)
		sc->render.cam.orig.x += 0.2;
	if (key == 65432)
		sc->render.cam.orig.x -= 0.2;
	if (key == 65434)
		sc->render.cam.orig.y += 0.2;
	if (key == 65435)
		sc->render.cam.orig.y -= 0.2;
	creat_img(sc->render, sc);
	mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win,
		sc->render.img.img, 0, 0);
	return (0);
}

int	red_button(t_scene *sc)
{
	if (sc->render.img.addr != NULL)
		mlx_destroy_image(sc->render.vars.mlx, sc->render.img.img);
	if (sc->render.vars.win != NULL)
		mlx_destroy_window(sc->render.vars.mlx, sc->render.vars.win);
	if (sc->render.vars.mlx != NULL)
		mlx_destroy_display(sc->render.vars.mlx);
	free(sc->render.vars.mlx);
	while (sc->selected->next != NULL)
	{
		sc->selected = sc->selected->next;
		free(sc->selected->prev);
	}
	free(sc->selected);
	free(sc);
	exit(0);
	return (0);
}
