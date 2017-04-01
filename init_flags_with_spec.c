/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags_with_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:51:55 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 17:51:59 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_flags_with_spec(char *format, va_list *ap, t_var *var)
{
//	init_all(var);
	while (*format)
	{
		format++;
		if (is_specificator(*format))
		{
			identify_specificator(*format, ap, var);
			break ;
		}
		if ((*format > '0' && *format <= '9') &&
				*(format - 1) != '.')
			format = init_width(format, var);
		else if (is_flags(*format))
			init_flags(*format, var);
		if (*format == '.')
			format = init_precision(format, var);
		if (is_modif(*format))
			init_modif(format, var);
	}
//	identify_specificator(*format, ap, var);
	return (format);
}
