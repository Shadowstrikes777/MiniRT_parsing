/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigbridge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:31:14 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/14 16:31:49 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_uniquess(t_data **pdata, t_scene **psc);

static void	make_list(t_objs **head, t_data *data)
{
	t_objs		*newobj;
	t_objs		**last;
	t_cylinder	*cy;

	cy = data->cylinder;
	if (data == NULL)
		return ;
	last = NULL;
	big_bridge_sphere(data, head, last, &newobj);
	while (cy)
	{
		newobj = alloc_obj(make_vec(cy->ox, cy->oy,
					cy->oz), make_vec(cy->x,
					cy->y, cy->z),
				make_vec(cy->rgb[0], cy->rgb[1],
					cy->rgb[2]), make_vec(cy->diameter,
					cy->height, 0));
		newobj->type = cy->type;
		head_updater(head, &newobj, last);
		cy = cy->next;
	}
}

t_objs	*alloc_obj(t_vec dir, t_vec center, t_vec color, t_vec d)
{
	t_objs	*new;

	new = malloc(sizeof(t_objs));
	if (new == NULL)
		return (NULL);
	new->col = color;
	new->cen = center;
	new->dir = dir;
	new->p = d;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	init_uniquess(t_data **pdata, t_scene **psc)
{
	t_data	*data;
	t_scene	*sc;

	data = *pdata;
	sc = *psc;
	sc->amb.col.x = data->ambient.rgb[0];
	sc->amb.col.y = data->ambient.rgb[1];
	sc->amb.col.z = data->ambient.rgb[2];
	sc->amb.ratio = data->ambient.ratio;
	sc->amb.count++;
	sc->cam.cen.x = data->camera.x;
	sc->cam.cen.y = data->camera.y;
	sc->cam.cen.z = data->camera.z;
	sc->cam.dir.x = data->camera.ox;
	sc->cam.dir.y = data->camera.oy;
	sc->cam.dir.z = data->camera.oz;
	sc->cam.fov = data->camera.fov;
	sc->cam.count++;
	sc->light.src.x = data->light.x + 0.0001;
	sc->light.src.y = data->light.y + 0.001;
	sc->light.src.z = data->light.z + 0.0001;
	sc->light.ratio = data->light.brightness;
	sc->light.col.x = 255;
	sc->light.col.y = 255;
	sc->light.col.z = 255;
}

void	bigbridge(t_data *data, t_scene *sc)
{
	init_uniquess(&data, &sc);
	make_list(&sc->objs, data);
}
