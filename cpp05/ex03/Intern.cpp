#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {

}

static AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}
AForm* Intern::makeForm(const std::string &formType, const std::string &target) {
    typedef AForm* (*FormCreator)(const std::string &);
    struct FormType {
        std::string name;
        FormCreator creator;
    };

    FormType formTypes[] = {
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPresidential}
    };

    for (int i = 0; i < 3; i++) {
        if (formTypes[i].name == formType) {
            std::cout << "Intern creates " << formType << std::endl;
            return formTypes[i].creator(target);
        }
    }

    std::cout << "Intern cannot create form: " << formType << std::endl;
    return NULL;
}
