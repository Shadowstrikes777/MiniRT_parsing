/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:48:29 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/14 16:26:31 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	data_clean(t_data *data)
{
	t_plane		*tmp;
	t_sphere	*tmp2;
	t_cylinder	*tmp3;

	while (data && data->plane)
	{
		tmp = data->plane->next;
		free(data->plane);
		data->plane = tmp;
	}
	data->plane = NULL;
	while (data && data->sphere)
	{
		tmp2 = data->sphere->next;
		free(data->sphere);
		data->sphere = tmp2;
	}
	data->sphere = NULL;
	while (data && data->cylinder)
	{
		tmp3 = data->cylinder->next;
		free(data->cylinder);
		data->cylinder = tmp3;
	}
	free(data);
}

void	clean_content(t_file *rt)
{
	t_file	*tmp;

	while (rt)
	{
		tmp = rt->next;
		free(rt->content);
		free(rt);
		rt = tmp;
	}
}
