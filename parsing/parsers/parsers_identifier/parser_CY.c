/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_CY.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:58:36 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 20:15:43 by mipang           ###   ########.fr       */
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

static int	parser_cy(char **s, t_cylinder *out)
{
	char		*p;
	char		*save;
	t_cylinder	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.cy_center))
		return (*s = save, 0);
	if (!parser_vec3(&p, &tmp.cy_vector)
		|| !vec3_range(tmp.cy_vector, -1, 1)
		|| !vec3_non_zero(tmp.cy_vector))
		return (*s = save, 0);
	if (!parser_double(&p, &tmp.cy_diameter) || tmp.cy_diameter <= 0.0)
		return (*s = save, 0);
	if (!parser_double(&p, &tmp.cy_height) || tmp.cy_height <= 0.0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.cy_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_cy(t_scene *sc, char *p, int lineidx)
{
	t_cylinder	*dst;

	if (!sc)
		return (sub_parser_error(sc, lineidx, "internal: scene is NULL.\n"), 0);
	if (!eat_ident(&p, "cy", 2))
		return (sub_parser_error(sc, lineidx,
				"invalid CY identifier.\n"), 0);
	dst = add_cylinder(sc);
	if (!dst)
		return (sub_parser_error(sc, lineidx,
				"cylinder allocation failed.\n"), 0);
	if (!parser_cy(&p, dst))
		return (sub_parser_error(sc, lineidx, "invalid CY line.\n"), 0);
	return (1);
}
