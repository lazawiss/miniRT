/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:50:57 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/28 14:30:25 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	degrees_to_radians(double fov)
{
	return (fov * PI / 180.0);
}

t_camera	calculate_viewport_height(t_camera c)
{
	double	theta;

	theta = degrees_to_radians((double)c.fov);
	c.viewport_height = 2.0 * tan(theta / 2.0);
	c.viewport_width = c.viewport_height * (((double)WIDTH) / ((double)HEIGHT));
	return (c);
}

t_camera	calculate_upper_left(t_camera c)
{
	t_vec3	forward;
	t_vec3	viewport_center;
	t_vec3	half_u;
	t_vec3	half_v;

	forward = normalize_vec3(c.orientation);
	viewport_center = add_vector(c.viewpoint, \
		power_vector_to_t(forward, c.focal_lenght));
	half_u = power_vector_to_t(c.viewport_u, 0.5);
	half_v = power_vector_to_t(c.viewport_v, 0.5);
	c.viewport_upper_left = substract_vector(half_u, viewport_center);
	c.viewport_upper_left = substract_vector(half_v, c.viewport_upper_left);
	c.pixel00_loc.x = c.viewport_upper_left.x + 0.5 \
	* (c.pixel_delta_u.x + c.pixel_delta_v.x);
	c.pixel00_loc.y = c.viewport_upper_left.y + 0.5 \
	* (c.pixel_delta_u.y + c.pixel_delta_v.y);
	c.pixel00_loc.z = c.viewport_upper_left.z + 0.5 \
	* (c.pixel_delta_u.z + c.pixel_delta_v.z);
	return (c);
}

t_camera	set_camera_init(t_camera c)
{
	t_vec3	forward;
	t_vec3	world_up;
	t_vec3	right;
	t_vec3	up;

	c.focal_lenght = 1.0;
	c = calculate_viewport_height(c);
	forward = normalize_vec3(c.orientation);
	world_up = (t_vec3){0, 1, 0};
	if (fabs(dot(forward, world_up)) > 0.999)
		world_up = (t_vec3){0, 0, 1};
	right = normalize_vec3(cross_vec3(forward, world_up));
	up = cross_vec3(right, forward);
	c.viewport_u = power_vector_to_t(right, c.viewport_width);
	c.viewport_v = power_vector_to_t(up, -c.viewport_height);
	c.pixel_delta_u = power_vector_to_t(c.viewport_u, 1.0 / (double)WIDTH);
	c.pixel_delta_v = power_vector_to_t(c.viewport_v, 1.0 / (double)HEIGHT);
	return (c);
}

t_camera	set_camera(t_camera c)
{
	c = set_camera_init(c);
	c = calculate_upper_left(c);
	return (c);
}
