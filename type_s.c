/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:14:24 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:14:39 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_to_fill_string(t_var *var, char *s, char c)
{
	char	*tmp;

	tmp = s;
	s = ft_strnew(var->width + 1);
	if (var->minus == 1)
	{
		ft_strcpy(s, tmp);
		ft_memset(s + ft_strlen(tmp), c, var->width - ft_strlen(tmp));
	}
	else
	{
		ft_memset(s, c, var->width - ft_strlen(tmp));
		ft_strcat(s, tmp);
	}
	free(tmp);
	return (s);
}

int			type_s(va_list *ap, t_var *var)
{
	char	*s;
	char	c;

	c = ' ';
	if ((var->s = va_arg(*ap, char*)) == NULL)
		var->s = "(null)";
	if (var->zero == 1)
		c = '0';
	if (var->precision >= 0 && var->precision < (int)ft_strlen(var->s))
	{
		s = ft_strnew(var->precision + 1);
		ft_strncpy(s, var->s, var->precision);
	}
	else
		s = ft_strdup(var->s);
	if (var->width > (int)ft_strlen(s))
		s = ft_to_fill_string(var, s, c);
	ft_putstr(s);
	return ((int)ft_strlen(s));
}
