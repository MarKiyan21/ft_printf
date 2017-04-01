/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:25:46 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 17:25:49 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*bits_help_1(char *s, wint_t *i, int *x, int *y)
{
	s[(*y)++] = (char)(((i[(*x)] & 0x07c0) >> 6) + 0xc0);
	s[(*y)++] = (char)((i[(*x)] & 0x003F) + 0x80);
	return (s);
}

char	*bits_help_2(char *s, wint_t *i, int *x, int *y)
{
	s[(*y)++] = (char)(((i[(*x)] & 0xF000) >> 12) + 0xE0);
	s[(*y)++] = (char)(((i[(*x)] & 0x0Fc0) >> 6) + 0x80);
	s[(*y)++] = (char)((i[(*x)] & 0x003F) + 0x80);
	return (s);
}

char	*bits_help_3(char *s, wint_t *i, int *x, int *y)
{
	s[(*y)++] = (char)(((i[(*x)] & 0x1c0000) >> 18) + 0xF0);
	s[(*y)++] = (char)(((i[(*x)] & 0x03F000) >> 12) + 0x80);
	s[(*y)++] = (char)(((i[(*x)] & 0x0Fc0) >> 6) + 0x80);
	s[(*y)++] = (char)((i[(*x)] & 0x003F) + 0x80);
	return (s);
}
