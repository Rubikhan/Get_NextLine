/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:57:20 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/12 17:05:15 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*a;

	if (s == NULL)
		return ;
	a = (char*)s;
	while (*a != '\0')
	{
		ft_putchar_fd(*a, fd);
		a++;
	}
}
