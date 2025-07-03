/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaevani <mmaevani@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:27:13 by mmaevani          #+#    #+#             */
/*   Updated: 2024/10/18 14:25:52 by mmaevani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getrestandline(char **stock, char **line);
static char	*ft_mitady(const char *s, int c);
static char	*readandstock(int fd, char **stock);

static char	*readandstock(int fd, char **stock)
{
	char	*buffer;
	char	*readed;
	int		rd;

	readed = *stock;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd > 0 && !ft_mitady(readed, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= -1)
		{
			free(buffer);
			return (free(readed), NULL);
		}
		buffer[rd] = '\0';
		readed = gnl_strjoin(readed, buffer);
	}
	if (buffer)
		free(buffer);
	return (readed);
}

static char	*getrestandline(char **stock, char **line)
{
	char	*rest;
	char	*readed;
	int		i;

	readed = *stock;
	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	rest = gnl_substr(readed, i + 1, gnl_strlen(readed) + 1);
	*line = gnl_substr(readed, 0, i + 1);
	free(readed);
	return (rest);
}

static char	*ft_mitady(const char *s, int c)
{
	char			*p;
	unsigned char	d;
	unsigned int	i;

	p = (char *)s;
	i = 0;
	d = c;
	if (!s)
		return (NULL);
	while (p[i] != '\0')
	{
		if ((unsigned char)p[i] == d)
			return (p + i);
		else
			i++;
	}
	if (p[i] == d)
		return (p + i);
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = readandstock(fd, &stock);
	if (!stock)
		return (NULL);
	if (*stock == '\0')
		return (free(stock), NULL);
	stock = getrestandline(&stock, &line);
	return (line);
}
