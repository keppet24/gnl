/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:50:20 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/29 18:43:05 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		n;
	int		i;
	char	*copy;

	i = 0;
	n = ft_strlen(src);
	copy = (char *)malloc((n + 1) * sizeof (char));
	if (!copy)
		return (0);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size2;
	int		i;
	char	*resu;
	int		j;

	size2 = ft_strlen(s2);
	i = 0;
	j = 0;
	resu = malloc(sizeof(char) * (ft_strlen(s1) + size2 + 1));
	if (!resu)
		return (0);
	while (i < ft_strlen(s1))
	{
		resu[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + size2)
	{
		resu[i] = s2[j];
		j++;
		i++;
	}
	resu[i] = '\0';
	return (resu);
}

// int main()
// {
// 	char *s1 = "";
// 	char *s2 = "hey";
// 	printf("%s", ft_strjoin(s1, s2));
// }