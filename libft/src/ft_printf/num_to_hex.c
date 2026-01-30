/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:57:28 by mipang            #+#    #+#             */
/*   Updated: 2024/12/10 21:33:58 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex_len(uintptr_t num)
{
	int	i;

	i = 1;
	while (num >= 16)
	{
		num /= 16;
		i ++;
	}
	return (i);
}

char	*num_to_hex(uintptr_t num)
{
	const char	*hex_char;
	char		*result;
	int			num_len;

	hex_char = "0123456789abcdef";
	num_len = count_hex_len(num);
	result = malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	while (num_len > 0)
	{
		result[num_len - 1] = hex_char[num % 16];
		num /= 16;
		num_len --;
	}
	return (result);
}
