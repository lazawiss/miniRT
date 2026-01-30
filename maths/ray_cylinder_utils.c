/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:20:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/28 19:39:29 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	cy_perp(t_vec3 v, t_vec3 axis)
{
	return (substract_vector(power_vector_to_t(axis, dot(v, axis)), v));
}

void	cy_side_params(t_cy_hit *h, double params[3])
{
	t_vec3	d_perp;
	t_vec3	oc_perp;

	d_perp = cy_perp(h->direction, h->axis);
	oc_perp = cy_perp(h->oc, h->axis);
	params[0] = dot(d_perp, d_perp);
	params[1] = 2.0 * dot(d_perp, oc_perp);
	params[2] = dot(oc_perp, oc_perp) - (h->radius * h->radius);
}

void	cy_update_hit(double t, t_vec3 hit_n, double *best, t_vec3 *n)
{
	if (t > 0.0 && (*best < 0.0 || t < *best))
	{
		*best = t;
		if (n)
			*n = hit_n;
	}
}

int	cy_cap_hit(t_cy_hit *h, double t, double sign, t_vec3 *n)
{
	t_vec3	p;
	t_vec3	p_perp;
	double	dist2;

	if (t <= h->s->ray_min || t >= h->s->ray_max)
		return (-1.0);
	if (n)
		*n = power_vector_to_t(h->axis, sign);
	p = add_vector(h->oc, power_vector_to_t(h->direction, t));
	p_perp = substract_vector(power_vector_to_t(h->axis, dot(p, h->axis)),
			p);
	dist2 = dot(p_perp, p_perp);
	if (dist2 > h->radius * h->radius)
		return (-1.0);
	if (n && dot(h->direction, *n) > 0.0)
		*n = power_vector_to_t(*n, -1.0);
	return (1);
}
