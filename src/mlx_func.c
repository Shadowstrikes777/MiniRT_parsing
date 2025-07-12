/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:46 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:50:52 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static void translation(t_scene *sc, int key)
{
		if (key == 65362)
	{
		sc->selected->cen.z += 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65364)
	{
		sc->selected->cen.z -= 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
		if (key == 65361)
	{
		sc->selected->cen.x += 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65363)
	{
		sc->selected->cen.x -= 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
		if (key == 65365)
	{
		sc->selected->cen.y += 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65366)
	{
		sc->selected->cen.y -= 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
}

static void light_translation(int key, t_scene *sc)
{
		if (key == 65379)
	{
		sc->light.src.z += 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65360)
	{
		sc->light.src.z -= 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
		if (key == 65535)
	{
		sc->light.src.x += 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65367)
	{
		sc->light.src.x -= 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
		if (key == 65407)
	{
		sc->light.src.y += 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65455)
	{
		sc->light.src.y -= 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
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
	light_translation(key, sc);
	objs_rotation(key, sc);
	cam_rotation(key, sc);
	if (key == 65307)
	{
		mlx_destroy_window(sc->render.vars.mlx, sc->render.vars.win);
		exit(0);
	}
	printf("pressed Key == %d\n", key);
	if (key == 65431)
	{
		sc->render.cam.orig.z += 0.2;

		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65433)
	{
		sc->render.cam.orig.z -= 0.2;
		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65430)
	{
		sc->render.cam.orig.x += 0.2;

		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65432)
	{
		sc->render.cam.orig.x -= 0.2;

		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65434)
	{
		sc->render.cam.orig.y += 0.2;

		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}
	if (key == 65435)
	{
		sc->render.cam.orig.y -= 0.2;

		creat_img(sc->render, sc);
		mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	}	
	return (0);
}

int	red_button(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
