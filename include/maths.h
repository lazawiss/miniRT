/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:30:05 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/28 19:38:01 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include "minirt.h"
# include <stdbool.h>

typedef struct t_point3
{
	double	x;
	double	y;
	double	z;
}	t_point3;

typedef struct t_ray
{
	t_point3	o;
	t_vec3		d;
	float		time;
	char		*medium;
	char		*material;
}	t_ray;

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_line;

typedef struct s_rect
{
	int	x;
	int	y;
	int	side_w;
	int	side_h;
	int	color;
}	t_rect;

typedef struct s_rand
{
	unsigned int	w;
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	c;
}	t_rand;

//-----POINT-----

int					pos(t_point3 *p);
int					new_pos_add(t_point3 *p);
int					new_pos_substract(t_point3 *p);

//-----VECTOR------

t_vec3				add_vector(t_vec3 v, t_vec3 u);
t_vec3				substract_vector(t_vec3 p, t_vec3 c);
t_vec3				power_vector_to_itself(t_vec3 *v);
t_vec3				power_vector_to_t(t_vec3 v, double t);
double				length_vector(double start, double finish);
double				dot_squared(double a);
double				dot(t_vec3 v, t_vec3 u);
t_vec3				unit_vector(t_vec3 v, double a);
t_vec3				cross_vec3(t_vec3 a, t_vec3 b);
t_vec3				normalize_vec3(t_vec3 v);

//-----RAY-----

bool				is_front_face(t_vec3 direction, t_vec3 normal);
double				ray_sphere(t_scene *s, t_vec3 direction,
						t_sphere *sp, t_vec3 *n);
t_vec3				ray(t_vec3 origin, t_vec3 direction);
double				ray_plane(t_scene *s, t_vec3 direction,
						t_plane *pl, t_vec3 *n);
double				ray_cylinder(t_scene *s, t_vec3 direction, t_cylinder *cy,
						t_vec3 *n);

//-----GEOMETRY-----

void				draw_circle(t_scene *win_dis);
void				ft_draw_line(t_line *line, t_scene *win_dis);
void				draw_rect(t_rect *rect, t_scene *win_dis);

//-----CYLINDER UTILS-----

t_vec3				cy_perp(t_vec3 v, t_vec3 axis);
void				cy_side_params(t_cy_hit *h, double params[3]);
void				cy_update_hit(double t, t_vec3 hit_n, double *best,
						t_vec3 *n);
int					cy_cap_hit(t_cy_hit *h, double t, double sign,
						t_vec3 *n);

//-----UTILS_MATHS-----

t_rand				init_seed(t_rand r);
unsigned long int	seeder(void);
t_rand				seed_kiss_no_power(t_rand *r);
unsigned int		seed(t_rand *r);
double				random_double(unsigned int seed);

//-----INTERVAL-----

double				interval_size(double min, double max);
bool				contains_between_min_and_max(double min, double max,
						double x);
bool				surrounds_to_min_and_max(double min, double max,
						double x);
double				clamp(double min, double max, double x);

#endif
