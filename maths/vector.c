/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:28:31 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/28 20:01:09 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	add_vector(t_vec3 v, t_vec3 u)
{
	t_vec3	w;

	w.x = v.x + u.x;
	w.y = v.y + u.y;
	w.z = v.z + u.z;
	return (w);
}

t_vec3	substract_vector(t_vec3 p, t_vec3 c)
{
	t_vec3	r;

	r.x = c.x - p.x;
	r.y = c.y - p.y;
	r.z = c.z - p.z;
	return (r);
}

t_vec3	power_vector_to_itself(t_vec3 *v)
{
	v->x *= v->x;
	v->y *= v->y;
	v->z *= v->z;
	return (*v);
}

t_vec3	power_vector_to_t(t_vec3 v, double t)
{
	t_vec3	u;

	u.x = v.x * t;
	u.y = v.y * t;
	u.z = v.z * t;
	return (u);
}

double	length_vector(double start, double finish)
{
	double	length;

	length = finish - start;
	return (length);
}
