/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:11:05 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:11:22 by mkyianyt         ###   ########.fr       */
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

static char	*ft_cast_with_sharp(char *s)
{
	char	*tmp;
	char	*null;
	int		i;

	i = 0;
	null = ft_strnew(1);
	tmp = ft_strnew(ft_strlen(s) + 1);
	null[0] = '0';
	while (s[i] == ' ')
		i++;
	tmp = ft_strncpy(tmp, s, i);
	tmp = ft_strcat(tmp, null);
	if (s[i] == '0')
		tmp = ft_strcat(tmp, s + i + 1);
	else
		tmp = ft_strcat(tmp, s + i);
	free(null);
	free(s);
	return (tmp);
}

int			type_o(va_list *ap, t_var *var)
{
	unsigned long long	value;
	int 				len;

	ft_cast(&value, ap, var);
	//if (value == 0 && (var->precision >= 0 || var->sharp == 1))
	//	var->s = ft_strnew(1);
//	else
		var->s = ft_strnew(64);
	var->s = my_unsigned_itoa_base(value, 8);
	if (var->sharp == 1 && value > 0)
		var->width--;
	var->s = ft_function_1(var->s, var);
	if (var->sharp == 1 && value > 0)
		var->s = ft_cast_with_sharp(var->s);
	len = (int)ft_strlen(var->s);
	if (value == 0 && var->precision == 0 && !var->sharp)
	{

		var->s = ft_strnew(0);
		len = 0;
		var->s = ft_function_1(var->s, var);
		//len += var->width;
		len = (int)ft_strlen(var->s);
	}
	ft_putstr(var->s);
	return (len);
}
