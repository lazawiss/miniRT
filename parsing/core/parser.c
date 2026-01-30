/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:13:27 by mipang            #+#    #+#             */
/*   Updated: 2026/01/27 18:23:46 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	trim_space(char *str)
{
	char	*start;
	char	*end;

	if (!str)
		return ;
	start = str;
	end = start + ft_strlen(str);
	while (*start && ((*start == ' ') || *start == '\t'))
		start++;
	while (end > start && ((end[-1] == ' ') || (end[-1] == '\t')
			|| (end[-1] == '\n') || (end[-1] == '\r')))
		end--;
	*end = '\0';
	if (start != str)
		ft_memmove(str, start, end - start + 1);
}

static void	rt_final_check(t_scene *sc)
{
	if (!sc->ambient.set)
		parser_error(sc, 0, "Missing ambient\n");
	if (!sc->camera.set)
		parser_error(sc, 0, "Missing camera\n");
	if (!sc->light.set)
		parser_error(sc, 0, "Missing light\n");
}

static int	open_rt_file(t_scene *sc, const char *rt_file_name)
{
	int	fd;

	fd = open(rt_file_name, O_RDONLY);
	if (fd < 0)
	{
		parser_error(sc, 0, "Can not open .rt file\n");
		return (-1);
	}
	return (fd);
}

static void	parse_lines(t_scene *sc, int fd)
{
	char	*line;
	int		lineidx;

	lineidx = 0;
	line = get_next_line(fd);
	while (line)
	{
		lineidx++;
		trim_space(line);
		if (*line != '\0' && !dispatch(sc, line, lineidx))
		{
			free(line);
			parser_error(sc, lineidx,
				"Dispatch failure. Unknown identifier or missing space "
				"after identifier\n");
		}
		free(line);
		line = get_next_line(fd);
	}
}

t_scene	*parser_rt(const char *rt_file_name)
{
	int		fd;
	t_scene	*sc;

	sc = scene_init(NULL);
	if (!sc)
		return (NULL);
	fd = open_rt_file(sc, rt_file_name);
	if (fd < 0)
		return (NULL);
	parse_lines(sc, fd);
	if (close(fd) < 0)
		parser_error(sc, 0, "Close fd failure.\n");
	rt_final_check(sc);
	return (sc);
}
