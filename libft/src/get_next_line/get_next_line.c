/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:37:53 by mipang            #+#    #+#             */
/*   Updated: 2024/12/14 16:54:21 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_newline(const char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		else
			i ++;
	}
	return (0);
}

static int	append_readline(char **readline, char **buffer)
{
	char	*tmp;

	tmp = copy_buffer(*readline, *buffer);
	if (!tmp)
	{
		free(*buffer);
		if (*readline)
			free(*readline);
		*readline = NULL;
		return (0);
	}
	*readline = tmp;
	return (1);
}

static int	readloop(int fd, char **buffer, char **readline)
{
	ssize_t	read_value;

	read_value = read(fd, *buffer, BUFFER_SIZE);
	while (read_value > 0)
	{
		(*buffer)[read_value] = '\0';
		if (!append_readline(readline, buffer))
			return (0);
		if (is_newline(*readline) == 1)
			break ;
		read_value = read(fd, *buffer, BUFFER_SIZE);
	}
	if (read_value < 0)
	{
		free(*buffer);
		if (*readline)
			free(*readline);
		*readline = NULL;
		return (0);
	}
	free(*buffer);
	return (read_value > 0 || (*readline && read_value == 0));
}

static int	init_buffer(int fd, char **buffer, char **readline)
{
	if (fd < 0 || BUFFER_SIZE < 0)
	{
		if (*readline)
			free(*readline);
		*readline = NULL;
		return (0);
	}
	*buffer = malloc(BUFFER_SIZE + 1);
	if (!*buffer || BUFFER_SIZE == 0)
	{
		if (*readline)
			free(*readline);
		*readline = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*readline;
	char		*line;
	char		*buffer;

	if (!init_buffer(fd, &buffer, &readline))
		return (NULL);
	if (readloop(fd, &buffer, &readline) == 0)
		return (NULL);
	line = extra_line(readline);
	readline = update_readline(readline);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int		main()
{
	int		fd;
	char	*output;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error open file");
		return (1);
	}
	output = get_next_line(fd);
	printf("the line : %s\n", output);
	if (output == NULL)
	{
		printf("the line is: NULL\n");
		return (1);
	}
	free(output);

	output = get_next_line(fd);
    if (output == NULL) {
        printf("Second call: NULL\n");
    } else {
        printf("Second call: %s\n", output);
        free(output);
    }
	return (0);
}
*/
