/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/27 12:00:00 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SHADOW_BIAS 1e-3

bool	hit_any_object(t_scene *s, t_vec3 direction, double max_t);
double	diffuse_intensity(t_vec3 n, t_vec3 p, t_light l);
t_vec3	combine_light(t_scene *s, double intensity);

static bool	shadow_hit(t_scene *s, t_vec3 to_light, double dist2)
{
	if (s->ray_max <= s->ray_min)
		return (false);
	to_light = unit_vector(to_light, dist2);
	return (hit_any_object(s, to_light, s->ray_max));
}

static bool	restore_shadow(t_scene *s, t_vec3 old_origin, double *old,
		bool shadow)
{
	s->camera.viewpoint = old_origin;
	s->ray_min = old[0];
	s->ray_max = old[1];
	return (shadow);
}

static bool	is_shadowed(t_scene *s, t_vec3 p, t_vec3 n)
{
	t_vec3		to_light;
	t_vec3		old_origin;
	double		old[2];
	double		dist2;
	bool		shadow;

	to_light = substract_vector(s->light.pos, p);
	dist2 = dot(to_light, to_light);
	if (dist2 <= 0.0)
		return (false);
	n = normalize_vec3(n);
	if (dot(n, to_light) < 0.0)
		n = power_vector_to_t(n, -1.0);
	old_origin = s->camera.viewpoint;
	old[0] = s->ray_min;
	old[1] = s->ray_max;
	s->camera.viewpoint = add_vector(p, power_vector_to_t(n, SHADOW_BIAS));
	s->ray_min = SHADOW_BIAS;
	s->ray_max = sqrt(dist2) - SHADOW_BIAS;
	shadow = shadow_hit(s, to_light, dist2);
	return (restore_shadow(s, old_origin, old, shadow));
}

t_vec3	calculate_light(t_scene *s, t_vec3 n, t_vec3 p)
{
	double	intensity;

	intensity = diffuse_intensity(n, p, s->light);
	if (is_shadowed(s, p, n))
		intensity = 0.0;
	return (combine_light(s, intensity));
}
