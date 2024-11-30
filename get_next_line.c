/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:50:23 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:56 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*part(char *particulier)
{
	particulier = malloc(sizeof(char) * 1);
	if (!particulier)
		return (0);
	particulier[0] = 0;
	return (particulier);
}

char	*ft_substr(char *s, int start, size_t len)
{
	unsigned int	i;
	char			*resu;
	char			*particulier;

	particulier = NULL;
	i = 0;
	if (s[0] == 0)
		return (part(particulier));
	if (len == 0)
		return (part(particulier));
	if (start >= ft_strlen(s))
		return (part(particulier));
	if ((ft_strlen(s) - start - 1) < len)
		len = ft_strlen(s) - start;
	resu = malloc(sizeof(char) * (len + 1));
	if (!resu)
		return (0);
	while (i < (unsigned int)len)
	{
		resu[i] = s[start + i];
		i++;
	}
	resu[i] = 0;
	return (resu);
}

char	*read_one_line(int fd)
{
	static char		*reste;
	int			nb_read;
	char		*buf;
	char		*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buf)
	{
		free(buf);
		return (0);
	}
	nb_read = -1;
	reste = ft_strdup("");
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		temp = ft_strjoin(reste, buf);
		reste = temp;
		if (ft_strchr(reste, '\n'))
		{
			reste = ft_substr(reste, 0, ft_strchr(reste, '\n') - reste + 1) ;
			break;
		}
	}
	return (reste);
}

int	main()
{
	int fd;

	fd = open("test.txt",  O_RDONLY, O_CREAT);
	printf("%s\n",read_one_line(fd));
	// printf("%s\n",read_one_line(fd));

	return(0);
}
