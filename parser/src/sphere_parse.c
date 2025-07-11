/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:59:49 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/10 18:11:53 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere	*get_current_sphere(t_data *data);
static t_sphere	*get_last_sphere(t_sphere *sphere);

static t_sphere	*get_current_sphere(t_data *data)
{
	t_sphere	*current;

	if (data->sphere)
	{
		current = get_last_sphere(data->sphere);
		current->next = (t_sphere *)malloc(sizeof(t_sphere));
		if (!current->next)
		{
			put_error("Error\nMem alloc failed");
			return (NULL);
		}
		current = current->next;
		current->next = NULL;
		return (current);
	}
	data->sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!data->sphere)
	{
		put_error("Error\nMemory allocation failed");
		return (NULL);
	}
	data->sphere->next = NULL;
	return (data->sphere);
}

static t_sphere	*get_last_sphere(t_sphere *sphere)
{
	while (sphere && sphere->next != NULL)
		sphere = sphere->next;
	return (sphere);
}

int	sphere_parse(char *line, t_data *data)
{
	int			cursor;
	t_sphere	*current;

	cursor = 3;
	current = get_current_sphere(data);
	if (!current)
		return (405);
	if (parse_spcoord(&cursor, line + cursor, current) == -1)
	{
		put_error("Error\nInvalid coordinates");
		return (-7);
	}
	if (parse_diameter(&cursor, line + cursor, current) == -1)
	{
		put_error("Error\nInvalid diameter");
		return (-7);
	}
	if (parse_sprgb(&cursor, line, current) == -1)
	{
		put_error("Error\nInvalid color");
		return (-7);
	}
	return (0);
}

int	parse_diameter(int *cursor, char *line, t_sphere *current)
{
	char	*int_str;
	int		len;

	if (ft_strchr(line, ' ') == NULL)
		return (-1);
	if (check_float(line, ' ') == -1)
		return (-1);
	len = ft_strchr(line, ' ') - line;
	int_str = ft_substr(line, 0, len);
	current->diameter = ft_atof(int_str);
	*cursor += ft_strlen(int_str) + 1;
	free(int_str);
	if (current->diameter > DLIMIT || current->diameter < NDLIMIT)
		return (-1);
	return (0);
}

int	parse_sprgb(int *cursor, char *line, t_sphere *current)
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
		if (ft_strchr(line, endc) == NULL)
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
