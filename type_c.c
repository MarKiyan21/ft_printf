/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:07:22 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:07:24 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_c(va_list *ap, t_var *var)
{
	char	c;
	char	*s;
	int		i;
	int		len;

	i = -1;
	c = va_arg(*ap, int);
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
		if (var->width > 0)
			return (var->width);
		else
			return (1);
	}
	else
		ft_putstr(s);
	return ((int)ft_strlen(s));
}
