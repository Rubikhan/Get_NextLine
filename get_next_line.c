/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:53:35 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/29 15:54:28 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //TESTING
#include <fcntl.h> //FOR TESTING
#include <unistd.h> //CLOSE -- FOR TESTING IN TANDEM WITH OPEN

char *olas(char *fdsingle)
{
	char *postnl;
	int len = ft_strlen(fdsingle);
	int n;
	char *tmp = ft_strnew(len);
	n = 0;
	while(fdsingle[n] != '\n' && fdsingle[n]) //##//
		n++;
	postnl = ft_strnew(len - n);
	tmp = ft_strsub(fdsingle, 0, n);
	postnl = ft_strsub(fdsingle, n + 1, len - n);
	ft_strclr(fdsingle);
	fdsingle = ft_strcpy(fdsingle, postnl);
//	printf("fdsingle: %s\n", fdsingle);
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
//	printf("FIRSTENTRY: %s", str);
	if (fda[0] && ft_strchr(fda[0], '\n'))
	{
		line[0] = olas(fda[0]);
		return(1);
	}
	else if(fda[0])
		fda[0] = ft_strjoin(fda[0], str);
	else
		fda[0] = ft_strdup(str);;
if (rv == 0)
	{
		line[0] = olas(fda[0]);
		return (0);
	}
	free(str);
	if(!(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(chrval = ft_strchr(fda[0], '\n')) && (rv != 0))
	{
		rv = read(fd, str, BUFF_SIZE);
		if(rv == 0)
			break;
		fda[0] = ft_strjoin(fda[0], str); //##//
		free(str);
		if(!(str = ft_strnew(BUFF_SIZE)))
			return (-1);

	}
	line[0] = olas(fda[0]);
	free (str);
	return rv == -1  ? 0 : 1; //Return value fuckery for 42FileChecker basic tests 
}

int get_next_line(const int fd, char **line) 
{ 
	static char *fda[4864] ; // won't fly for norm, silences valgrind warning BUT maybe make into macro;
	int rv;
	
	if(!line || fd < 0)
		return (-1);
	rv = first_entry(fd, line, &fda[fd], 0); //##//
//	printf("rv: %d\n", rv);
	return(rv);

} 

/* int main(int argc, char **argv) */
/* { */
/*     char *str; */
/*     int fd; */

/*     fd = open(argv[1], O_RDONLY); */
/*     while (get_next_line(fd, &str)) */
/*     { */
/*         printf("%s\n", str); */
/*         str = NULL; */
/*     } */
/* } */

/*       int main(int argc, char *argv[])       */
/*       {       */
/*       	int fdone;       */
/*       	int fdtwo;       */
/*       	char *str;        */

/*       	fdone = open(argv[1], O_RDONLY);       */
/*       	fdtwo = open(argv[1], O_RDONLY);       */

/*       	str = NULL;        */

/*       	int rv = get_next_line(fdone, &str);       */
/*       //	printf("\nin between gnl calls\n");       */
/*       	printf("str: %s\n", str);       */
/* 		printf("rv: %d\n", rv); */
/*       	free(str);       */
/*       	str = NULL;       */
/*       	get_next_line(fdone, &str);       */
/*       	printf("str: %s\n", str);       */
/* 		printf("rv: %d\n", rv); */
/*       	free(str);       */
/*       	str = NULL;       */
/*       	get_next_line(fdone, &str);       */
/*       	printf("str: %s\n", str);       */
/* 		printf("rv: %d\n", rv); */
/*       	free(str);       */
/*       	str = NULL;       */
/*       	get_next_line(fdone, &str);       */
/*       	printf("str: %s\n", str);       */
/* 		printf("rv: %d\n", rv); */
/*       //	printf("end of main\n");       */
/*       	return (rv);       */
/*       }       */
