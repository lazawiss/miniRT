/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_A.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:39:17 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 20:10:26 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	parser_a(char **s, t_ambient *out)
{
	char		*p;
	char		*save;
	t_ambient	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_double(&p, &tmp.ratio) || tmp.ratio > 1.0 || tmp.ratio < 0.0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.ambient_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	tmp.set = 1;
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_a(t_scene *sc, char *p, int lineidx)
{
	if (!sc)
		return (sub_parser_error(sc, lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "A", 1))
		return (sub_parser_error(sc, lineidx, "invalid A identifier.\n"), 0);
	if (sc->ambient.set)
		return (sub_parser_error(sc, lineidx,
				"duplicate ambient (A) not allowed.\n"), 0);
	if (!parser_a(&p, &sc->ambient))
		return (sub_parser_error(sc, lineidx, "invalid A line.\n"), 0);
	return (1);
}
