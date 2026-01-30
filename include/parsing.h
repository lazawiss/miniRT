/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:56:17 by mipang            #+#    #+#             */
/*   Updated: 2026/01/29 20:01:05 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "scene.h"
# include <limits.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

void		parser_error(t_scene *sc, int lineidx, const char *msg);
void		skip_space(char **str);
void		*scene_push(t_list **lst, size_t obj_size);
void		scene_free(t_scene *sc);
int			dispatch(t_scene *sc, char *line, int lineidx);
int			is_space(char c);
int			check_ratio(double r);
int			check_rgb(int c);
int			dispatch_a(t_scene *sc, char *p, int lineidx);
int			dispatch_c(t_scene *sc, char *p, int lineidx);
int			dispatch_l(t_scene *sc, char *p, int lineidx);
int			dispatch_sp(t_scene *sc, char *p, int lineidx);
int			dispatch_pl(t_scene *sc, char *p, int lineidx);
int			dispatch_cy(t_scene *sc, char *p, int lineidx);
int			parser_int(char **s, int *out);
int			parser_color(char **s, t_color *out);
int			parser_double(char **s, double *out);
int			parser_vec3(char **s, t_vec3 *out);
int			expect_split(char **s, char c);
int			eat_ident(char **s, const char *const id, size_t len);
int			ensure_eol(char *p);
int			sub_parser_error(t_scene *sc, int lineidx, const char *msg);
t_scene		*parser_rt(const char *rt_file_name);
t_scene		*scene_init(t_scene *sc);
t_plane		*add_plane(t_scene *sc);
t_sphere	*add_sphere(t_scene *sc);
t_cylinder	*add_cylinder(t_scene *sc);

typedef struct s_double_i
{
	char	*p;
	int		sign;
	double	fp;
	double	ip;
	double	base;
	int		has_digit;
	int		has_frac;
}	t_double_i;

#endif
