#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN {
public:
    static int evaluate(const std::string &expression);

private:
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
    ~RPN();
};

#endif

