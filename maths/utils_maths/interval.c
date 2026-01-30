/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:27 by lzannis           #+#    #+#             */
/*   Updated: 2026/01/21 16:46:43 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	interval_size(double min, double max)
{
	return (max - min);
}

bool	contains_between_min_and_max(double min, double max, double x)
{
	return (x >= min && x <= max);
}

bool	surrounds_to_min_and_max(double min, double max, double x)
{
	return (x > min && x < max);
}

double	clamp(double min, double max, double x)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
