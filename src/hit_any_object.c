/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_any_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/27 12:00:00 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_spheres(t_scene *s, t_list *list, t_vec3 d, double max_t)
{
	t_vec3	n;
	double	t;

	while (list)
	{
		t = ray_sphere(s, d, (t_sphere *)list->content, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		list = list->next;
	}
	return (false);
}

static bool	hit_planes(t_scene *s, t_list *list, t_vec3 d, double max_t)
{
	t_vec3	n;
	double	t;

	while (list)
	{
		t = ray_plane(s, d, (t_plane *)list->content, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		list = list->next;
	}
	return (false);
}

static bool	hit_cylinders(t_scene *s, t_list *list, t_vec3 d, double max_t)
{
	t_vec3	n;
	double	t;

	while (list)
	{
		t = ray_cylinder(s, d, (t_cylinder *)list->content, &n);
		if (t > s->ray_min && t < max_t)
			return (true);
		list = list->next;
	}
	return (false);
}

bool	hit_any_object(t_scene *s, t_vec3 direction, double max_t)
{
	if (hit_spheres(s, s->spheres, direction, max_t))
		return (true);
	if (hit_planes(s, s->planes, direction, max_t))
		return (true);
	if (hit_cylinders(s, s->cylinders, direction, max_t))
		return (true);
	return (false);
}
