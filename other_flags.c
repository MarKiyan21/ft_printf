/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:04:35 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/04/01 14:05:56 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specificator(char c)
{
	int	i;

	i = -1;
	while (c && SPEC[++i])
		if (c == SPEC[i])
			return (1);
	return (0);
}

int		is_flags(char c)
{
	int	i;

	i = -1;
	while (c && FLAGS[++i])
		if (c == FLAGS[i])
			return (1);
	return (0);
}

int		is_modif(char c)
{
	int	i;

	i = -1;
	while (c && MODIF[++i])
		if (c == MODIF[i])
			return (1);
	return (0);
}

int		find_types(char *format)
{
	int i;

	i = 0;
	while (!(is_specificator(format[i])))
	{
		if (is_flags(format[i]) || is_modif(format[i]) ||
				format[i] == '.' || (format[i] >= '0' && format[i] <= '9'))
			i++;
		else
			return (i);
	}
	return (-1);
}

int		ft_find(char *s, char *c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i] && !is_specificator(s[i]))
		if (s[i] == c[0])
			count++;
	return (count);
}
