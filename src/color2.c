/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:21:25 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/27 22:03:43 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_sphere(t_scene *s, t_vec3 direction, double max_t)
{
	t_list		*temp;
	t_sphere	*sp;
	t_vec3		n;
	double		t;

	temp = s->spheres;
	while (temp)
	{
		sp = temp->content;
		t = ray_sphere(s, direction, sp, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	hit_plane(t_scene *s, t_vec3 direction, double max_t)
{
	t_list		*temp;
	t_plane		*pl;
	t_vec3		n;
	double		t;

	temp = s->planes;
	while (temp)
	{
		pl = temp->content;
		t = ray_plane(s, direction, pl, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	hit_cylinder(t_scene *s, t_vec3 direction, double max_t)
{
	t_list		*temp;
	t_cylinder	*cy;
	t_vec3		n;
	double		t;

	temp = s->cylinders;
	while (temp)
	{
		cy = temp->content;
		t = ray_cylinder(s, direction, cy, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	hit_any_object(t_scene *s, t_vec3 direction, double max_t)
{
	if (hit_sphere(s, direction, max_t))
		return (true);
	if (hit_plane(s, direction, max_t))
		return (true);
	if (hit_cylinder(s, direction, max_t))
		return (true);
	return (false);
}
