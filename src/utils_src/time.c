/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:24:17 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/11 22:06:38 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*Gettimeofday but in milliseconds*/
int	getexacttimeofday(void)
{
	struct timeval	tv;
	int				seconds;
	int				microseconds;
	int				sum;

	if (gettimeofday(&tv, NULL))
		return (-1);
	seconds = tv.tv_sec * 1000;
	microseconds = tv.tv_usec / 1000;
	sum = seconds + microseconds;
	return (sum);
}
