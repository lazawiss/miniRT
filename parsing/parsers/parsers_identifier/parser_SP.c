/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_SP.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:44:57 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 20:01:59 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parser_sp(char **s, t_sphere *out)
{
	char		*p;
	char		*save;
	t_sphere	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_vec3(&p, &tmp.sp_center))
		return (*s = save, 0);
	if (!parser_double(&p, &tmp.sp_diameter) || tmp.sp_diameter <= 0.0)
		return (*s = save, 0);
	if (!parser_color(&p, &tmp.sp_color))
		return (*s = save, 0);
	if (!ensure_eol(p))
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}

int	dispatch_sp(t_scene *sc, char *p, int lineidx)
{
	t_sphere	*dst;

	if (!sc)
		return (sub_parser_error(sc, lineidx, "internal: scene is NULL.\n"));
	if (!eat_ident(&p, "sp", 2))
		return (sub_parser_error(sc, lineidx, "invalid SP identifier.\n"));
	dst = add_sphere(sc);
	if (!dst)
		return (sub_parser_error(sc, lineidx, "sphere allocation failed.\n"));
	if (!parser_sp(&p, dst))
		return (sub_parser_error(sc, lineidx, "invalid SP line.\n"));
	dst->sp_radius = dst->sp_diameter / 2.0;
	return (1);
}
