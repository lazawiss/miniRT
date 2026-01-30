/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:00:00 by mipang            #+#    #+#             */
/*   Updated: 2026/01/20 12:00:00 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	ray(t_vec3 origin, t_vec3 direction)
{
	t_vec3	ray_final;

	ray_final.x = origin.x + direction.x;
	ray_final.y = origin.y + direction.y;
	ray_final.z = origin.z + direction.z;
	return (ray_final);
}
