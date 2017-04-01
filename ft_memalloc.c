/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:17:27 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/31 11:11:17 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void			*a;
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if ((a = (void*)malloc(size)) == NULL)
		return (NULL);
	tmp = a;
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return (a);
}
