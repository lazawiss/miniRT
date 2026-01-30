/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:08:36 by mipang            #+#    #+#             */
/*   Updated: 2025/12/14 17:30:46 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parser_vec3(char **s, t_vec3 *out)
{
	char	*p;
	char	*save;
	t_vec3	tmp;

	if (!s || !*s || !out)
		return (0);
	save = *s;
	p = *s;
	if (!parser_double(&p, &tmp.x))
		return ((*s = save), 0);
	if (!expect_split(&p, ','))
		return ((*s = save), 0);
	if (!parser_double(&p, &tmp.y))
		return ((*s = save), 0);
	if (!expect_split(&p, ','))
		return ((*s = save), 0);
	if (!parser_double(&p, &tmp.z))
		return ((*s = save), 0);
	*out = tmp;
	*s = p;
	return (1);
}
