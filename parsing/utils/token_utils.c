/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:38:42 by mipang            #+#    #+#             */
/*   Updated: 2025/12/17 00:18:26 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	skip_space(char **str)
{
	while (**str && is_space(**str))
		(*str)++;
}

int	expect_split(char **s, char c)
{
	char	*cur;

	if (!s || !*s)
		return (0);
	cur = *s;
	skip_space(&cur);
	if (*cur != c)
		return (0);
	cur++;
	*s = cur;
	return (1);
}

int	ensure_eol(char *p)
{
	while (*p == '\t' || *p == ' ')
		p++;
	return (*p == '\n' || *p == '\0');
}

int	eat_ident(char **s, const char *const id, size_t len)
{
	char	*p;
	size_t	i;

	if (!s || !*s || !id)
		return (0);
	i = 0;
	p = *s;
	while (i < len)
	{
		if (p[i] != id[i])
			return (0);
		i++;
	}
	if (p[len] != '\0' && !is_space(p[len]))
		return (0);
	p += len;
	skip_space(&p);
	*s = p;
	return (1);
}
