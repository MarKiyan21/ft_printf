/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:08:56 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/31 10:11:57 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *ac, ...)
{
	t_var	*var;
	va_list	ap;
	char	*format;

	va_start(ap, ac);
	format = (char*)ac;
	var = (t_var*)malloc(sizeof(t_var));
	var->global_len = 0;
	init_all(var);
	while (*format)
	{
		if (*format == '%' && find_types(format + 1) >= 0)
			format = init_other_flags(format, var);
		if (*format == '%' && find_types(format + 1) == -1)
			format = init_flags_with_spec(format, &ap, var);
		else if (*format != '%' && *format)
		{
			ft_putchar(*format);
			var->global_len += 1;
		}
		if (*format == '\0')
			break ;
		if (*format != '%')
			format++;
	}
	free(var);
	va_end(ap);
	return (var->global_len);
}
