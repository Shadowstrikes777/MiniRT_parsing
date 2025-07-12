/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:29:58 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/10 17:56:54 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_red(char *line, t_data *data, int *cursor);
static int	parse_green(char *line, t_data *data, int *cursor);
static int	parse_blue(char *line, t_data *data, int *cursor);

int	ambient_parse(char *line, t_data *data)
{
	int	cursor;

	cursor = 2;
	if (data->ambient.unique == true && data->ambient.set == true)
		return (-2);
	if (parse_aratio(&cursor, line + cursor, data) == -1)
	{
		put_error("Error\nInvalid ratio");
		return (-3);
	}
	if (parse_argb(&cursor, line, data) == -1)
	{
		put_error("Error\nInvalid color");
		return (-3);
	}
	data->ambient.set = true;
	return (0);
}

static int	parse_red(char *line, t_data *data, int *cursor)
{
	char	*int_str;

	if (ft_strchr(line, ',') == NULL)
		return (-1);
	if (check_int(line, ',') == -1)
		return (-1);
	int_str = ft_substr(line, 0, ft_strchr(line, ',') - line);
	data->ambient.rgb[0] = ft_atoi(line);
	free(int_str);
	if (data->ambient.rgb[0] < 0 || data->ambient.rgb[0] > 255)
		return (-1);
	*cursor += ft_strchr(line, ',') - line + 1;
	return (0);
}

static int	parse_green(char *line, t_data *data, int *cursor)
{
	char	*int_str;

	if (ft_strchr(line, ',') == NULL)
		return (-1);
	if (check_int(line, ',') == -1)
		return (-1);
	int_str = ft_substr(line, 0, ft_strchr(line, ',') - line);
	free(int_str);
	data->ambient.rgb[1] = ft_atoi(line);
	if (data->ambient.rgb[1] < 0 || data->ambient.rgb[1] > 255)
		return (-1);
	*cursor += ft_strchr(line, ',') - line + 1;
	return (0);
}

static int	parse_blue(char *line, t_data *data, int *cursor)
{
	char	*int_str;

	if (ft_strchr(line, '\n') == NULL)
		return (-1);
	if (check_int(line, '\n') == -1)
		return (-1);
	int_str = ft_substr(line, 0, ft_strchr(line, '\n') - line);
	free(int_str);
	data->ambient.rgb[2] = ft_atoi(line);
	if (data->ambient.rgb[2] < 0 || data->ambient.rgb[2] > 255)
		return (-1);
	*cursor += ft_strchr(line, '\n') - line + 1;
	return (0);
}

int	parse_argb(int *cursor, char *line, t_data *data)
{
	if (parse_red(line + (*cursor), data, cursor) == -1)
		return (-1);
	if (parse_green(line + (*cursor), data, cursor) == -1)
		return (-1);
	if (parse_blue(line + (*cursor), data, cursor) == -1)
		return (-1);
	return (0);
}
