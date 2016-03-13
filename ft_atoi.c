/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 10:23:21 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/09 17:46:03 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	unsigned int	nb;
	unsigned int	limit;
	int				signe;

	signe = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\r' ||
			*nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			signe = -1;
	limit = (signe == 1) ? FT_INT_MAX : (unsigned int)FT_INT_MIN * -1;
	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (nb * 10 > limit)
			return (limit);
		nb *= 10;
		if (nb + (*nptr - '0') > limit)
			return (limit);
		nb += *nptr++ - '0';
	}
	return ((int)nb * signe);
}
