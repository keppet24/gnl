/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:50:25 by oettaqi           #+#    #+#             */
/*   Updated: 2024/12/02 19:22:46 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif


# include <fcntl.h>  
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
char	*ft_strchr(char *s, int c);
size_t		ft_strlen(char *str);


 #endif
