/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcoord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:29:03 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/03 22:35:34 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_spcoord(int *cursor, char *line, t_sphere *current)
{
	int	i;
	int	retval;

	i = 0;
	retval = 0;
	while (i < 3)
	{
		if (i == 0)
			*cursor = 0;
		retval = parse_sphere_coord(cursor, line + *cursor, current, i);
		if (retval != 0)
			return (retval);
		i++;
	}
	retval = checkxyzlimit(current->x, current->y, current->z);
	*cursor += 3;
	return (retval);
}

int	parse_sphere_coord(int *cursor, char *line, t_sphere *current, int i)
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
