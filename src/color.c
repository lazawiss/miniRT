/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/28 12:06:44 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "maths.h"

static void	update_hit(t_hit *hit, double t, t_vec3 n, t_color color)
{
	if (t > 0.0 && t < hit->t)
	{
		hit->t = t;
		hit->n = n;
		hit->color = color;
		hit->p = add_vector(hit->s->camera.viewpoint,
				power_vector_to_t(hit->direction, t));
	}
}

static void	hit_spheres(t_hit *hit)
{
	t_list		*temp;
	t_sphere	*sp;
	t_vec3		n;
	double		t;

	temp = hit->s->spheres;
	while (temp)
	{
		sp = temp->content;
		t = ray_sphere(hit->s, hit->direction, sp, &n);
		update_hit(hit, t, n, sp->sp_color);
		temp = temp->next;
	}
}

static void	hit_planes(t_hit *hit)
{
	t_list	*temp;
	t_plane	*pl;
	t_vec3	n;
	double	t;

	temp = hit->s->planes;
	while (temp)
	{
		pl = temp->content;
		t = ray_plane(hit->s, hit->direction, pl, &n);
		update_hit(hit, t, n, pl->pl_color);
		temp = temp->next;
	}
}

static void	hit_cylinders(t_hit *hit)
{
	t_list		*temp;
	t_cylinder	*cy;
	t_vec3		n;
	double		t;

	temp = hit->s->cylinders;
	while (temp)
	{
		cy = temp->content;
		t = ray_cylinder(hit->s, hit->direction, cy, &n);
		update_hit(hit, t, n, cy->cy_color);
		temp = temp->next;
	}
}

/* assign color to pixel depending on their position on the screen */
t_vec3	ray_color(t_scene *s, t_vec3 direction)
{
	t_hit	hit;

	hit.s = s;
	hit.direction = direction;
	hit.t = s->ray_max;
	hit.n = (t_vec3){0, 0, 0};
	hit.p = (t_vec3){0, 0, 0};
	hit.color = (t_color){0};
	hit_spheres(&hit);
	hit_planes(&hit);
	hit_cylinders(&hit);
	if (hit.t < s->ray_max)
	{
		s->closest_object = hit.color;
		return (calculate_light(s, hit.n, hit.p));
	}
	return (render_background(s, direction));
}
