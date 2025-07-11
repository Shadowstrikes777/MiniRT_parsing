/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:59 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/10 18:35:41 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_unique(char *line, t_data *data);

int	parse_file(t_file *copy, t_data *data)
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

	retval = -1;
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

int	parse_line(char *line, t_data *data)
{
	int	retval;

	retval = parse_unique(line, data);
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
	return (retval);
}
