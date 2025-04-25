/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:22:28 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 16:07:56 by aneumann         ###   ########.fr       */
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
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string str = argv[i];

            for (std::string::iterator it = str.begin(); it != str.end(); ++it)
            {
                std::cout << static_cast<char>(std::toupper(*it));
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
//         return 1;
//     }
//     else
//     {
//         for (int i = 1; i < argc; i++)
//         {
//             for (int j = 0; argv[i][j] != '\0'; j++)
//             {
//                 std::cout << (char)std::toupper(argv[i][j]);
//             }
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }

//        std::cout << std::endl; saut de ligne
//cerr mais on peut aussi utiliser cout pour afficher le message d'erreur mais sinon std::cout << ok 