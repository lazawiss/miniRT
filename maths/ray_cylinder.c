/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/20 12:00:00 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	cylinder_side_root(t_cy_hit *h, double t, t_vec3 *n)
{
	t_vec3	p;
	t_vec3	normal;
	double	y;
	double	len;

	if (t <= h->s->ray_min || t >= h->s->ray_max)
		return (-1.0);
	y = dot(h->oc, h->axis) + dot(h->direction, h->axis) * t;
	if (fabs(y) > h->half_h)
		return (-1.0);
	if (n)
	{
		p = add_vector(h->oc, power_vector_to_t(h->direction, t));
		normal = substract_vector(power_vector_to_t(h->axis,
					dot(p, h->axis)), p);
		len = dot_squared(dot(normal, normal));
		if (len == 0.0)
			return (-1.0);
		normal = unit_vector(normal, len);
		if (dot(h->direction, normal) > 0.0)
			normal = power_vector_to_t(normal, -1.0);
		*n = normal;
	}
	return (t);
}

static double	cylinder_side(t_cy_hit *h, t_vec3 *n)
{
	double	params[3];
	double	disc;
	double	best;
	t_vec3	tmp_n;
	double	t;

	cy_side_params(h, params);
	disc = params[1] * params[1] - 4.0 * params[0] * params[2];
	if (fabs(params[0]) < 1e-6 || disc < 0.0)
		return (-1.0);
	disc = sqrt(disc);
	best = -1.0;
	t = (-params[1] - disc) / (2.0 * params[0]);
	cy_update_hit(cylinder_side_root(h, t, &tmp_n), tmp_n, &best, n);
	t = (-params[1] + disc) / (2.0 * params[0]);
	cy_update_hit(cylinder_side_root(h, t, &tmp_n), tmp_n, &best, n);
	return (best);
}

static double	cylinder_cap(t_cy_hit *h, double sign, t_vec3 *n)
{
	double	d_dot_v;
	double	oc_dot_v;
	double	t;

	d_dot_v = dot(h->direction, h->axis);
	if (fabs(d_dot_v) < 1e-6)
		return (-1.0);
	oc_dot_v = dot(h->oc, h->axis);
	t = (sign * h->half_h - oc_dot_v) / d_dot_v;
	if (cy_cap_hit(h, t, sign, n) < 0)
		return (-1.0);
	return (t);
}

double	ray_cylinder(t_scene *s, t_vec3 direction, t_cylinder *cy, t_vec3 *n)
{
	t_cy_hit	h;
	t_vec3		tmp_n;
	double		len;
	double		best;

	h.axis = cy->cy_vector;
	len = dot_squared(dot(h.axis, h.axis));
	if (len == 0.0)
		return (-1.0);
	h.axis = unit_vector(h.axis, len);
	h.radius = cy->cy_diameter * 0.5;
	h.half_h = cy->cy_height * 0.5;
	h.oc = substract_vector(cy->cy_center, s->camera.viewpoint);
	h.s = s;
	h.direction = direction;
	best = -1.0;
	cy_update_hit(cylinder_side(&h, &tmp_n), tmp_n, &best, n);
	cy_update_hit(cylinder_cap(&h, 1.0, &tmp_n), tmp_n, &best, n);
	cy_update_hit(cylinder_cap(&h, -1.0, &tmp_n), tmp_n, &best, n);
	return (best);
}
