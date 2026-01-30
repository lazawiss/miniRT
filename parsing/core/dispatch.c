/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:57:17 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 18:46:25 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	dispatch(t_scene *sc, char *line, int lineidx)
{
	char	*str;

	str = line;
	while (is_space(*str))
		str++;
	if (*str == '\0' || *str == '#')
		return (1);
	else if (str[0] == 'A' && is_space(str[1]))
		return (dispatch_a(sc, str, lineidx));
	else if (str[0] == 'C' && is_space(str[1]))
		return (dispatch_c(sc, str, lineidx));
	else if (str[0] == 'L' && is_space(str[1]))
		return (dispatch_l(sc, str, lineidx));
	else if (str[0] == 's' && str[1] == 'p' && is_space(str[2]))
		return (dispatch_sp(sc, str, lineidx));
	else if (str[0] == 'p' && str[1] == 'l' && is_space(str[2]))
		return (dispatch_pl(sc, str, lineidx));
	else if (str[0] == 'c' && str[1] == 'y' && is_space(str[2]))
		return (dispatch_cy(sc, str, lineidx));
	return (0);
}
