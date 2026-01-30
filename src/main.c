/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2026/01/11 15:57:56 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	has_rt_extension(const char *path)
{
	size_t	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (path[len - 3] == '.' && path[len - 2] == 'r'
		&& path[len - 1] == 't');
}

int	main(int argc, char **argv)
{
	t_scene		*s;
	const char	*rt_file_name;

	if (argc != 2 || !argv || !*argv || !has_rt_extension(argv[1]))
	{
		ft_putstr_fd("Error\ninvalid file extension\n", 2);
		return (1);
	}
	rt_file_name = argv[1];
	s = parser_rt(rt_file_name);
	if (!s)
		return (1);
	if (!create_window(s))
		close_win(s);
	draw_image(s);
	close_win(s);
	return (0);
}
