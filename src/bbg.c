/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:31:14 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/12 18:49:51 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_uniquess(t_data **pdata, t_scene **psc);

static void make_list(t_objs **head, t_data *data)
{
	t_sphere *stmp;
    t_plane	*ptmp;
    t_cylinder *ctmp;
	
	if (data == NULL)
        return;
    stmp = data->sphere;
    ptmp = data->plane;
    ctmp = data->cylinder;
    while (stmp)
    {
        t_objs *newobj = alloc_obj(make_vec(0,0,0),
                make_vec(stmp->x, stmp->y, stmp->z),
                make_vec(stmp->rgb[0], stmp->rgb[1], stmp->rgb[2]),
                make_vec(stmp->diameter,0,0), stmp->type);
        if (newobj == NULL)
        {
            ft_err("Memory allocation failed");
            return;
        }
        if (*head == NULL)
        {
            *head = newobj;
        }
		else
		{
			t_objs **last = head;
			while ((*last)->next != NULL)
			{
				last = &((*last)->next);
			}
			(*last)->next = newobj;
			newobj->prev = *last;
		}
        stmp = stmp->next;
    }
	while (ptmp)
	{
		t_objs *newobj = alloc_obj(make_vec(ptmp->ox, ptmp->oy, ptmp->oz),
				make_vec(ptmp->x, ptmp->y, ptmp->z),
				make_vec(ptmp->rgb[0], ptmp->rgb[1], ptmp->rgb[2]),
					make_vec(0,0,0), ptmp->type);
 		if (newobj == NULL)
    	    {
    	        ft_err("Memory allocation failed");
    	        return;
    	    }
    	    if (*head == NULL)
    	    {
    	        *head = newobj;
    	    }
    	    else
    	    {
    	        t_objs **last = head;
    	        while ((*last)->next != NULL) {
    	            last = &((*last)->next);
    	        }
    	        (*last)->next = newobj;
    	        newobj->prev = *last;
    	    }
    	    ptmp = ptmp->next;
	}
	while (ctmp)
	{
		t_objs *newobj = alloc_obj(make_vec(ctmp->ox, ctmp->oy, ctmp->oz),
				make_vec(ctmp->x, ctmp->y, ctmp->z),
				make_vec(ctmp->rgb[0], ctmp->rgb[1], ctmp->rgb[2]),
				make_vec(ctmp->diameter, ctmp->height, 0), ctmp->type);
		if (newobj == NULL)
		{
		    ft_err("Memory allocation failed");
		    return;
		}
		if (*head == NULL)
		{
		    *head = newobj;
		}
		else
		{
			t_objs **last = head;
			while ((*last)->next != NULL) {
				last = &((*last)->next);
			}
			(*last)->next = newobj;
			newobj->prev = *last;
		}
		ctmp = ctmp->next;
	}
}


t_objs *alloc_obj(t_vec dir, t_vec center, t_vec color, t_vec d, int type)
{
	t_objs *new = malloc(sizeof(t_objs));
	if (new == NULL)
		return NULL;
	new->type = type;
	new->col = color;
	new->cen = center;
	new->dir = dir;
	new->p = d;
	new->next = NULL;
    new->prev = NULL;
	return(new);
}


static void	init_uniquess(t_data **pdata, t_scene **psc)
{
	t_data	*data = *pdata;
	t_scene	*sc	= *psc;
	sc->amb.col.x = data->ambient.rgb[0];
	sc->amb.col.y = data->ambient.rgb[1];
	sc->amb.col.z = data->ambient.rgb[2];
	sc->amb.ratio = data->ambient.ratio;
	sc->amb.count = 1;
	sc->cam.cen.x = data->camera.x;
	sc->cam.cen.y = data->camera.y;
	sc->cam.cen.z = data->camera.z;
	sc->cam.dir.x = data->camera.ox;
	sc->cam.dir.y = data->camera.oy;
	sc->cam.dir.z = data->camera.oz;
	sc->cam.fov = data->camera.fov;
	sc->cam.count = 1;
	sc->light.src.x = data->light.x;
	sc->light.src.y = data->light.y;
	sc->light.src.z = data->light.z;
	sc->light.ratio = data->light.brightness;
	sc->light.col.x = 255;
	sc->light.col.y = 255;
	sc->light.col.y = 255;
}
void	bbg(t_data *data, t_scene *sc)
{
	init_uniquess(&data, &sc);
	make_list(&sc->objs, data);
}

