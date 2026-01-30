/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-06 19:55:59 by mipang            #+#    #+#             */
/*   Updated: 2024/12/10 15:53:05 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(char spe, va_list args)
{
	if (spe == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (spe == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	if (spe == 'd' || spe == 'i')
		return (ft_pf_handle_int(va_arg(args, int)));
	if (spe == 'u')
		return (ft_pf_handle_unsigned_int(va_arg(args, unsigned int)));
	if (spe == 'p')
		return (ft_pf_handle_pointer(va_arg(args, void *)));
	if (spe == 's')
		return (ft_pf_handle_str(va_arg(args, char *)));
	if (spe == 'x' || spe == 'X')
		return (ft_pf_handle_hex_generic(va_arg(args, unsigned int), spe));
	return (0);
}
