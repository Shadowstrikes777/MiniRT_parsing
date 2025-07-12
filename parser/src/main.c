/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:43:36 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/12 15:29:43 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
void	print_data(t_data *data);

int	main(int argc, char **argv)
{
	int		fd;
	t_file	*copy;
	t_data	*data;
	int		err;

	err = 0;
	fd = handle_file_error(argc, argv);
	copy = copy_file(fd);
	remove_nls(&copy);
	data = init_data();
	if (!data)
	{
		free(data);
		clean_content(copy);
		return (1);
	}
	err = parse_file(copy, data);
	if (err !=  0)
	{
		custom_err(err);
		clean_content(copy);
		data_clean(data);
		return (1);
	}
	print_data(data);
	clean_content(copy);
	data_clean(data);
	return (0);
}


void	print_data(t_data *data)
{
	printf("ambient:\n");
	printf("ambient: ratio =%f r=%d g=%d b=%d\n", data->ambient.ratio, data->ambient.rgb[0], data->ambient.rgb[1], data->ambient.rgb[2]);

	printf("camera:\n");
	printf("camera: x=%f y=%f z=%f\n", data->camera.x, data->camera.y, data->camera.z);
	printf("camera: ox=%f oy=%f oz=%f\n", data->camera.ox, data->camera.oy, data->camera.oz);
	printf("camera: fov=%d\n", data->camera.fov);

	printf("lights:\n");
	printf("light: x=%f y=%f z=%f brightness=%f\n", data->light.x, data->light.y, data->light.z, data->light.brightness);
	printf("spheres:\n");
	t_sphere *sphere = data->sphere;
	while (sphere)
	{
		printf("sphere: x=%f y=%f z=%f diameter=%f\n", sphere->x, sphere->y, sphere->z, sphere->diameter);
		printf("sphere: r=%d g=%d b=%d type=%d\n", sphere->rgb[0], sphere->rgb[1], sphere->rgb[2], sphere->type);
		sphere = sphere->next;
	}
	printf("planes:\n");
	t_plane *plane = data->plane;
	while (plane)
	{
		printf("plane: x=%f y=%f z=%f\n", plane->x, plane->y, plane->z);
		printf("plane: ox=%f oy=%f oz=%f\n", plane->ox, plane->oy, plane->oz);
		printf("plane: r=%d g=%d b=%d type=%d\n", plane->rgb[0], plane->rgb[1], plane->rgb[2], plane->type);
		plane = plane->next;
	}
	printf("cylinders:\n");
	t_cylinder *cylinder = data->cylinder;
	while (cylinder)
	{
		printf("cylinder: x=%f y=%f z=%f\n", cylinder->x, cylinder->y, cylinder->z);
		printf("cylinder: ox=%f oy=%f oz=%f\n", cylinder->ox, cylinder->oy, cylinder->oz);
		printf("cylinder: diameter=%f height=%f\n", cylinder->diameter, cylinder->height);
		printf("cylinder: r=%d g=%d b=%d type=%d\n", cylinder->rgb[0], cylinder->rgb[1], cylinder->rgb[2], cylinder->type);
		cylinder = cylinder->next;
	}
}
