/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:50:23 by oettaqi           #+#    #+#             */
/*   Updated: 2024/12/01 18:24:47 by othmaneetta      ###   ########.fr       */
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

// char *read_one_line(int fd)
// {
//     static char *reste = NULL; // Contient le reste à traiter
//     char *buf;
//     char *temp;
//     char *resu;
//     int nb_read;

//     if (!reste)
//         reste = ft_strdup(""); // Initialisation si nécessaire
    
//     buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // +1 pour '\0'
//     if (!buf)
//         return NULL;

//     nb_read = 1; // Initialiser à une valeur non nulle pour entrer dans la boucle
//     while (nb_read > 0)
//     {
//         nb_read = read(fd, buf, BUFFER_SIZE);
//         if (nb_read < 0)
//             break;
//         buf[nb_read] = '\0'; // Terminer la chaîne lue
//         temp = ft_strjoin(reste, buf); // Ajouter le buffer à `reste`
//         free(reste); // Libérer l'ancien `reste`
//         reste = temp;

//         if (ft_strchr(reste, '\n')) // Une ligne complète est trouvée
//         {
//             resu = ft_substr(reste, 0, ft_strchr(reste, '\n') - reste); // Extraire la ligne
//             temp = ft_strdup(ft_strchr(reste, '\n') + 1); // Récupérer le nouveau reste
//             free(reste); // Libérer l'ancien `reste`
//             reste = temp;
//             free(buf); // Libérer le buffer
//             return resu; // Retourner la ligne extraite
//         }
//     }

//     // Gérer la fin de fichier ou reste final
//     free(buf); // Libérer le buffer
//     if (*reste) // Si `reste` contient encore des données
//     {
//         resu = ft_strdup(reste);
//         free(reste);
//         reste = NULL;
//         return resu;
//     }
//     free(reste);
//     reste = NULL;
//     return NULL; // Fin du fichier ou erreur
// }


char	*read_one_line(int fd)
{
	static char		*reste;
	int			nb_read;
	char		*buf;
	char		*temp;
	char		*resu;

	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buf)
	{
		free(buf);
		return (0);
	}

	nb_read = -1;
	if (!reste)
		reste = ft_strdup("");
	resu = ft_strdup("");
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		// printf("%s", buf);
		if (nb_read < 0)
            break	;
		temp = ft_strjoin(reste, buf);
		reste = temp;
		if (ft_strchr(reste, '\n'))
		{
			reste[nb_read] = '\0';
			resu = ft_substr(reste, 0, ft_strchr(reste, '\n') - reste);
			reste = ft_strdup(&reste[ft_strchr(reste, '\n') - reste + 1]);
			// printf("%s\n", resu);
			// printf("%s\n", reste);
			reste = temp;
			break;
		}
	}
	if (*reste)
    {
        resu = ft_strdup(reste);
        free(reste);
        reste = NULL;
        return resu;
    }
	return (resu);
}

// int	main()
// {
// 	int fd;

// 	fd = open("test.txt",  O_RDONLY, O_CREAT);
// 	// read_one_line(fd);
// 	// printf("%c",'\n');
// 	// read_one_line(fd);
// 	// read_one_line(fd);

// 	printf("%s\n",read_one_line(fd));
// 	printf("%s\n",read_one_line(fd));
// 	printf("%s\n",read_one_line(fd));
// 	//printf("%s\n",read_one_line(fd));

// 	return(0);
// }
