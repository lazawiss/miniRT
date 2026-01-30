/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:56:24 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/28 20:09:13 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	diffuse_intensity(t_vec3 n, t_vec3 p, t_light l)
{
	t_vec3	dir_l;
	double	len;
	double	a;

	dir_l = substract_vector(p, l.pos);
	len = dot_squared(dot(dir_l, dir_l));
	if (len > 0.0)
		dir_l = unit_vector(dir_l, len);
	n = normalize_vec3(n);
	a = dot(dir_l, n);
	if (a < 0.0)
		a = 0.0;
	return (a * l.ratio);
}

bool	ray_shadow(t_scene *s, t_shadow sh)
{
	bool	shadow;

	shadow = true;
	if (s->ray_max <= s->ray_min)
		shadow = false;
	else
	{
		sh.to_light = unit_vector(sh.to_light, sh.dist);
		shadow = hit_any_object(s, sh.to_light, s->ray_max);
	}
	s->camera.viewpoint = sh.old_origin;
	s->ray_min = sh.old_min;
	s->ray_max = sh.old_max;
	return (shadow);
}

bool	is_shadowed(t_scene *s, t_vec3 p, t_vec3 n)
{
	t_shadow		sh;
	bool			shadow;
	const double	bias = 1e-3;

	ft_memset(&sh, 0, sizeof(t_shadow));
	shadow = true;
	sh.to_light = substract_vector(p, s->light.pos);
	sh.dist2 = dot(sh.to_light, sh.to_light);
	if (sh.dist2 <= 0.0)
		return (false);
	sh.dist = sqrt(sh.dist2);
	n = normalize_vec3(n);
	if (dot(n, sh.to_light) < 0.0)
		n = power_vector_to_t(n, -1.0);
	sh.origin = add_vector(p, power_vector_to_t(n, bias));
	sh.old_origin = s->camera.viewpoint;
	sh.old_min = s->ray_min;
	sh.old_max = s->ray_max;
	s->camera.viewpoint = sh.origin;
	s->ray_min = bias;
	s->ray_max = sh.dist - bias;
	shadow = ray_shadow(s, sh);
	return (shadow);
}

static t_vec3	combine_light(t_scene *s, double intensity)
{
	t_vec3	ray_light;
	t_vec3	ray_color;
	t_vec3	ambient_light;
	t_vec3	out;

	ray_light = render_color(s->light.light_color);
	ray_light = power_vector_to_t(ray_light, intensity);
	ray_color = render_color(s->closest_object);
	ambient_light = render_color(s->ambient.ambient_color);
	ambient_light = power_vector_to_t(ambient_light, s->ambient.ratio);
	out.x = (ambient_light.x + ray_light.x) * ray_color.x;
	out.y = (ambient_light.y + ray_light.y) * ray_color.y;
	out.z = (ambient_light.z + ray_light.z) * ray_color.z;
	out.x = clamp(0.0, 1.0, out.x);
	out.y = clamp(0.0, 1.0, out.y);
	out.z = clamp(0.0, 1.0, out.z);
	return (out);
}

t_vec3	calculate_light(t_scene *s, t_vec3 n, t_vec3 p)
{
	double	intensity;

	intensity = diffuse_intensity(n, p, s->light);
	if (is_shadowed(s, p, n))
		intensity = 0.0;
	return (combine_light(s, intensity));
}
