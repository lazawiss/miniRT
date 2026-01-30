/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/27 12:00:00 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	diffuse_intensity(t_vec3 n, t_vec3 p, t_light l)
{
	t_vec3	dir_l;
	double	len;
	double	a;

	dir_l = substract_vector(l.pos, p);
	len = dot_squared(dot(dir_l, dir_l));
	if (len > 0.0)
		dir_l = unit_vector(dir_l, len);
	n = normalize_vec3(n);
	a = dot(dir_l, n);
	if (a < 0.0)
		a = 0.0;
	return (a * l.ratio);
}

t_vec3	combine_light(t_scene *s, double intensity)
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
