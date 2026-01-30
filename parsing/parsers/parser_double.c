/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:14:38 by mipang            #+#    #+#             */
/*   Updated: 2025/12/12 17:25:52 by mipang           ###   ########.fr       */
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

static void	init_double_i(t_double_i *pd, char **s)
{
	pd->p = *s;
	skip_space(&pd->p);
	pd->sign = get_sign(&pd->p);
	pd->fp = 0.0;
	pd->ip = 0.0;
	pd->base = 1.0;
	pd->has_digit = 0;
	pd->has_frac = 0;
}

static int	double_core(t_double_i *pd)
{
	if (!pd)
		return (0);
	while (*(pd->p) && ft_isdigit(*(pd->p)))
	{
		pd->has_digit = 1;
		pd->ip = pd->ip * 10 + (double)(*(pd->p) - '0');
		pd->p++;
	}
	if (*(pd->p) == '.')
	{
		pd->p++;
		while ((*(pd->p)) && ft_isdigit(*(pd->p)))
		{
			pd->has_digit = 1;
			pd->has_frac = 1;
			pd->base *= 10.0;
			pd->fp += (double)(*(pd->p) - '0') / (pd->base);
			pd->p++;
		}
	}
	return (1);
}

int	parser_double(char **s, double *out)
{
	t_double_i		pd;
	char			*save;

	if (!s || !*s || !out)
		return (0);
	save = *s;
	init_double_i(&pd, s);
	if (!double_core(&pd) || !(pd.has_digit))
	{
		*s = save;
		return (0);
	}
	*out = (pd.ip + pd.fp) * (double)(pd.sign);
	*s = pd.p;
	return (1);
}
