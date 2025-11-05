/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:46:17 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/05 15:06:06 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include <iostream>
#include <string>

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
return 0;
}

// const char * e = "chaine4" ;
// const char * f = "chaine3" ;
// ::swap(e, f);
// std::cout << "e = " << e << ", f = " << f << std::endl;
// std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
// std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

//inline const char* const& min(const char* const& a, const char* const& b) {
//     return (std::strcmp(b, a) < 0) ? b : a;
// }
// inline const char* const& max(const char* const& a, const char* const& b) {
//     return (std::strcmp(a, b) < 0) ? b : a;
// }

/*
fonctions inlines = just overload  = pas functions de remplacements.
Les overlaods sont compatibles avec des templates. Le compilateur choisira l'overload le plus specifique
quand le type conrrespond exactement sinon, il utilisera le template.

CAR AVEC CHAR* ca compile mais ne fonctionne pas car ca compare les adresses memoires pas sur le contenu!

*/