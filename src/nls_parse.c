/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nls_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:17:39 by mmaevani          #+#    #+#             */
/*   Updated: 2025/04/25 14:18:44 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	remove_nls(t_file **copy)
{
	remove_nl(copy);
	remove_space(copy);
}

void	remove_current(t_file **file_copy, t_file *current)
{
	t_file	*tmp;

	tmp = *file_copy;
	while (tmp->next != current && tmp->next)
		tmp = tmp->next;
	tmp->next = current->next;
	free(current->content);
	free(current);
}

void	remove_nl(t_file **copy)
{
	t_file	*tmp;
	int		nl;

	tmp = *copy;
	nl = 0;
	while (tmp)
	{
		if (ft_strchr((char *)tmp->content, '\n'))
		{
			if (!nl)
				nl = 1;
			tmp = tmp->next;
			while (tmp && *(char *)(tmp->content) == '\n')
			{
				remove_current(copy, tmp);
				tmp = *copy;
			}
		}
		else
		{
			nl = 0;
			tmp = tmp->next;
		}
	}
}

void	remove_space(t_file **copy)
{
	t_file	*tmp;
	char	*line;

	tmp = *copy;
	while (tmp)
	{
		line = (char *)tmp->content;
		if (remove_extra_spaces(line) == -1)
		{
			put_error("Error\nLine beginning/ending with space not allowed");
			clean_content(*copy);
			exit(1);
		}
		tmp = tmp->next;
	}
}

int	remove_extra_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == ' ')
		return (-1);
	if ((str[ft_strlen(str) - 2] == ' ' && str[ft_strlen(str) - 1] == '\n')
		|| str[ft_strlen(str) - 1] == ' ')
		return (-1);
	while (str[i])
	{
		if (str[i] != ' ' || (j > 0 && str[j - 1] != ' '))
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	if (j > 0 && str[j - 1] == ' ')
		j--;
	str[j] = '\0';
	return (1);
}
