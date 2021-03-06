/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 14:04:20 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/04/01 14:04:25 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_char(t_var *var, char c)
{
	char	*s;
	int		i;
	int		len;

	i = -1;
	s = ft_strnew(2);
	s[0] = c;
	if (var->width > 0)
		s = fillstring_c(s, var);
	len = ft_strlen(s);
	if (!c)
	{
		while (++i < len - 1)
			ft_putchar(s[i]);
		ft_putchar(0);
	}
	else
		ft_putstr(s);
	return ((int)ft_strlen(s));
}
