/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:50:23 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/29 19:12:56 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_one_line(int fd)
{
	static char	*reste;
	int			nb_read;
	char		*buf;
	char		*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	nb_read = -1;
	reste = ft_strdup("");
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		temp = ft_strjoin(reste, buf);
		reste = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (reste);
}

int	main()
{
	int fd;

	fd = open("test.txt",  O_RDONLY, O_CREAT);
	printf("%s",get_next_line(fd));
	return(0);
}
