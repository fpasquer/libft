/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:09:27 by fpasquer          #+#    #+#             */
/*   Updated: 2017/07/13 09:09:38 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					*get_tmp(size_t width)
{
	static void				*tmp = NULL;

	if (tmp == NULL)
		tmp = ft_memalloc(width);
	return (tmp);
}

static void					switch_value(void *left, void *right, size_t width)
{
	void					*tmp;

	if ((tmp = get_tmp(width)) == NULL)
		return ;
	ft_memcpy(tmp, right, width);
	ft_memcpy(right, left, width);
	ft_memcpy(left, tmp, width);
}

void						loop_qsort(void *base, size_t nel, size_t width,
		int (*compar)(const void *, const void *))
{
	void					*pivot;
	void					*end;
	void					*right;
	void					*left;

	end = (void*)base + (nel - 1) * width;
	right = end;
	left = base;
	pivot = base;
	if (nel <= 1 || width <= 0 || end < base)
		return ;
	while (left < right)
	{
		while (left < right && compar(pivot, right) < 0)
			right = (void*)right - width;
		switch_value(left, right, width);
		pivot = right;
		while (left < right && compar(pivot, left) >= 0)
			left = (void*)left + width;
		switch_value(left, right, width);
		pivot = left;
	}
	loop_qsort(base, (left - base) / width, width, compar);
	loop_qsort((void*)left + width, (end - left) / width, width, compar);
}

void						ft_qsort(void *base, size_t nel, size_t width,
		int (*compar)(const void *, const void *))
{
	void					*tmp;

	if (nel <= 1)
		return ;
	loop_qsort(base, nel, width, compar);
	if ((tmp = get_tmp(0)) != NULL)
		ft_memdel((void**)&tmp);
}