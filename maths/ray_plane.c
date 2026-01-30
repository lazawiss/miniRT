/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/28 16:36:59 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ray_plane(t_scene *s, t_vec3 direction, t_plane *pl, t_vec3 *n)
{
	const double	eps = 1e-6;
	t_vec3			normal;
	t_vec3			diff;
	double			denom;
	double			t;

	normal = normalize_vec3(pl->pl_vector);
	denom = dot(direction, normal);
	if (fabs(denom) < eps)
		return (-1.0);
	diff = substract_vector(s->camera.viewpoint, pl->pl_point);
	t = dot(diff, normal) / denom;
	if (t <= s->ray_min || t >= s->ray_max)
		return (-1.0);
	if (n && dot(direction, normal) > 0.0)
		normal = power_vector_to_t(normal, -1.0);
	if (n)
		*n = normal;
	return (t);
}
