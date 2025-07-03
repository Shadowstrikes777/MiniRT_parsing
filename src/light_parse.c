/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:09:34 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/04 18:21:58 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_brightness(int *cursor, char *line, t_data *data);

int	light_parse(char *line, t_data *data)
{
	int	cursor;

	cursor = 2;
	if (data->light.unique &&
		data->light.set)
		return (-2);
	if (parse_lcoord(&cursor, line + cursor, data) == -1)
	{
		put_error("Error\nInvalid coordinates");
		return (-1);
	}
	if (parse_brightness(&cursor, line + cursor, data) == -1)
	{
		put_error("Error\nInvalid brightness");
		return (-1);
	}
	data->light.set = true;
	return (0);
}

int	parse_lcoord(int *cursor, char *line, t_data *data)
{
	int	i;
	int retval;
	
	i = 0;
	retval = 0;
	while (i < 3)
	{
		if ( i == 0)
			*cursor = 0;
		retval = parse_light_coord(cursor, line + *cursor, &data->light, i);
		if (retval != 0)
			return (retval);
		i++;
	}
	retval = checkxyzlimit(data->light.x, data->light.y, data->light.z);
	*cursor += 2;
	return (retval);
}

int	parse_light_coord(int *cursor, char *line, t_light *light, int i)
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
		light->x = ft_atof(float_str); 
	if (i == 1)
		light->y = ft_atof(float_str);
	else
		light->z = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	return (0);
}

static int	parse_brightness(int *cursor, char *line, t_data *data)
{
	char	*float_str;
	int		len;

	len = 0;
	if (ft_strchr(line, '\n') == NULL)
		return (-1);
	if (check_float(line, '\n') == -1)
		return (-1);
	len = ft_strchr(line, '\n') - line;
	float_str = ft_substr(line, 0, len);
	data->light.brightness = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	return (0);
}
