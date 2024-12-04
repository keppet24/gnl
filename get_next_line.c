/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:46:23 by oettaqi           #+#    #+#             */
/*   Updated: 2024/12/04 14:05:00 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*last_iter(char **stash, char *line)
{
	line = ft_strdup(*stash);
	if (!line)
		return (NULL);
	free(*stash);
	*stash = NULL;
	return (line);	
}

char	*get_a_line(char **temp, char **buf, char **stash, char *line)
{
	line = ft_substr(*stash, 0, ft_strchr(*stash, '\n') - *stash + 1);
	*temp = *stash;
	*stash = ft_strdup(&(*stash)[ft_strchr(*stash, '\n') - *stash + 1]);
	free(*temp);
	free(*buf);
	return (line);
}

void	auxiliary(char **buf, char **temp, char **stash, int nb_read)
{
	(*buf)[nb_read] = 0;
	*temp = *stash;
	*stash = ft_strjoin(*temp, *buf);
	free(*temp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	char		*temp;
	int			nb_read;

	nb_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	if (!stash)
		stash = ft_strdup("");
	while (nb_read > 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0)
			break;
		auxiliary(&buf, &temp, &stash, nb_read);
		if (ft_strchr(stash, '\n'))
			return (get_a_line(&temp, &buf, &stash, line));
	}
	free(buf);
	if (stash)
		return (last_iter(&stash, line));			
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
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	return(0);
}