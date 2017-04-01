/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:08:56 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/04/01 16:09:04 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_k(char c, t_var *var)
{
	ft_putchar(c);
	var->global_len += 1;
}

int			ft_printf(const char *ac, ...)
{
	t_var	var;
	va_list	ap;
	char	*format;

	va_start(ap, ac);
	format = (char*)ac;
	var.global_len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
			break ;
		if (*format == '%' && find_types(format + 1) >= 0)
			format = init_other_flags(format, &var);
		if (*format == '%' && find_types(format + 1) == -1)
			format = init_flags_with_spec(format, &ap, &var);
		else if (*format != '%' && *format)
			ft_printf_k(*format, &var);
		if (*format == '\0')
			break ;
		if (*format != '%')
			format++;
	}
	va_end(ap);
	return (var.global_len);
}
