/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:38:46 by mipang            #+#    #+#             */
/*   Updated: 2026/01/28 11:54:22 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "types.h"
# include "../libft/libft.h"

typedef struct s_scene
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_sphere	sph1;
	t_sphere	sph2;
	t_color		closest_object;
	t_list		*spheres;
	int			n_spheres;
	t_list		*planes;
	int			n_planes;
	t_list		*cylinders;
	int			n_cylinders;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			sample_per_pixel;
	double		pixel_sample_scale;
	double		a;
	double		b;
	double		c;
	double		ray_min;
	double		ray_max;
	double		closest_so_far;
	double		pixel_shading_sample;
	double		shift_x;
	double		shift_y;
	double		time;
	double		render_time;
	double		zoom;
}	t_scene;

typedef struct s_cy_hit
{
	t_scene	*s;
	t_vec3	direction;
	t_vec3	axis;
	t_vec3	oc;
	double	radius;
	double	half_h;
}	t_cy_hit;

typedef struct s_hit
{
	t_scene	*s;
	t_vec3	direction;
	double	t;
	t_vec3	n;
	t_vec3	p;
	t_color	color;
}	t_hit;

typedef struct s_shadow
{
	t_vec3		to_light;
	t_vec3		origin;
	t_vec3		old_origin;
	double		old_min;
	double		old_max;
	double		dist2;
	double		dist;
	double		n_dot_l;
}	t_shadow;

#endif
