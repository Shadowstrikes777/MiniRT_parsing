/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:17:19 by mmaevani          #+#    #+#             */
/*   Updated: 2024/11/11 09:51:59 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str_tab(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i++]);
	}
	free(str);
	str = NULL;
}
