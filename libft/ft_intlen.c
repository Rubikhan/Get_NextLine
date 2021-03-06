/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:03:41 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 14:04:33 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	int a;
	int b;

	a = 10;
	b = 1000000000;
	while (n <= b && b >= 10)
	{
		a--;
		b = b / 10;
	}
	return (a);
}
