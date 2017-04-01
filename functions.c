/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:35:00 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 17:35:14 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_function_1(char *s, t_var *var)
{
	char	*str;
	int		len;

	len = (int)ft_strlen(s);
	if (var->precision > len)
	{
		str = ft_strnew(var->precision + 1);
		str = ft_memset(str, 48, var->precision - len);
		ft_strncat(str, s, var->precision);
	}
	else
		str = ft_strdup(s);
	if (var->width > (int)ft_strlen(str))
		str = fillstring(str, var);
	free(s);
	return (str);
}

char		*ft_function_2(char *s, t_var *var, long long value)
{
	char	*str;
	char	c;
	int		i;

	str = s;
	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (value < 0)
		c = '-';
	else if (var->plus == 1)
		c = '+';
	else
		c = ' ';
	s = ft_strnew(ft_strlen(s) + 1);
	ft_strncpy(s, str, i);
	s[i] = c;
	ft_strcat(s, str + i);
	free(str);
	return (s);
}
