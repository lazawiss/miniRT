/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_hex_generic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:12:31 by mipang            #+#    #+#             */
/*   Updated: 2024/12/10 15:30:39 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*upchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i ++;
	}
	return (str);
}

int	ft_pf_handle_hex_generic(unsigned int num_hex, char up_low)
{
	char	*result;
	int		len;

	result = num_to_hex(num_hex);
	if (!result)
		return (-1);
	if (up_low == 'X')
		upchar(result);
	ft_putstr_fd(result, 1);
	len = ft_strlen(result);
	free(result);
	return (len);
}
