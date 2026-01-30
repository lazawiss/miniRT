/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:53:08 by mipang            #+#    #+#             */
/*   Updated: 2026/01/28 10:41:52 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*add_plane(t_scene *sc)
{
	t_plane	*obj;

	if (!sc)
		return (NULL);
	obj = (t_plane *)scene_push(&sc->planes, sizeof(t_plane));
	if (!obj)
		return (NULL);
	else
		sc->n_planes++;
	return (obj);
}

t_sphere	*add_sphere(t_scene *sc)
{
	t_sphere	*obj;

	if (!sc)
		return (NULL);
	obj = (t_sphere *)scene_push(&sc->spheres, sizeof(t_sphere));
	if (!obj)
		return (NULL);
	else
		sc->n_spheres++;
	return (obj);
}

t_cylinder	*add_cylinder(t_scene *sc)
{
	t_cylinder	*obj;

	if (!sc)
		return (NULL);
	obj = (t_cylinder *)scene_push(&sc->cylinders, sizeof(t_cylinder));
	if (!obj)
		return (NULL);
	else
		sc->n_cylinders++;
	return (obj);
}
