/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:16:46 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/25 14:20:30 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	camera_parse(char *line, t_data *data)
{
	int	cursor;

	cursor = 2;
	if (data->camera.unique && data->camera.set)
		return (-2);
	if (parse_coord(&cursor, line + cursor, data) == -1)
	{
		put_error("Error\nInvalid coordinates");
		return (-1);
	}
	if (parse_orientation(&cursor, line + cursor, data) == -1)
	{
		put_error("Error\nInvalid orientation vector");
		return (-1);
	}
	if (parse_fov(&cursor, line, data) == -1)
	{
		put_error("Error\nInvalid Field Of View");
		return (-1);
	}
	data->camera.set = true;
	return (0);
}

//∗ FOV: Horizontal field of view in degrees in range [0,180]: 70
int	parse_fov(int *cursor, char *line, t_data *data)
{
	int		len;
	char	endchar;

	endchar = '\n';
	len = 0;
	if (ft_strchr(line + *cursor, endchar) == NULL || check_int(line + *cursor,
			endchar) == -1)
		return (-1);
	len = ft_strchr(line + *cursor, endchar) - line;
	data->camera.fov = ft_atoi(line + *cursor);
	if (data->camera.fov < 0 || data->camera.fov > 180)
		return (-1);
	*cursor += len + 1;
	return (0);
}
