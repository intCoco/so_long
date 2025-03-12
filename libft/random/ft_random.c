/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:13 by chuchard          #+#    #+#             */
/*   Updated: 2024/12/14 02:57:50 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // Pour read, write, close
#include <fcntl.h> // Pour open

unsigned int update_seed(unsigned int seed) {
    return (seed * 1103515245 + 12345) & 0x7FFFFFFF; // LCG classique
}

// Fonction principale ft_random
int ft_random(int max) {
    int fd;
    unsigned int seed;
    ssize_t bytes_read;

    if (max <= 0)
        return 0;

    // Ouvre ou crée le fichier pour stocker la graine
    fd = open("save.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0)
        return 0; // En cas d'erreur d'ouverture

    // Essaie de lire la graine depuis le fichier
    bytes_read = read(fd, &seed, sizeof(seed));
    if (bytes_read != sizeof(seed)) {
        // Si le fichier est vide ou invalide, initialise une graine par défaut
        seed = 123456789;
    }

    // Met à jour la graine avec la fonction LCG
    seed = update_seed(seed);

    // Rewind le fichier et écris la nouvelle graine
    lseek(fd, 0, SEEK_SET);
    write(fd, &seed, sizeof(seed));

    // Ferme le fichier
    close(fd);

    // Retourne un nombre pseudo-aléatoire entre 0 et max (exclus)
    return seed % max;
}
