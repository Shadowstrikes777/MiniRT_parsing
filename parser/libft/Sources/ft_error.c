/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:45:42 by mmaevani          #+#    #+#             */
/*   Updated: 2025/07/10 18:56:46 by mmaevani         ###   ########.fr       */
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

void	custom_err(int err)
{
	if (err == -1)
		put_error("Error\nInvalid format");
	if (err == -2)
		put_error("Error\nAttempt to recreate unique object");
	if (err == -3)
		put_error("Error on Ambient light\n");
	if (err == -4)
		put_error("Error on Camera parsing\n");
	if (err == -5)
		put_error("Error on light parsing\n");
	if (err == -6)
		put_error("Error on plane parsing\n");
	if (err == -7)
		put_error("Error on sphere parsing\n");
	if (err == -8)
		put_error("Error on cylinder\n");
	if (err == 404)
		put_error("Failed to create object : Plane\n");
	if (err == 405)
		put_error("Failed to create object : Sphere\n");
	if (err == 406)
		put_error("Failed to create object : Cylinder\n");
}
