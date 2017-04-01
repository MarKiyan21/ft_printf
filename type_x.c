/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:18:43 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:18:54 by mkyianyt         ###   ########.fr       */
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
	char	*sharp;
	int		i;

	i = 0;
	sharp = ft_strnew(2);
	tmp = ft_strnew(ft_strlen(s) + 2);
	sharp[0] = '0';
	sharp[1] = 'x';
	while (s[i] == ' ')
		i++;
	tmp = ft_strncpy(tmp, s, i);
	tmp = ft_strcat(tmp, sharp);
	tmp = ft_strcat(tmp, s + i);
	free(sharp);
	free(s);
	return (tmp);
}

int			type_x(va_list *ap, t_var *var, int flag)
{
	unsigned long long	value;
	int					i;

	i = -1;
	ft_cast(&value, ap, var);
	if (value == 0 && var->precision >= 0)
		var->s = ft_strnew(1);
	else
		var->s = ft_strnew(64);
	if (var->precision != 0)
		var->s = my_unsigned_itoa_base(value, 16);
	if (var->sharp == 1 && value > 0)
		var->width -= 2;
	var->s = ft_function_1(var->s, var);
	if (var->sharp == 1 && value > 0)
		var->s = ft_cast_with_sharp(var->s);
	if (flag == 1)
		var->s = ft_uppercase(var->s);
	while (var->s[++i])
		ft_putchar(var->s[i]);
	return ((int)ft_strlen(var->s));
}
