/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:53:35 by smaddux           #+#    #+#             */
/*   Updated: 2017/11/29 19:08:34 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //TESTING
#include <fcntl.h> //FOR TESTING
#include <unistd.h> //CLOSE -- FOR TESTING IN TANDEM WITH OPEN

int full_file(int fd, char **fda, int rv)
{
	char *temp;
	if(!(temp = ft_strnew(BUFF_SIZE)))
			return (-1);
	while ((rv = read(fd, temp, BUFF_SIZE)) > 0)
	{
		if (!fda[0])
			fda[0] = ft_strdup(temp); //CRUCIAL, as it ALLOCATES MEM
		else
			fda[0] = ft_strjoin(fda[0], temp);

		free (temp);
		if(!(temp = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
	}
	if (rv == -1)
		return (-1);
	if (*temp != 0) // ? looks at ft_strnew //MIGHT NOT NEED THIS
	{
		fda[0] = ft_strjoin(fda[0], temp);
		free (temp);
		if(!(temp = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		printf("LAST %s\n", fda[0]); // why didnt this print when passed Cantos?
	}
	return (0);
}

int chrnl(char **fda, char **line)
{
	char *chrval;
	char *temp;

	if(!fda[0]) // see else's ft_strclr
		return(0); // ????
	if ((chrval = ft_strchr(fda[0], '\n')))
	{
		if(!(temp = ft_strnew(chrval - fda[0])))// +1?
			return (-1);
		
		temp = ft_strncpy(temp, fda[0], (chrval - fda[0]));
		fda[0] = chrval + 1;
		chrval = NULL; // ?
		line[0] = ft_strdup(temp);
		free (temp);
		return (1);
	}
	else if (*fda[0])
	{
		line[0] = ft_strdup(fda[0]);
		fda[0] = ft_strnew(0); //THIS IS VERY CRUCIAL
		return (1);
	}
	else //ITS THE END OF FILE?
	{
		line[0] = ft_strdup(fda[0]);
		return (0); // changing this to 1 REALLY fucks shit up
	}
	return (0); //? idk ?? it shouldnt get here?
}

int get_next_line(const int fd, char **line) 
{ 
	if (fd < 0 || fd > 4864) 
		return (-1);
	static char *fda[4864] ; // won't fly for norm, silences valgrind warning BUT maybe make into macro;
	int rv;
	
	if(!line || (rv = full_file(fd, &fda[fd], 0)) == -1)
		return (-1);
	rv =  chrnl(&fda[fd], line); //passing line T_T
	return(rv);
} 

/*    int main(int argc, char **argv)    */
/*    {    */
/*        char *str;    */
/*        int fd;    */

/*        fd = open(argv[1], O_RDONLY);    */
/*        while (get_next_line(fd, &str))    */
/*        {    */
/*            printf("%s\n", str);    */
/*            str = NULL;    */
/*        }    */
/*   	 return (26);   */
/*    }    */

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
