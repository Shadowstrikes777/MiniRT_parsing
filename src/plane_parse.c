/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:31:39 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/12 14:57:38 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_plane	*get_last_plane(t_plane *plane);

static t_plane	*get_current_plane(t_data *data)
{
	t_plane	*current;

	if (data->plane)
	{
		current = get_last_plane(data->plane);
		current->next = (t_plane *)malloc(sizeof(t_plane));
		if (!current->next)
		{
			put_error("Error\nMemory allocation failed");
			return (NULL);
		}
		current = current->next;
		current->next = NULL;
		return (current);
	}
	data->plane = (t_plane *)malloc(sizeof(t_plane));
	if (!data->plane)
	{
		put_error("Error\nMemory allocation failed");
		return (NULL);
	}
	data->plane->next = NULL;
	return (data->plane);
}

static t_plane	*get_last_plane(t_plane *plane)
{
	while (plane && plane->next != NULL)
		plane = plane->next;
	return (plane);
}

int	plane_parse(char *line, t_data *data)
{
	int		cursor;
	t_plane	*current;

	cursor = 3;
	current = get_current_plane(data);
	if (!current)
		return (404);
	if (parse_pcoord(&cursor, line + cursor, current) == -1)
	{
		put_error("Error\nInvalid coordinates");
		return (-6);
	}
	if (parse_pvect(&cursor, line + cursor, current) == -1)
	{
		put_error("Error\nInvalid vector");
		return (-6);
	}
	if (parse_prgb(&cursor, line, current) == -1)
	{
		put_error("Error\nInvalid color");
		return (-6);
	}
	current->type = PL;
	return (0);
}
