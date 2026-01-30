/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:42:12 by mipang            #+#    #+#             */
/*   Updated: 2025/04/25 14:10:06 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include "../../libft.h"
# include <stdlib.h>

char	*get_next_line(int fd);
char	*copy_buffer(char *readline, char *buffer);
char	*extra_line(char *readline);
char	*update_readline(char *readline);

#endif
