/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:43:36 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/04 18:21:09 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_file	*copy;
	t_data	*data;

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
	if (parse_file(copy, data) == -2)
		put_error("Error\nUnique elements declared more than once");
	clean_content(copy);
	data_clean(data);
	return (0);
}
