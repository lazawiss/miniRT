/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:57:25 by mipang            #+#    #+#             */
/*   Updated: 2025/02/28 13:09:16 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>
# include <stdint.h>

char	*num_to_hex(uintptr_t num);
int		ft_printf(const char *str, ...);
int		ft_printf_format(char spe, va_list args);
int		ft_pf_handle_unsigned_int(unsigned int n);
int		ft_pf_handle_int(int n);
int		ft_pf_handle_str(char *str);
int		ft_pf_handle_pointer(void *ptr);
int		ft_pf_handle_hex_generic(unsigned int num_hex, char up_low);

#endif
