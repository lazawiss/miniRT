/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:31:37 by leazannis         #+#    #+#             */
/*   Updated: 2025/12/17 18:24:35 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_hook(int button, int x, int y, t_scene *s)
{
	(void)x;
	(void)y;
	if (button == 4)
		s->zoom *= 0.85;
	if (button == 5)
		s->zoom *= 1.15;
	if (button == 1)
		s->zoom *= 0.5;
	if (button == 3)
		s->zoom *= 2.5;
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	return (0);
}
