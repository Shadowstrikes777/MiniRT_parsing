/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihrakot <mihrakot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:35:52 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/12 17:07:51 by mihrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	creat_img(t_render render, t_scene *sc)
{
	render.y = HEIGHT - 1;
	while (render.y >= 0)
	{
		render.x = 0;
		while (render.x < WIDTH)
		{
			render.v = (double)render.x * 2 / WIDTH - 1;
			render.u = (double)render.y * 2 / HEIGHT - 1;
			render.ray = ray_primary(&render.cam, render.v, render.u);
			render.ray_col = ray_color(&render.ray, sc);
			my_mlx_pixel_put(&render.img, render.x, HEIGHT - 1 - render.y,
				create_rgb(render.ray_col.x, render.ray_col.y, render.ray_col.z));
			render.x++;
		}
		render.y--;
	}
}

void	render_miniRT(t_scene *sc)
{
	sc->render.cam = set_camera(sc);
	sc->render.vars.mlx = mlx_init();
	sc->render.vars.win = mlx_new_window(sc->render.vars.mlx, WIDTH, HEIGHT, "MiniRT");
	sc->render.img.img = mlx_new_image(sc->render.vars.mlx, WIDTH, HEIGHT);
	sc->render.img.addr = mlx_get_data_addr(sc->render.img.img, &sc->render.img.bits_per_pixel,
			&sc->render.img.line_length, &sc->render.img.endian);
	creat_img(sc->render, sc);
	mlx_key_hook(sc->render.vars.win, handle_key, sc);
	mlx_put_image_to_window(sc->render.vars.mlx, sc->render.vars.win, sc->render.img.img, 0, 0);
	mlx_hook(sc->render.vars.win, 17, 0, red_button, &sc->render.vars);
	mlx_loop(sc->render.vars.mlx);
}
