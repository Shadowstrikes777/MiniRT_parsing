/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:09:07 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/03 22:20:57 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int parse_plane_coord(int *cursor, char *line, t_plane *plane, int  i);

int	parse_pcoord(int *cursor, char *line, t_plane *plane)
{
	int	i;
	int	retval;

	i = 0;
	retval = 0;
	while (i < 3)
	{
		if (i == 0)
			*cursor = 0;
		retval = parse_plane_coord(cursor, line + *cursor, plane, i);
		if (retval != 0)
			return (retval);
		i++;
	}
	retval = checkxyzlimit(plane->x, plane->y, plane->z);
	*cursor += 3;
	return (retval);
}

static int parse_plane_coord(int *cursor, char *line, t_plane *plane, int  i)
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
		plane->x = ft_atof(float_str); 
	if (i == 1)
		plane->y = ft_atof(float_str);
	else
		plane->z = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	return (0);
}

int		parse_prgb(int *cursor, char *line, t_plane *current)
{
	char	*int_str;
	int		i;
	char	endc;

	i = 0;
	endc = ',';
	while (i < 3)
	{
		if (i == 2)
			endc = '\n';
		line += (*cursor);
		if (ft_strchr(line, endc) ==  NULL)
			return (-1);
		if (check_int(line, endc) == -1)
			return (-1);
		int_str = ft_substr(line, 0, ft_strchr(line, endc) - line);
		current->rgb[i] = ft_atoi(int_str);
		*cursor = ft_strlen(int_str) + 1;
		free(int_str);
		if (current->rgb[i] < 0 || current->rgb[i] > 255)
			return (-1);
		i++;
	}
	return (0);
}
