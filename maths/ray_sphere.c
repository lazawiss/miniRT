/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/28 20:03:05 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_front_face(t_vec3 direction, t_vec3 normal)
{
	return (dot(direction, normal) <= 0.0);
}

static t_vec3	calculate_normal_sphere(t_scene *s, t_vec3 direction,
	t_sphere *sp, double t)
{
	t_vec3	ray_sp;
	t_vec3	ray_sp_final;
	double	c;

	ray_sp = power_vector_to_t(direction, t);
	ray_sp_final = add_vector(s->camera.viewpoint, ray_sp);
	ray_sp_final = substract_vector(ray_sp_final, sp->sp_center);
	ray_sp_final = unit_vector(ray_sp_final, sp->sp_radius);
	c = dot_squared(dot(ray_sp_final, ray_sp_final));
	ray_sp_final = unit_vector(ray_sp_final, c);
	if (!is_front_face(direction, ray_sp_final))
		ray_sp_final = unit_vector(ray_sp_final, -1);
	return (ray_sp_final);
}

static double	sphere_root(t_scene *s, t_vec3 direction, t_vec3 oc, double r)
{
	double	disc;
	double	t;

	s->a = dot(direction, direction);
	s->b = dot(oc, direction);
	s->c = dot(oc, oc) - (r * r);
	disc = s->b * s->b - (s->a * s->c);
	if (disc < 0.0)
		return (-1.0);
	t = (s->b - sqrt(disc)) / s->a;
	if (t > s->ray_min && t < s->ray_max)
		return (t);
	t = (s->b + sqrt(disc)) / s->a;
	if (t > s->ray_min && t < s->ray_max)
		return (t);
	return (-1.0);
}

double	ray_sphere(t_scene *s, t_vec3 direction, t_sphere *sp, t_vec3 *n)
{
	t_vec3	oc;
	double	t;

	oc = substract_vector(s->camera.viewpoint, sp->sp_center);
	t = sphere_root(s, direction, oc, sp->sp_radius);
	if (t < 0.0)
		return (-1.0);
	*n = calculate_normal_sphere(s, direction, sp, t);
	return (t);
}
