/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:42:06 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/25 14:15:01 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_orientation(int *cursor, char *line, t_data *data)
{
	int	i;
	int	retval;
	int	curs;

	i = 0;
	retval = 0;
	curs = 0;
	while (i < 3)
	{
		retval = parse_camorientation(&curs, line + curs, &data->camera, i);
		if (retval != 0)
			return (retval);
		i++;
	}
	retval = valid_orientation(data->camera.ox, data->camera.oy,
			data->camera.oz);
	*cursor += curs;
	return (retval);
}

int	parse_camorientation(int *cursor, char *line, t_camera *camera, int i)
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
		camera->ox = ft_atof(float_str);
	if (i == 1)
		camera->oy = ft_atof(float_str);
	else
		camera->oz = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	return (0);
}

int	valid_orientation(float x, float y, float z)
{
	if (x < -1.0 || x > 1.0 || y < -1.0 || y > 1.0 || z < -1.0 || z > 1.0)
		return (-1);
	return (0);
}
