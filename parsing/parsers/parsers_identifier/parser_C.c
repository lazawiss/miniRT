/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_C.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:20:48 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 20:09:57 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "types.h"

static int	vec3_non_zero(t_vec3 tmp)
{
	return ((tmp.x != 0) || (tmp.y != 0) || (tmp.z != 0));
}

static int	vec3_range(t_vec3 tmp, double min, double max)
{
	if ((tmp.x < min) || (tmp.x > max))
		return (0);
	if ((tmp.y < min) || (tmp.y > max))
		return (0);
	if ((tmp.z < min) || (tmp.z > max))
		return (0);
	return (1);
}

static int	parser_c(char **s, t_camera *out)
{
	char		*p;
	char		*save;
	t_camera	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.viewpoint))
		return (*s = save, 0);
	if (!parser_vec3(&p, &tmp.orientation)
		|| !vec3_non_zero(tmp.orientation)
		|| !vec3_range(tmp.orientation, -1, 1))
		return (*s = save, 0);
	if (!parser_int(&p, &tmp.fov) || tmp.fov < 0 || tmp.fov > 180)
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	tmp.set = 1;
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_c(t_scene *sc, char *p, int lineidx)
{
	if (!sc)
		return (sub_parser_error(sc, lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "C", 1))
		return (sub_parser_error(sc, lineidx, "invalid C identifier.\n"), 0);
	if (sc->camera.set)
		return (sub_parser_error(sc, lineidx,
				"duplicate camera (C) not allowed.\n"), 0);
	if (!parser_c(&p, &sc->camera))
		return (sub_parser_error(sc, lineidx, "invalid C line.\n"), 0);
	return (1);
}
