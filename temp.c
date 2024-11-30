#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int main() {
//     char *s = "salut";
//     char *pos = strchr(s, 'u'); // Trouver la position de 'u' dans la chaîne
//     if (pos != NULL) {
//         size_t len = pos - s; // Calculer la longueur jusqu'à 'u'
//         char *result = malloc(len + 1); // Allouer de la mémoire pour le résultat
//         if (result != NULL) {
//             strncpy(result, s, len); // Copier les caractères avant 'u'
//             result[len] = '\0'; // Ajouter le caractère de fin de chaîne
//             printf("Résultat: %s\n", result); // Afficher le résultat
//             free(result); // Libérer la mémoire allouée
//         }
//     } else {
//         // Si 'u' n'est pas trouvé, copier toute la chaîne ou gérer le cas
//         printf("Le caractère 'u' n'est pas présent dans la chaîne.\n");
//     }
//     return 0;
// }

int	main()
{
	char *s = "salut";
char *pos = strchr(s, 'u'); // Trouver la position de 'u' dans la chaîne

if (pos != NULL) {
    int index = pos - s; // Calculer l'indice de 'u' dans la chaîne
    printf("Le caractère 'u' est à l'indice %d\n", index);
} else {
    printf("Le caractère 'u' n'est pas présent dans la chaîne.\n");
}

	return (0);
}