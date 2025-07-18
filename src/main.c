/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:43:36 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/17 12:30:47 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parsing(int argc, char **argv, t_data **pdata, t_file **copy);

int	main(int argc, char **argv)
{
	t_file	*copy;
	t_data	*data;
	t_scene	*sc;

	if (parsing(argc, argv, &data, &copy) != 0)
		return (1);
	sc = ft_calloc(sizeof(t_scene), 1);
	if (sc == NULL)
		return (1);
	bigbridge(data, sc);
	clean_content(copy);
	data_clean(data);
	sc->selected = sc->objs;
	render_minirt(sc);
	return (0);
}

void	usage(void)
{
	// should fix these crazy controls
	printf("light directions:\n\t end -> right\tdel -> left\tins -> up\t home");
	printf("-> down\n");
	printf("Page up/down to move up and down an object\n");
	printf("Num, / to brighten or not the scene\n");
	printf("Numerical pad for camera movement\n");
}

static int	parsing(int argc, char **argv, t_data **pdata, t_file **copy)
{
	int		fd;
	t_data	*data;
	int		err;

	fd = handle_file_error(argc, argv);
	*copy = copy_file(fd);
	remove_nls(copy);
	data = init_data();
	if (!data)
	{
		free(data);
		clean_content(*copy);
		return (1);
	}
	err = parse_file(*copy, data);
	if (err != 0)
	{
		custom_err(err);
		clean_content(*copy);
		data_clean(data);
		return (1);
	}
	*pdata = data;
	return (err);
}
