/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:20:33 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/15 11:41:09 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_file_error(int argc, char **argv)
{
	char	*filename;
	int		retval;

	if (argc != 2)
	{
		put_error("Error\nNot enough or too much argument, quitting");
		exit(1);
	}
	filename = argv[1];
	if (check_file_ext(filename, ".rt") == 1)
	{
		retval = open(filename, O_RDONLY);
		if (retval == -1)
		{
			put_error("Error\nUnable to open file");
			exit(1);
		}
		return (retval);
	}
	else
	{
		put_error("Error\nWrong file extension");
		exit(1);
	}
}

int	check_file_ext(char *str, char *sub)
{
	char	*tmp;

	tmp = ft_strrchr(str, '.');
	if (ft_strcmp(str, ".rt") == 0)
	{
		put_error("Error\nWrong filename");
		exit(1);
	}
	if (*str == '\0')
	{
		put_error("Error\nEmpty filename not allowed");
		exit(1);
	}
	if (!tmp)
	{
		put_error("Error\nFilename must have a file extension.");
		exit(1);
	}
	if (ft_strcmp(tmp, sub) != 0)
	{
		put_error("Error\nWrong file extension.");
		exit(1);
	}
	return (1);
}
