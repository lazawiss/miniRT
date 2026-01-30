/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:01:04 by mipang            #+#    #+#             */
/*   Updated: 2026/01/23 16:47:26 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parser_color(char **s, t_color *out)
{
	char	*p;
	char	*save;
	t_color	tmp;

	if (!s || !*s || !out)
		return (0);
	p = *s;
	save = *s;
	if (!parser_int(&p, &tmp.r) || tmp.r > 255 || tmp.r < 0)
		return (*s = save, 0);
	if (!expect_split(&p, ','))
		return (*s = save, 0);
	if (!parser_int(&p, &tmp.g) || tmp.g > 255 || tmp.g < 0)
		return (*s = save, 0);
	if (!expect_split(&p, ','))
		return (*s = save, 0);
	if (!parser_int(&p, &tmp.b) || tmp.b > 255 || tmp.b < 0)
		return (*s = save, 0);
	*out = tmp;
	*s = p;
	return (1);
}
