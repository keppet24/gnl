/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:43:18 by othmaneetta       #+#    #+#             */
/*   Updated: 2024/12/02 15:44:00 by oettaqi          ###   ########.fr       */
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

// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char	*temp;
// 	char	*buf;
// 	char	*line;
// 	int		nb_read;

// 	temp = ft_strdup("");
// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 	{
// 		free(buf);
// 		return (NULL);
// 	}
// 	nb_read = 1;
// 	while (nb_read > 0)
// 	{
// 		nb_read = read(fd, buf, BUFFER_SIZE);
// 		buf[nb_read] = 0;
// 		stash = ft_strjoin(temp, buf);
// 		free(temp);
// 		temp = stash;
// 		if (ft_strchr(stash, '\n'))
// 		{
// 			line = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1);
// 			stash = ft_strdup(&stash[ft_strchr(stash, '\n') - stash + 1 ]);
// 			temp = stash;
// 			break;
// 		}
// 	}
// 	if (nb_read == 0)
// 		return (stash);
// 	free(buf);
// 	return (line);
// } 

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*temp;
	char	*buf;
	char	*line;
	int		nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0)
			break;
		buf[nb_read] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(stash, '\n'))
		{
			line = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1);
			temp = stash;
			stash = ft_strdup(&stash[ft_strchr(stash, '\n') - stash + 1]);
			free(temp);
			free(buf);
			return (line);
		}
	}
	free(buf);
	if (stash && *stash)
	{
		line = stash;
		stash = NULL;
		free(stash);
		return (line);
	}
	free(stash);
	return (NULL);
}


int	main()
{
	int fd;
	char *s;

	fd = open("test.txt",  O_RDONLY);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	fd = -1;
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	return(0);
}
