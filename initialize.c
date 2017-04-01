/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.s                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:57:15 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/04/01 16:08:44 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_all(t_var *var)
{
	var->sharp = 0;
	var->zero = 0;
	var->minus = 0;
	var->plus = 0;
	var->space = 0;
	var->width = -1;
	var->precision = -1;
	var->spec_hh = 0;
	var->spec_h = 0;
	var->spec_l = 0;
	var->spec_ll = 0;
	var->spec_j = 0;
	var->spec_z = 0;
	var->s = NULL;
}

char	*init_width(char *format, t_var *var)
{
	if (*format >= '0' && *format <= '9')
	{
		var->width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	return (format - 1);
}

char	*init_precision(char *format, t_var *var)
{
	var->precision = 0;
	format++;
	if (*format >= '0' && *format <= '9')
	{
		var->precision = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	if (var->minus == 1 && var->precision != -1)
		var->zero = 0;
	format--;
	return (format);
}

void	init_flags(char c, t_var *var)
{
	if (c == ' ' && var->plus == 0)
		var->space = 1;
	else if (c == '+')
	{
		var->plus = 1;
		var->space = 0;
	}
	else if (c == '-')
	{
		var->minus = 1;
		var->zero = 0;
	}
	else if (c == '#')
		var->sharp = 1;
	else if (c == '0' && var->precision == -1 && var->minus == 0)
		var->zero = 1;
}

void	init_modif(char *s, t_var *var)
{
	if (ft_find(s, "h") / 2 != 1 && ft_find(s, "h") != 0 && var->spec_hh == 0)
		var->spec_h = 1;
	else if (ft_find(s, "h") / 2 == 1 && ft_find(s, "h") != 0)
	{
		var->spec_h = 0;
		var->spec_hh = 1;
	}
	if (ft_find(s, "l") / 2 != 1 && ft_find(s, "l") != 0 && var->spec_ll == 0)
		var->spec_l = 1;
	else if (ft_find(s, "l") / 2 == 1 && ft_find(s, "l") != 0)
	{
		var->spec_l = 0;
		var->spec_ll = 1;
	}
	if (ft_strstr(s, "j"))
		var->spec_j = 1;
	if (ft_strstr(s, "z"))
		var->spec_z = 1;
}
