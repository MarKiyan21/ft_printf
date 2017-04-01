/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:03:22 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:03:59 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_size(uintmax_t n, int base)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static char		*calc(uintmax_t n, int i, char *s, int base)
{
	uintmax_t		nb;

	nb = n;
	while (nb > 0)
	{
		if (base >= 10 && nb % base >= 10)
			s[i] = ((nb % base - 10 + 97));
		else
			s[i] = ((nb % base + 48));
		nb = nb / base;
		i++;
	}
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}

char			*my_unsigned_itoa_base(uintmax_t n, int base)
{
	char			*s;
	int				i;
	int				len;

	i = 0;
	len = ft_size(n, base);
	s = (char *)ft_memalloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	if (n == 0)
	{
		s[i] = 48;
		s[i + 1] = '\0';
		return (&s[i]);
	}
	s = calc(n, i, s, base);
	return (s);
}
