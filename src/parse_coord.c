/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:26:07 by mmaevani          #+#    #+#             */
/*   Updated: 2025/03/25 17:19:52 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_coord(int *cursor, char *line, t_data *data)
{
	int	i;
	int retval;
	
	i = 0;
	retval = 0;
	while (i < 3)
	{
		if ( i == 0)
			*cursor = 0;
		retval = parse_camera_coord(cursor, line + *cursor, &data->camera, i);
		if (retval != 0)
			return (retval);
		i++;
	}
	retval = checkxyzlimit(data->camera.x, data->camera.y, data->camera.z);
	*cursor += 2;
	return (retval);
}

// -50.0,0,20
int parse_camera_coord(int *cursor, char *line, t_camera *camera, int i)
{
	char	*float_str;
	int		len;
	char	end;

	len = 0;
	if (i < 2)
		end = ',';
	else
		end = ' ';
	if (ft_strchr(line, end) == NULL)
		return (-1);
	if (check_float(line, end) == -1)
		return (-1);
	len = ft_strchr(line, end) - line;
	float_str = ft_substr(line, 0, len);
	if (i == 0)
		camera->x = ft_atof(float_str); 
	if (i == 1)
		camera->y = ft_atof(float_str);
	else
		camera->z = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	return (0);
}

int	checkxyzlimit(int x, int y, int z)
{
	if 	(x >= POS_XYZLIMIT || x <= NEG_XYZLIMIT ||
		y >= POS_XYZLIMIT || y <= NEG_XYZLIMIT ||
		z >= POS_XYZLIMIT || z <= NEG_XYZLIMIT)
		return (-1);
	return (0);
}
