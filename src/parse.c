/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:59 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/04 17:43:11 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_unique(char *line, t_data *data);

int		parse_file(t_file *copy,t_data *data)
{
	t_file	*tmp;
	int		retval;

	tmp = copy;
	while (tmp)
	{
		retval = parse_line((char *)tmp->content, data);
		if (retval != 0)
			return (retval);
		tmp = tmp->next;
	}
	return (retval);
}


static int	parse_unique(char *line, t_data *data)
{
	int	retval;

	retval = 0;
	if (ft_strncmp(line, "A ", 2) == 0)
	{
		retval = ambient_parse(line, data);
		return (retval);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		retval = camera_parse(line, data);
		return (retval);
	}
	if (ft_strncmp(line, "L ", 2) == 0)
	{
		retval = light_parse(line, data);
		return (retval);
	}
	return (retval);
}
// should add a verification of return value ft, -2 for unique errors, else for -1 parsing error

int	parse_line(char *line, t_data *data)
{
	int retval;

	retval = -1;
	retval = parse_unique(line, data);
	if (retval != 0)
		return (retval);
	if (ft_strncmp(line, "pl ", 3) == 0)
	{
		retval = plane_parse(line, data);
		return (retval);
	}
	if (ft_strncmp(line, "sp ", 3) == 0)
	{
		retval = sphere_parse(line, data);
		return (retval);
	}
	if (ft_strncmp(line, "cy ", 3) == 0)
	{
		retval = cylinder_parse(line, data);
		return (retval);
	}
	return (0);
}
