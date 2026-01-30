/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:07:10 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/27 23:19:01 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned long int	seeder(void)
{
	unsigned long int	v;
	int					fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (1);
	if (read(fd, &v, sizeof(v)) != sizeof(v))
		return (1);
	close(fd);
	return (v);
}

t_rand	init_seed(t_rand r)
{
	r.x = seeder();
	r.y = seeder();
	r.z = seeder();
	r.w = seeder();
	r.c = 0;
	return (r);
}

t_rand	seed_kiss_no_power(t_rand *r)
{
	int	t;

	t = 0;
	r->y ^= (r->y << 5);
	r->y ^= (r->y >> 7);
	r->y ^= (r->y << 22);
	t = r->z + r->w + r->c;
	r->z = r->w;
	r->c = t < 0;
	r->w = t & 214783647;
	r->x += 1411392427;
	return (*r);
}

unsigned int	seed(t_rand *r)
{
	return (r->x + r->y + r->w);
}

double	random_double(unsigned int seed)
{
	double	x;

	x = seed / 4294967296.0;
	return (x);
}
