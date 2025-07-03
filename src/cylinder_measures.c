/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_measures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:08:12 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/04 17:52:56 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
static int	cy_height(int *cursor, char *line, t_cylinder *current);

int	parse_cymeasures(int *cursor, char *line, t_cylinder *current)
{
	char	*float_str;
	int		len;
	char	end;
	int		retval;

	retval = 0;
	len = 0;
	end = ' ';
	if (ft_strchr(line, end) == NULL)
		return (-1);
	if (check_float(line, end) == -1)
		return (-1);
	len = ft_strchr(line, end) - line;
	float_str = ft_substr(line, 0, len);
	current->diameter = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	retval = cy_height(cursor, line, current);
	if (retval == -1 || current->diameter > DLIMIT
		|| current->diameter < NDLIMIT)
		return (-1);
	return (0);
}

static int	cy_height(int *cursor, char *line, t_cylinder *current)
{
	char	*float_str;
	int		len;
	char	end;

	len = 0;
	end = ' ';
	if (ft_strchr(line, end) == NULL)
		return (-1);
	if (check_float(line, end) == -1)
		return (-1);
	len = ft_strchr(line, end) - line;
	float_str = ft_substr(line, 0, len);
	current->height = ft_atof(float_str);
	*cursor += len + 1;
	free(float_str);
	if (current->height < 1 || current->height > DLIMIT)
		return (-1);
	return (0);
}
