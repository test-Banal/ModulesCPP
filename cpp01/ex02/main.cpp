/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:09:58 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/12 21:42:36 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string variable = "HI THIS IS BRAIN";
	std::string* variablePTR = &variable;
	std::string& variableREF = variable;

	std::cout << "L'adresse de variable est (" << &variable << ") et son contenu est    : " << variable << std::endl; 
	std::cout << "L'adresse de variablePTR est (" << variablePTR << ") et son contenu est : " << *variablePTR << std::endl;
	std::cout << "L'adresse de variableREF est (" << &variableREF << ") et son contenu est : " << variableREF << std::endl;
	std::cout << "\n";

	return 0;
}	
