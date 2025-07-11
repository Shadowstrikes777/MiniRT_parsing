/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:43:36 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/10 18:16:53 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	custom_err(err);
	clean_content(copy);
	data_clean(data);
	return (0);
}
