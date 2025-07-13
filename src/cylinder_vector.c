/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:46:52 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/13 22:22:03 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_cylinder	*get_last_cylinder(t_cylinder *cylinder);

int	parse_cyrgb(int *cursor, char *line, t_cylinder *current)
{
	char	*int_str;
	int		i;
	char	end;

	i = 0;
	end = ',';
	while (i < 3)
	{
		if (i == 2)
			end = '\n';
		line += (*cursor);
		if (ft_strchr(line, end) == NULL)
			return (-1);
		if (check_int(line, end) == -1)
			return (-1);
		int_str = ft_substr(line, 0, ft_strchr(line, end) - line);
		current->rgb[i] = ft_atoi(int_str);
		*cursor = ft_strlen(int_str) + 1;
		free(int_str);
		if (current->rgb[i] < 0 || current->rgb[i] > 255)
			return (-1);
		i++;
	}
	return (0);
}

t_cylinder	*get_current_cylinder(t_data *data)
{
	t_cylinder	*current;

	if (data->cylinder)
	{
		current = get_last_cylinder(data->cylinder);
		current->next = (t_cylinder *)malloc(sizeof(t_cylinder));
		if (!current->next)
		{
			put_error("Error\nMemory allocation failed");
			return (NULL);
		}
		current = current->next;
		current->next = NULL;
		return (current);
	}
	data->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!data->cylinder)
	{
		put_error("Error\nMemory allocation failed");
		return (NULL);
	}
	data->cylinder->next = NULL;
	return (data->cylinder);
}



static t_cylinder	*get_last_cylinder(t_cylinder *cylinder)
{
	while (cylinder && cylinder->next != NULL)
		cylinder = cylinder->next;
	return (cylinder);
}
