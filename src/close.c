/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:47:04 by leazannis         #+#    #+#             */
/*   Updated: 2025/12/22 19:42:14 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_win(t_scene *w_d)
{
	if (w_d->mlx_ptr)
	{
		mlx_destroy_image(w_d->mlx_ptr, w_d->img_ptr);
		mlx_destroy_window(w_d->mlx_ptr, w_d->win_ptr);
		mlx_destroy_display(w_d->mlx_ptr);
		free(w_d->mlx_ptr);
	}
	if (w_d->spheres || w_d->cylinders || w_d->planes)
		scene_free(w_d);
	free(w_d);
	exit(EXIT_SUCCESS);
}

int	handle_exit(void *param, t_scene *s)
{
	(void)param;
	close_win(s);
	return (0);
}
