/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:27:57 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/26 14:35:07 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	pos(t_point3 *p)
{
	if (!p)
		return (0);
	return ((int)(p->x + p->y + p->z));
}

int	new_pos_add(t_point3 *p)
{
	if (!p)
		return (0);
	return ((int)(p->x + p->y + p->z));
}

int	new_pos_substract(t_point3 *p)
{
	if (!p)
		return (0);
	return ((int)(p->x - p->y - p->z));
}
