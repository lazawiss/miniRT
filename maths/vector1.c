/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:24:32 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/21 16:58:23 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* fcts to normalize */
double	dot_squared(double a)
{
	double	b;

	b = 0.0;
	b = sqrt(a);
	return (b);
}

double	dot(t_vec3 v, t_vec3 u)
{
	double	a;

	a = v.x * u.x + v.y * u.y + v.z * u.z;
	return (a);
}

t_vec3	unit_vector(t_vec3 v, double a)
{
	v.x /= a;
	v.y /= a;
	v.z /= a;
	return (v);
}

t_vec3	cross_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	out;

	out.x = a.y * b.z - a.z * b.y;
	out.y = a.z * b.x - a.x * b.z;
	out.z = a.x * b.y - a.y * b.x;
	return (out);
}

t_vec3	normalize_vec3(t_vec3 v)
{
	double	len;

	len = dot_squared(dot(v, v));
	if (len == 0.0)
		return (v);
	return (unit_vector(v, len));
}
