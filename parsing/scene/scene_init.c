/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:29:39 by mipang            #+#    #+#             */
/*   Updated: 2026/01/22 21:57:58 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*scene_init(t_scene *sc)
{
	sc = malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	ft_memset(sc, 0, sizeof(t_scene));
	sc->sample_per_pixel = 10;
	sc->pixel_sample_scale = 1.0 / sc->sample_per_pixel;
	sc->ray_min = 0.001;
	sc->ray_max = INFINITY;
	sc->zoom = 2.0;
	sc->time = getexacttimeofday();
	return (sc);
}

static void	*xmalloc_zero(size_t sz)
{
	void	*p;

	p = malloc(sz);
	if (!p)
		return (NULL);
	ft_bzero(p, sz);
	return (p);
}

void	*scene_push(t_list **lst, size_t obj_size)
{
	void	*obj;
	t_list	*node;

	obj = xmalloc_zero(obj_size);
	if (!obj)
		return (NULL);
	node = ft_lstnew(obj);
	if (!node)
	{
		free(obj);
		return (NULL);
	}
	ft_lstadd_back(lst, node);
	node->next = NULL;
	return (obj);
}

static void	del_content(void *content)
{
	free(content);
}

void	scene_free(t_scene *sc)
{
	if (!sc)
		return ;
	ft_lstclear(&sc->planes, del_content);
	ft_lstclear(&sc->spheres, del_content);
	ft_lstclear(&sc->cylinders, del_content);
}
