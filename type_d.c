/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_dDi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:08:32 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:08:39 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cast(long long *value, va_list *ap, t_var *var)
{
	if (var->spec_ll == 1)
		*value = va_arg(*ap, long long);
	else if (var->spec_l == 1)
		*value = va_arg(*ap, long);
	else if (var->spec_j == 1)
		*value = va_arg(*ap, long);
	else if (var->spec_z == 1)
		*value = va_arg(*ap, long);
	else if (var->spec_h == 1)
		*value = (short)va_arg(*ap, int);
	else if (var->spec_hh == 1)
		*value = (char)va_arg(*ap, int);
	else
		*value = (int)va_arg(*ap, int);
}

int			type_d(va_list *ap, t_var *var)
{
	long long	value;
	int 		len;

	ft_cast(&value, ap, var);
//	if (value == 0 && var->precision >= 0)
//		var->s = ft_strnew(1);
//	else
		var->s = ft_strnew(64);
	if (value < 0 || var->plus == 1 || var->space == 1)
		var->width--;
	var->s = my_itoa_base(value, 10);
//	if (ft_atoi(var->s) < 0 && (var->spec_l == 0 || var->spec_ll == 1))
//		var->s = ft_del_minus(var->s);
	if (var->s[0] == '-' && (var->spec_l == 0 || var->spec_ll == 1))
		var->s = ft_del_minus(var->s);
	var->s = ft_function_1(var->s, var);
	if (value < 0 || var->plus == 1 || var->space == 1)
		var->s = ft_function_2(var->s, var, value);
	//
	len = (int)ft_strlen(var->s);
	if (value == 0 && var->precision == 0)
	{

		var->s = ft_strnew(0);
		len = 0;
		var->s = ft_function_1(var->s, var);
		//len += var->width;
		len = (int)ft_strlen(var->s);
	}
	//
	ft_putstr(var->s);
	//return ((int)ft_strlen(var->s));
	return (len);
}


