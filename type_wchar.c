/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:15:58 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:15:59 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	count_len_bits(wint_t *i)
{
	int				index;
	unsigned int	len;

	index = -1;
	len = 0;
	while (i[++index])
	{
		if (i[index] <= 0x7F)
			len++;
		else if (i[index] <= 0x7FF)
			len += 2;
		else if (i[index] <= 0xFFFF)
			len += 3;
		else if (i[index] <= 0x1FFFFF)
			len += 4;
	}
	return (len);
}

int					type_wchar(va_list *ap, t_var *var, int x, int y)
{
	wint_t	*i;

	i = va_arg(*ap, wint_t*);
	if (!i)
	{
		var->s = ft_strnew(6);
		var->s = "(null)";
		return ((int)ft_strlen(var->s));
	}
	var->s = ft_strnew(count_len_bits(i));
	while (i[++x])
	{
		if (i[x] <= 0x7F)
			var->s[y++] = i[x];
		else if (i[x] <= 0x7FF)
			var->s = bits_help_1(var->s, i, &x, &y);
		else if (i[x] <= 0xFFFF)
			var->s = bits_help_2(var->s, i, &x, &y);
		else if (i[x] <= 0x1FFFFF)
			var->s = bits_help_3(var->s, i, &x, &y);
	}
	var->s[y] = '\0';
	return ((int)ft_strlen(var->s));
}
