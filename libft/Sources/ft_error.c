/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:45:42 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/13 22:45:24 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_error(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(STDERR_FILENO, msg, len);
	write(STDERR_FILENO, "\n", 1);
	return (len + 1);
}
