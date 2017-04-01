/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_other_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:54:35 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 17:54:37 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_other_flags(char *format, t_var *var)
{
//	init_all(var);
	while (*format)
	{
		format++;
		if ((*format > '0' && *format <= '9') &&
				*(format - 1) != '.')
			format = init_width(format, var);
		else if (is_flags(*format))
			init_flags(*format, var);
		if (*format == '.')
			format = init_precision(format, var);
		if (is_modif(*format))
			init_modif(format, var);
		if (!(*format > 0 && *format <= 9) && *format != '.' &&
				!(is_flags(*format)) && !(is_modif(*format)))
			break ;
	}
	var->global_len = write_char(var, *format);
	format++;
	return (format);
}
