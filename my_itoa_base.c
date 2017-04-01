/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:03:04 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 18:03:05 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(intmax_t n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static int	ft_isneg(intmax_t n)
{
	int				flag;

	flag = 0;
	if (n < 0)
		flag = 1;
	return (flag);
}

static char	*calc(intmax_t n, int i, char *s, int base)
{
	int				isneg;
	uintmax_t		nb;

	isneg = ft_isneg(n);
	if (isneg == 1)
		nb = n * -1;
	else
		nb = n;
	while (nb > 0)
	{
		if (nb % base > 10)
			s[i] = ((nb % base - 10 + 97));
		else
			s[i] = ((nb % base + 48));
		nb = nb / base;
		i++;
	}
	if (isneg == 1)
	{
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}

char		*my_itoa_base(intmax_t n, int base)
{
	char			*s;
	int				i;
	int				len;

	i = 0;
	len = ft_size(n, base);
	if (!(s = (char *)ft_memalloc(sizeof(char) * len)))
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
