/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:26:10 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 17:26:15 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fillstring(char *s, t_var *var)
{
	char	c;
	char	*tmp;

	tmp = s;
	if (var->zero == 1 && var->precision < 0 && var->minus == 0)
		c = '0';
	else
		c = ' ';
	s = ft_strnew(var->width + 1);
	if (var->minus == 1)
	{
		ft_strcpy(s, tmp);
		ft_memset(s + ft_strlen(tmp), c, var->width - ft_strlen(tmp));
	}
	else
	{
		ft_memset(s, c, var->width - ft_strlen(tmp));
		ft_strcat(s, tmp);
	}
	free(tmp);
	return (s);
}

char	*fillstring_c(char *s, t_var *var)
{
	char	c;
	char	*tmp;

	tmp = s;
	if (var->zero == 1)
		c = '0';
	else
		c = ' ';
	s = ft_strnew(var->width + 1);
	if (var->minus == 1)
	{
		ft_strcpy(s, tmp);
		ft_memset(s + ft_strlen(tmp), c, var->width - ft_strlen(tmp));
	}
	else
	{
		ft_memset(s, c, var->width - ft_strlen(tmp));
		ft_strcat(s, tmp);
	}
	free(tmp);
	return (s);
}

char	*ft_del_minus(char *s)
{
	char	*tmp;

	tmp = s;
	s = ft_strnew(ft_strlen(s) - 1);
	s = ft_strcpy(s, tmp + 1);
	free(tmp);
	return (s);
}
