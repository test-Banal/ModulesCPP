/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:48:56 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/11 16:48:58 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            std::cout << (char)std::toupper(argv[i][j]);
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}


//ici utilisation cerr mais on peut aussi utiliser cout pour afficher le message d'erreur
