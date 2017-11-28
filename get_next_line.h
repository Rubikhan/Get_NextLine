/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 20:46:33 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/28 00:44:58 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include "./libft/libft.h"

#define BUFF_SIZE 200

int get_next_line(const int fd, char **line);

#endif
