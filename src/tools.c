/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:36:06 by mihrakot          #+#    #+#             */
/*   Updated: 2025/07/15 11:38:41 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	check_min(double x, double y)
{
	if (x > y)
		return (y);
	return (x);
}

void	error(char *err)
{
	put_error("Error");
	put_error(err);
	exit(1);
}

void	big_bridge_sphere(t_data *data, t_objs **head, t_objs **last,
		t_objs **newobj)
{
	t_sphere	*sp;
	t_plane		*pl;

	sp = data->sphere;
	pl = data->plane;
	while (sp)
	{
		*newobj = alloc_obj(make_vec(0, 0, 0), make_vec(sp->x, sp->y, sp->z),
				make_vec(sp->rgb[0], sp->rgb[1], sp->rgb[2]),
				make_vec(sp->diameter, 0, 0));
		(*newobj)->type = sp->type;
		head_updater(head, newobj, last);
		sp = sp->next;
	}
	while (pl)
	{
		*newobj = alloc_obj(make_vec(pl->ox, pl->oy,
					pl->oz), make_vec(pl->x, pl->y,
					pl->z), make_vec(pl->rgb[0],
					pl->rgb[1], pl->rgb[2]), make_vec(0, 0,
					0));
		(*newobj)->type = pl->type;
		head_updater(head, newobj, last);
		pl = pl->next;
	}
}

void	head_updater(t_objs **head, t_objs **newobj, t_objs **last)
{
	if (*newobj == NULL)
	{
		error("Memory allocation failed");
		return ;
	}
	if (*head == NULL)
	{
		*head = *newobj;
	}
	else
	{
		last = head;
		while ((*last)->next != NULL)
		{
			last = &((*last)->next);
		}
		(*last)->next = *newobj;
		(*newobj)->prev = *last;
	}
}
