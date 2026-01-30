/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:22:38 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/28 00:10:04 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	sample_random_pixel(t_camera c, t_rand *r)
{
	*r = seed_kiss_no_power(r);
	c.offset.x = random_double(seed(r)) - 0.5;
	*r = seed_kiss_no_power(r);
	c.offset.y = random_double(seed(r)) - 0.5;
	c.offset.z = 0.0;
	return (c.offset);
}

t_camera	normalize_viewport(t_camera c, int i, int j)
{
	c.pixel_center.x = c.pixel00_loc.x
		+ ((i + c.offset.x) * c.pixel_delta_u.x)
		+ ((j + c.offset.y) * c.pixel_delta_v.x);
	c.pixel_center.y = c.pixel00_loc.y
		+ ((i + c.offset.x) * c.pixel_delta_u.y)
		+ ((j + c.offset.y) * c.pixel_delta_v.y);
	c.pixel_center.z = c.pixel00_loc.z
		+ (i * c.pixel_delta_u.z)
		+ (j * c.pixel_delta_v.z);
	c.orientation.x = c.pixel_center.x - c.viewpoint.x;
	c.orientation.y = c.pixel_center.y - c.viewpoint.y;
	c.orientation.z = c.pixel_center.z - c.viewpoint.z;
	return (c);
}

t_vec3	get_ray(t_scene *s, t_rand *r, int x, int y)
{
	t_vec3		ray_background;
	t_vec3		ray_final;
	t_camera	c;

	c = s->camera;
	ray_final = (t_vec3){0, 0, 0};
	c.offset = sample_random_pixel(c, r);
	c = normalize_viewport(c, x, y);
	ray_background = c.orientation;
	ray_final = ray_color(s, ray_background);
	s->camera = c;
	return (ray_final);
}

void	fill_frame(t_scene *s)
{
	int		x;
	int		y;
	t_rand	r;
	t_color	color_sc;

	y = 0;
	ft_memset(&r, 0, sizeof(t_rand));
	r = init_seed(r);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color_sc.pixel_color = color_each_pixel(s, &r, x, y);
			image_pixel_put(s, x, y, write_color(color_sc,
					color_sc.pixel_color.x,
					color_sc.pixel_color.y,
					color_sc.pixel_color.z));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	s->render_time = getexacttimeofday() - s->time;
	printf("render time : %.3lf\n", s->render_time);
}

void	renderer(t_scene *w_d)
{
	t_camera	c;

	c = w_d->camera;
	c = set_camera(c);
	w_d->camera = c;
	fill_frame(w_d);
}
