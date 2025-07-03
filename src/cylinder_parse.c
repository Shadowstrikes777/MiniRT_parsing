/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:53:59 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/04 18:06:49 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_cylinder_coord(int *cursor, char *line, t_cylinder *current, int i);
static int	parse_cyorientation(int *cursor, char *line, t_cylinder *current, int i);

int	parse_cycoord(int *cursor, char *line, t_cylinder *current)
{
	int	i;
	int	retval;

	i = 0;
	retval = 0;
	while (i < 3)
	{
		if (i == 0)
			*cursor = 0;
		retval = parse_cylinder_coord(cursor, line + *cursor, current, i);
		if (retval != 0)
			return (retval);
		i++;
	}
	retval = checkxyzlimit(current->x, current->y, current->z);
	*cursor += 3;
	return (retval);
}

static int	parse_cylinder_coord(int *cursor, char *line, t_cylinder *current, int i)
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
		current->x = ft_atof(float_str); 
	if (i == 1)
		current->y = ft_atof(float_str);
	else
		current->z = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	return (0);
}

int	cylinder_parse(char *line, t_data *data)
{
	int			cursor;
	t_cylinder	*current;

	cursor = 3;
	current = get_current_cylinder(data);
	if (!current)
		return (-1);
	if (parse_cycoord(&cursor, line + cursor, current) == -1)
	{
		put_error("Error\nInvalid coordinates");
		return (-1);
	}
	if (parse_cyvect(&cursor, line + cursor, current) == -1)
	{
		put_error("Error\nInvalid cy vector");
		return (-1);
	}
	if (parse_cymeasures(&cursor, line + cursor, current) == -1)
	{
		put_error("Error\nInvalid cy radius");
		return (-1);
	}
	if (parse_cyrgb(&cursor, line, current) == -1)
	{
		put_error("Error\nInvalid cy color");
		return (-1);
	}
	return (0);
}

int	parse_cyvect(int *cursor, char *line, t_cylinder *current)
{
	int	i;
	int	retval;
	int	curs;

	i = 0;
	retval = 0;
	curs = 0;
	while (i < 3)
	{
		retval = parse_cyorientation(&curs, line + curs, current, i);
		if (retval != 0)
			return (retval);
		i++;
	}
	retval = valid_orientation(current->ox, current->oy, current->oz);
	*cursor += curs;
	return (retval);
}

static int	parse_cyorientation(int *cursor, char *line, t_cylinder *current, int i)
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
		current->ox = ft_atof(float_str);
	if (i == 1)
		current->oy = ft_atof(float_str);
	else
		current->oz = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	return (0);
}
