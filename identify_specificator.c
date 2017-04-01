/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_specificator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:43:44 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/04/01 14:03:44 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	identify_continue(char type, va_list *ap, t_var *var)
{
	if (type == 'U')
	{
		var->spec_l = 1;
		var->global_len += type_u(ap, var);
	}
	else if (type == 'x')
		var->global_len += type_x(ap, var, 0);
	else if (type == 'X')
		var->global_len += type_x(ap, var, 1);
	else if (type == 'C' || (type == 'c' && var->spec_l == 1))
		var->global_len += type_c(ap, var);
	else if (type == 'c')
		var->global_len += type_c(ap, var);
}

static void	identify_spec_continue(char type, va_list *ap, t_var *var)
{
	if (type == 'D')
	{
		var->spec_l = 1;
		var->global_len += type_d(ap, var);
	}
	else if (type == 'o')
		var->global_len += type_o(ap, var);
	else if (type == 'O')
	{
		var->spec_l = 1;
		var->global_len += type_o(ap, var);
	}
	else if (type == 'u')
		var->global_len += type_u(ap, var);
	else
		identify_continue(type, ap, var);
}

void		identify_specificator(char type, va_list *ap, t_var *var)
{
	if (type == 'S' || (type == 's' && var->spec_l == 1))
		var->global_len += type_wchar(ap, var, -1, 0);
	else if (type == 's')
		var->global_len += type_s(ap, var);
	else if (type == 'p')
	{
		var->sharp = 1;
		var->spec_l = 1;
		var->global_len += type_p(ap, var);
	}
	else if (type == 'd' || type == 'i')
		var->global_len += type_d(ap, var);
	else
		identify_spec_continue(type, ap, var);
}
