/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:15:17 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:15:44 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cast(unsigned long long *value, va_list *ap, t_var *var)
{
	if (var->spec_ll == 1)
		*value = va_arg(*ap, unsigned long long);
	else if (var->spec_l == 1)
		*value = va_arg(*ap, unsigned long);
	else if (var->spec_j == 1)
		*value = va_arg(*ap, unsigned long);
	else if (var->spec_z == 1)
		*value = va_arg(*ap, unsigned long);
	else if (var->spec_h == 1)
		*value = (unsigned short)va_arg(*ap, int);
	else if (var->spec_hh == 1)
		*value = (unsigned char)va_arg(*ap, int);
	else
		*value = (unsigned int)va_arg(*ap, unsigned int);
}

int			type_u(va_list *ap, t_var *var)
{
	unsigned long long	value;

	ft_cast(&value, ap, var);
	if (value == 0 && var->precision >= 0)
		var->s = ft_strnew(1);
	else
		var->s = ft_strnew(64);
	var->s = my_unsigned_itoa_base(value, 10);
	var->s = ft_function_1(var->s, var);
	ft_putstr(var->s);
	return ((int)ft_strlen(var->s));
}
