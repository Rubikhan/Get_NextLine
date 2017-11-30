/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:53:35 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/29 23:18:29 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	full_file(int fd, char **fda, int rv)
{
	char *temp;

	if (!(temp = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((rv = read(fd, temp, BUFF_SIZE)) > 0)
	{
		if (!fda[0])
			fda[0] = ft_strdup(temp);
		else
			fda[0] = ft_strjoinf(fda[0], temp);
		free(temp);
		if (!(temp = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	if (rv == -1)
		return (-1);
	if (*temp != 0)
	{
		fda[0] = ft_strjoin(fda[0], temp);
		free(temp);
		if (!(temp = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	return (0);
}

int	chrnl(char **fda, char **line)
{
	char *chrval;
	char *temp;

	if (!fda[0])
		return (0);
	if ((chrval = ft_strchr(fda[0], '\n')))
	{
		if (!(temp = ft_strnew(chrval - fda[0])))
			return (-1);
		temp = ft_strncpy(temp, fda[0], (chrval - fda[0]));
		fda[0] = chrval + 1;
		chrval = NULL;
		line[0] = ft_strdupf(temp);
		return (1);
	}
	else if (*fda[0])
	{
		line[0] = ft_strdup(fda[0]);
		fda[0] = ft_strnew(0);
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int			rv;
	static char *fda[4864];

	if (fd < 0 || fd > 4864)
		return (-1);
	if (!line || (rv = full_file(fd, &fda[fd], 0)) == -1)
		return (-1);
	rv = chrnl(&fda[fd], line);
	return (rv);
}

/*      int main(int argc, char **argv)      */
/*      {      */
/*          char *str;      */
/*          int fd;      */

/*          fd = open(argv[1], O_RDONLY);      */
/*          while (get_next_line(fd, &str))      */
/*          {      */
/*              printf("%s\n", str);      */
/*              str = NULL;      */
/*          }      */
/*     	 return (26);     */
/*      }      */
