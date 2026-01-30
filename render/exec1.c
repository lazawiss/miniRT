/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:04:02 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/26 17:09:25 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	color_each_pixel(t_scene *s, t_rand *r, int x, int y)
{
	int		i;
	t_color	color_sc;
	t_color	new_color_sc;

	i = 0;
	color_sc.pixel_color = (t_vec3){0, 0, 0};
	while (i < s->sample_per_pixel)
	{
		new_color_sc.pixel_color = (t_vec3){0, 0, 0};
		new_color_sc.pixel_color = get_ray(s, r, x, y);
		color_sc.pixel_color = add_vector(color_sc.pixel_color,
				new_color_sc.pixel_color);
		i++;
	}
	color_sc.pixel_color = power_vector_to_t(color_sc.pixel_color,
			s->pixel_sample_scale);
	return (color_sc.pixel_color);
}
