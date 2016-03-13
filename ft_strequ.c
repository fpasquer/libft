/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 08:53:41 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/01 09:55:19 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2) == 0 ? 1 : 0);
}