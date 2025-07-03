/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:19:05 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/03 21:50:40 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_file	*copy_file(int fd)
{
	t_file	*file_copy;

	file_copy = NULL;
	if (fill_file_copy(fd, &file_copy) == -1)
	{
		put_error("Error\nWrong file format");
		clean_content(file_copy);
		exit(1);
	}
	return (file_copy);
}

int	fill_file_copy(int fd, t_file **file_copy)
{
	char	*line;
	int		err;
	int		i;

	i = 0;
	err = 0;
	while (1)
	{
		line = get_next_line(fd);
		if ((line == NULL && i == 0)
			|| (line != NULL && line[0] == '\0'))
		{
			err = -1;
			break;
		}
		if (line == NULL && i != 0)
		{
			err = 0;
			break;
		}
		ft_lstadd_back(file_copy, ft_lstnew(line));
		i++;
	}
	return (err);
}

