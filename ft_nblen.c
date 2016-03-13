/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:07:10 by fpasquer          #+#    #+#             */
/*   Updated: 2016/03/04 14:03:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_nblen(long long int nb)
{
	size_t				len;

	len = 1;
	while (nb != 0)
	{
		len++;
		nb = nb > 0 ? nb / 10 : nb * 10;
	}
	return (len);
}