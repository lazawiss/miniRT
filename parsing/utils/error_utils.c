/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:10 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 20:06:28 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"

int	sub_parser_error(t_scene *sc, int lineidx, const char *msg)
{
	(void)sc;
	ft_printf("Error\n");
	ft_printf("line no.%d : %s", lineidx, msg);
	get_next_line(-1);
	return (0);
}

void	parser_error(t_scene *sc, int lineidx, const char *msg)
{
	ft_printf("Error\n");
	ft_printf("line no.%d : %s", lineidx, msg);
	get_next_line(-1);
	close_win(sc);
	exit(EXIT_FAILURE);
}
