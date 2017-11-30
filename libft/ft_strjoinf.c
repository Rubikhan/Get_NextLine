/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:26:21 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/29 23:24:31 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char const *s2)
{
	char			*a;
	int				b;
	int				c;
	int				d;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	b = ft_strlen(s1);
	c = ft_strlen(s2);
	a = ft_strnew(b + c);
	if (a == NULL)
		return (NULL);
	d = 0;
	a = ft_strcpy(a, s1);
	ft_strcpy(&a[b], s2);
	free(s1);
	return (a);
}
