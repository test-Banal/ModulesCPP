#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <cstdlib>    // rand(), srand()
#include <typeinfo>   // std::bad_cast, typeid
#include <ctime>      // time() si vous utilisez srand(time(NULL))

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif