/*
Écrivez une classe ScalarConverter contenant une seule méthode statique, « convert », 
qui prendra en paramètre une représentation sous forme de chaîne d'un littéral C++ dans 
sa forme la plus courante et affichera sa valeur dans la série de types scalaires suivante :
• char
• int
• float
• double

Comme cette classe n'a besoin de rien stocker, elle ne doit pas être instanciable par 
les utilisateurs.
À l'exception des paramètres char, seule la notation décimale sera utilisée.
Exemples de littéraux char : « c », « a », etc.

Pour simplifier, veuillez noter que les caractères non affichables ne doivent pas 
être utilisés comme entrées. Si une conversion en char n'est pas affichable, affichez
 un message d'information.

Exemples de littéraux int : 0, -42, 42...
Exemples de littéraux float : 0.0f, -4.2f, 4.2f...
Vous devez également gérer ces pseudo-littéraux (pour la science) : -inff, +inff et nanf.
 Exemples de littéraux doubles : 0.0, -4.2, 4.2...
Vous devez également gérer ces pseudo-littéraux (pour le plaisir) : -inf, +inf et nan. 
Écrivez un programme pour tester le fonctionnement de votre classe.

Vous devez d'abord détecter le type du littéral passé en paramètre, le convertir de chaîne
 à son type réel, puis le convertir explicitement vers les trois autres types de données. 
 Enfin, affichez les résultats comme indiqué ci-dessous.

Si une conversion est incompréhensible ou déborde, affichez un message pour informer 
l'utilisateur que la conversion de type est impossible. Incluez tout en-tête dont vous
 avez besoin pour gérer les limites numériques et les valeurs spéciales.
*/

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
        std::cerr << "Usage: ./convert <literal>" << std::endl;
    return 0;
}

/*
    example usage:    
./convert a
./convert 42
./convert 4.2
./convert 4.2f
./convert nan
./convert nanf
./convert -inf
./convert +inff
*/