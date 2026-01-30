/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leazannis <leazannis@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:54:41 by mipang            #+#    #+#             */
/*   Updated: 2025/12/22 19:46:50 by leazannis        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_buffer(char *readline, char *buffer)
{
	int		re_len;
	int		buf_len;
	char	*new_readline;

	if (!buffer)
		return (NULL);
	if (readline)
		re_len = ft_strlen(readline);
	else
		re_len = 0;
	buf_len = ft_strlen(buffer);
	new_readline = malloc(re_len + buf_len + 1);
	if (!new_readline)
		return (NULL);
	if (readline)
	{
		ft_memcpy(new_readline, readline, re_len);
		free(readline);
	}
	ft_memcpy(new_readline + re_len, buffer, buf_len);
	new_readline[re_len + buf_len] = '\0';
	return (new_readline);
}

char	*extra_line(char *readline)
{
	char	*extraline;
	int		re_len;
	int		j;

	re_len = 0;
	if (!readline)
		return (NULL);
	while (readline[re_len] && readline[re_len] != '\n')
		re_len ++;
	extraline = malloc(re_len + 2);
	if (!extraline)
		return (NULL);
	j = 0;
	while (j <= re_len)
	{
		extraline[j] = readline[j];
		j ++;
	}
	extraline[j] = '\0';
	return (extraline);
}

char	*update_readline(char *readline)
{
	char	*new_readline;
	int		new_len;
	int		i;

	i = 0;
	if (!readline)
		return (NULL);
	while (readline[i] != '\n' && readline[i] != '\0')
		i++;
	if (readline[i] == '\0' || readline[i + 1] == '\0')
		return (free(readline), NULL);
	if (!readline[i + 1])
		return (free(readline), NULL);
	new_len = ft_strlen(readline) - i - 1;
	new_readline = malloc(new_len + 1);
	if (!new_readline)
		return (NULL);
	ft_memcpy(new_readline, readline + i + 1, new_len);
	new_readline[new_len] = '\0';
	free(readline);
	return (new_readline);
}
