/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:48:12 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/13 21:47:25 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	parse_aratio(int *cursor, char *line, t_data *data)
{
	int		len;
	char	*float_str;

	len = 0;
	if (ft_strchr(line, ' ') == NULL)
		return (-1);
	if (check_float(line, ' ') == -1)
		return (-1);
	len = ft_strchr(line, ' ') - (line);
	float_str = ft_substr(line, 0, len);
	data->ambient.ratio = ft_atof(float_str);
	free(float_str);
	if (data->ambient.ratio >= 0.0 && data->ambient.ratio <= 1.0)
	{
		*cursor += len + 1;
		return (0);
	}
	return (-1);
}
