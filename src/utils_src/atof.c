/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:25:19 by leazannis         #+#    #+#             */
/*   Updated: 2025/12/17 17:23:35 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strlen_post_point(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	j = i;
	while (str[j])
		j++;
	return (j - i - 1);
}

double	ft_power(t_atof *atof)
{
	double	power;

	power = 1.0 / 10;
	while (atof->len)
	{
		atof->nbr *= power;
		atof->len--;
	}
	return (atof->nbr);
}

int	ft_atoi_atof(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] != '.')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}

double	ft_atof(char *str)
{
	t_atof	atof;

	atof.nbr = 0;
	atof.sign = 1;
	atof.i = 0;
	atof.len = ft_strlen_post_point(str);
	if (str[atof.i] == '-')
		atof.sign = -1;
	atof.i = ft_strlen(str) - atof.len;
	atof.nb = ft_atoi(str);
	if (str[atof.i] == '.')
		atof.i++;
	while (str[atof.i])
	{
		atof.nbr = (atof.nbr * 10) + (str[atof.i] - '0');
		atof.i++;
	}
	atof.nbr = ft_power(&atof);
	return ((atof.nb + atof.nbr) * atof.sign);
}
