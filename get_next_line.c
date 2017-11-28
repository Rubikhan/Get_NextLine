/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:53:35 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/28 00:46:43 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //TESTING
#include <fcntl.h> //FOR TESTING
#include <unistd.h> //CLOSE -- FOR TESTING IN TANDEM WITH OPEN

char *olas(char *fdsingle)
{
	char *postnl;
//	printf("fdsingle: %s, length:%zu\n", fdsingle, ft_strlen(fdsingle));
	int len = ft_strlen(fdsingle);
//	printf("len: %d\n", len);
	int n;
	char *tmp = ft_strnew(len);
//	printf("fdsingle %s\n", fdsingle);
	n = 0;
	while(fdsingle[n] != '\n')
		n++;
	postnl = ft_strnew(len - n);
//	printf("n:%d\n", n);
	tmp = ft_strsub(fdsingle, 0, n);
	postnl = ft_strsub(fdsingle, n + 1, len - n);
	ft_strclr(fdsingle);
	fdsingle = ft_strcpy(fdsingle, postnl);
		
//	printf("tmp: %s\n", tmp);
	return (tmp);
}

/*
** type 'ulimit -n' in bash 
** HOWEVER, someone with sudo privleges can increase this
** So not completely portable in light of that fact
*/

static int first_entry(int fd, char **line, char **fda, int rv)
{
	char *str;
	char *chrval;
	
	if(!(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	if((rv = read(fd, str, BUFF_SIZE)) == -1) 
		return (-1);
//	printf("str %s\n", str);
	if(fda[0])
		fda[0] = ft_strjoin(fda[0], str);
	else
		fda[0] = ft_strdup(str);;
	free(str);
	if(!(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(chrval = ft_strchr(fda[0], '\n')) && (rv != 0))
	{
		rv = read(fd, str, BUFF_SIZE);
//		printf("str %s\n", str);
		fda[0] = ft_strjoin(fda[0], str);
//		printf("fda[0] %s\n", fda[0]);
		free(str);
		if(!(str = ft_strnew(BUFF_SIZE)))
			return (-1);

	}
//	fda[0] = ft_strcat(fda[0], "dood");
//	printf("fda[0] %s\n", fda[0]);
//	free(fda[0]);
//	printf("line[0]b4: %s\n", line[0]);
	line[0] = olas(fda[0]);
//	printf("line[0]after: %s\n", line[0]);
//	printf("after fda[0] %s\n", fda[0]);
	free (str);
	return (rv);
}

int get_next_line(const int fd, char **line) 
{ 
	char *fda[4864];
	int rv;
	
	if(!line || fd < 0)
		return (-1);
	rv = first_entry(fd, line, &fda[fd], 0);
//	printf("final %d\n", rv);
	return(rv);
} 

int main(int argc, char *argv[])
{
	int fdone;
	int fdtwo;
	char *str; 

	fdone = open(argv[1], O_RDONLY);
	fdtwo = open(argv[1], O_RDONLY);

	str = NULL; 

	get_next_line(fdone, &str);
//	printf("\nin between gnl calls\n");
	printf("str: %s\n", str);
	free(str);
	str = NULL;
	get_next_line(fdone, &str);
	printf("str: %s\n", str);
//	printf("end of main\n");
	return (26);
}
