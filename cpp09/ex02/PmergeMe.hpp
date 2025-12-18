#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <algorithm>
# include <climits>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& src);
    ~PmergeMe();

    static void process(char **argv);

private:
    static void _fordJohnsonSort(std::vector<int> &vec);
    static void _fordJohnsonSort(std::deque<int> &deq);
};

#endif

