/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:32:52 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 15:33:39 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**tbh not sure why its size + 1
**maybe something to do with null terminators of strings?
*/

char	*ft_strnew(size_t size)
{
	char	*a;

	a = malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (size + 1));
	return (a);
}
