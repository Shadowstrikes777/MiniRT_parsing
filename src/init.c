/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:47:51 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/02 17:46:22 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		put_error("Error\nmalloc of data failed");
		return (NULL);
	}
	ft_bzero(&data->ambient, sizeof(t_amb));
	ft_bzero(&data->camera, sizeof(t_camera));
	ft_bzero(&data->light, sizeof(t_light));
	data->plane = NULL;
	data->sphere = NULL;
	data->cylinder = NULL;
	data->ambient.unique = true;
	data->camera.unique = true;
	data->light.unique = true;
	return (data);
}
