/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_L.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:34:59 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 20:08:52 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	parser_l(char **s, t_light *out)
{
	char	*p;
	char	*save;
	t_light	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.pos))
		return (*s = save, 0);
	if (!parser_double(&p, &tmp.ratio) || tmp.ratio < 0.0 || tmp.ratio > 1.0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.light_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	tmp.set = 1;
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_l(t_scene *sc, char *p, int lineidx)
{
	if (!sc)
		return (sub_parser_error(sc, lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "L", 1))
		return (sub_parser_error(sc, lineidx, "invalid L identifier.\n"), 0);
	if (sc->light.set)
		return (sub_parser_error(sc, lineidx,
				"duplicate light (L) not allowed.\n"), 0);
	if (!parser_l(&p, &sc->light))
		return (sub_parser_error(sc, lineidx, "invalid L line.\n"), 0);
	return (1);
}
