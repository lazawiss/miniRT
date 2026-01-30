/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:10:00 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/27 21:23:30 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	render_background(t_scene *s, t_vec3 direction)
{
	t_vec3	unit_direction;
	double	a;
	double	b;

	(void)s;
	b = dot_squared(dot(direction, direction));
	unit_direction = unit_vector(direction, b);
	a = 0.5 * (unit_direction.y + 1.0);
	unit_direction.x = (1.0 - a) * 1.0 + a * 0.5;
	unit_direction.y = (1.0 - a) * 1.0 + a * 0.7;
	unit_direction.z = (1.0 - a) * 1.0 + a * 1.0;
	return (unit_direction);
}

/* normalisation position to int to translate color */
/* -0.1 >> [0,255] */
int	write_color(t_color c, double pixel_color_x,
		double pixel_color_y, double pixel_color_z)
{
	double	auto_r;
	double	auto_g;
	double	auto_b;
	double	min;
	double	max;

	c.r = 0;
	c.g = 0;
	c.b = 0;
	min = 0.000;
	max = 0.999;
	auto_r = pixel_color_x;
	auto_g = pixel_color_y;
	auto_b = pixel_color_z;
	c.r = (int)(255.999 * clamp(min, max, auto_r));
	c.g = (int)(255.999 * clamp(min, max, auto_g));
	c.b = (int)(255.999 * clamp(min, max, auto_b));
	return (0xFF << 24 | c.r << 16 | c.g << 8 | c.b);
}

/* take original color in int [0,255] translate them in double */
/* assign them to a position (x,y,z) */
t_vec3	render_color(t_color c)
{
	double	auto_r;
	double	auto_g;
	double	auto_b;

	auto_r = (int)(c.r) / 255.999;
	auto_g = (int)(c.g) / 255.999;
	auto_b = (int)(c.b) / 255.999;
	c.pixel_color.x = (double)auto_r;
	c.pixel_color.y = (double)auto_g;
	c.pixel_color.z = (double)auto_b;
	return (c.pixel_color);
}

int	give_color(int r, int g, int b)
{
	return (0xFF << 24 | r << 16 | g << 8 | b);
}
