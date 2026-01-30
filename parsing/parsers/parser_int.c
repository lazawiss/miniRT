/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:14:30 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 23:53:22 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_sign(char **p)
{
	int	sign;

	sign = 1;
	if ((**p == '+') || (**p == '-'))
	{
		if (**p == '-')
			sign = -1;
		(*p)++;
	}
	return (sign);
}

static int	check_overflow(long long result, int digit, int sign)
{
	long long	abs_min_limit;

	abs_min_limit = (long long)INT_MAX + 1LL;
	if (sign == 1)
	{
		if (result > INT_MAX / 10)
			return (1);
		if (result == INT_MAX / 10 && digit > INT_MAX % 10)
			return (1);
	}
	else
	{
		if (result > abs_min_limit / 10)
			return (1);
		if (result == abs_min_limit / 10
			&& digit > (int)(abs_min_limit % 10))
			return (1);
	}
	return (0);
}

int	parser_int(char **s, int *out)
{
	char			*p;
	int				sign;
	int				has_digit;
	long long		result;

	has_digit = 0;
	result = 0;
	if (!s || !*s)
		return (0);
	p = *s;
	skip_space(&p);
	sign = get_sign(&p);
	while (*p && ft_isdigit(*p))
	{
		has_digit = 1;
		if (check_overflow(result, (*p - '0'), sign))
			return (0);
		result = result * 10 + (long long)(*p - '0');
		p++;
	}
	if (has_digit == 0)
		return (0);
	*out = (int)(result * sign);
	*s = p;
	return (1);
}
