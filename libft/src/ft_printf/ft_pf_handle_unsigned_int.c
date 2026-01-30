/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_unsigned_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-08 21:23:28 by mipang            #+#    #+#             */
/*   Updated: 2024/12/09 14:18:20 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_len(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

static char	*ft_utoa(unsigned int n)
{
	char	*result;
	int		len;

	len = count_len(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		result[len - 1] = (n % 10) + '0';
		n = n / 10;
		len --;
	}
	return (result);
}

int	ft_pf_handle_unsigned_int(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
