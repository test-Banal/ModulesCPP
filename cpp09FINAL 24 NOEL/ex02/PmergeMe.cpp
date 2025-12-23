/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:13:19 by aneumann          #+#    #+#             */
/*   Updated: 2025/12/22 21:20:40 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) {
    (void)src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
    (void)src;
    return *this;
}

PmergeMe::~PmergeMe() {}

static bool isAllDigits(const std::string& s) {
    if (s.empty())
        return false;
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}













void PmergeMe::process(char **argv) {
    std::vector<int> input;

    // parsing

for (int i = 1; argv[i]; ++i) {
    std::string s(argv[i]);

    // (1) Refuse tout sauf [0-9]+
    if (!isAllDigits(s)) {
        std::cerr << "Error" << std::endl;
        return;
    }

    // conversion sûre
    // (note: ici, s est digits-only, donc pas de +/-, pas d'espace)
    long val = std::strtol(s.c_str(), NULL, 10);

    // (positive strict + INT_MAX)
    if (val <= 0 || val > INT_MAX) {
        std::cerr << "Error" << std::endl;
        return;
    }

    input.push_back(static_cast<int>(val));
}
        if (input.size() == 1) {
        std::cerr << "Error only one number ,no sort" << std::endl;
        return;
    }

    if (input.size() >= 2) {
    bool alreadySorted = true;
    for (std::vector<int>::size_type i = 1; i < input.size(); ++i) {
        if (input[i - 1] > input[i]) {
            alreadySorted = false;
            break;
        }
    }
    if (alreadySorted) {
        std::cerr << "Error already sorted " << std::endl;
        return;
    }
}

    //affichage before
    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < input.size(); ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;

    // algo avec container VECTOR
    std::vector<int> vec;
    timeval start_vec, end_vec;

    gettimeofday(&start_vec, NULL);
    vec = input;
    _fordJohnsonSort(vec);
    gettimeofday(&end_vec, NULL);

    long time_vec = (end_vec.tv_sec - start_vec.tv_sec) * 1000000L
                  + (end_vec.tv_usec - start_vec.tv_usec);

    //affichage resultat
    std::cout << "After:  ";
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    //algo avec Deque
    std::deque<int> deq;
    timeval start_deq, end_deq;

    gettimeofday(&start_deq, NULL);
    deq.insert(deq.begin(), input.begin(), input.end());
    _fordJohnsonSort(deq);     
    gettimeofday(&end_deq, NULL);

    long time_deq = (end_deq.tv_sec - start_deq.tv_sec) * 1000000L
                  + (end_deq.tv_usec - start_deq.tv_usec);

    //affichage temps
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << time_vec << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque:  " << time_deq << " us" << std::endl;
}








































void PmergeMe::_fordJohnsonSort(std::vector<int> &vec) { 
    if (vec.size() <= 1)
        return;

    //1) PAring
    std::vector< std::pair<int, int> > pairs;
    pairs.reserve(vec.size() / 2);

    bool hasOdd = (vec.size() % 2 != 0);
    int  odd = 0;
    for (std::vector<int>::size_type i = 0; i + 1 < vec.size(); i += 2) {
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    if (hasOdd) {
        odd = vec.back();
    }

    // 2) Tri interne des paires (max en first)
    for (std::vector< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    // 3) cree et initialise chaines
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    mainChain.reserve(pairs.size());
    pendChain.reserve(pairs.size());

    for (std::vector< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendChain.push_back(pairs[i].second);
    }

    // 4) Tri récursif sur mianChain
    _fordJohnsonSort(mainChain);

    // 5) insert lower_bound = min
    std::vector<size_t> order = _buildJacobsthalInsertionOrder(pendChain.size());
    for (std::vector<size_t>::size_type k = 0; k < order.size(); ++k)
    {
        size_t idx = order[k];
        int value = pendChain[idx];

        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(it, value);
    }

    // 6) si impair , insert impair
    if (hasOdd) {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), odd);
        mainChain.insert(it, odd);
    }

    vec = mainChain;
}

void PmergeMe::_fordJohnsonSort(std::deque<int> &deq) {
    if (deq.size() <= 1)
        return;

    std::deque< std::pair<int, int> > pairs;
    bool hasOdd = (deq.size() % 2 != 0);
    int  odd = 0;

    for (std::deque<int>::size_type i = 0; i + 1 < deq.size(); i += 2) {
        pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
    if (hasOdd) {
        odd = deq.back();
    }

    for (std::deque< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    std::deque<int> mainChain;
    std::deque<int> pendChain;

    for (std::deque< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendChain.push_back(pairs[i].second);
    }

    _fordJohnsonSort(mainChain);

    std::vector<size_t> order = _buildJacobsthalInsertionOrder(pendChain.size());
    for (std::vector<size_t>::size_type k = 0; k < order.size(); ++k)
    {
        size_t idx = order[k];
        int value = pendChain[idx];

        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(it, value);
    }


    if (hasOdd) {
        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), odd);
        mainChain.insert(it, odd);
    }

    deq = mainChain;
}

size_t PmergeMe::_jacobsthal(size_t n)
{
    //ici pour creer la suite de JAcobsthal
    if (n == 0) return 0;
    if (n == 1) return 1;

    size_t a = 0; // J0
    size_t b = 1; // J1
    for (size_t i = 2; i <= n; ++i)
    {
        size_t c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

//pour obtenir l'ordre d'insertion
std::vector<size_t> PmergeMe::_buildJacobsthalInsertionOrder(size_t m)
{
    std::vector<size_t> order;
    if (m == 0)
        return order;

    order.reserve(m);

    order.push_back(0);

    if (m == 1)
        return order;

    size_t prevJ = 1;
    size_t k = 3;

    while (prevJ < m)
    {
        size_t Jk = _jacobsthal(k);
        size_t upper = (Jk < m) ? Jk : m;

        if (upper <= prevJ)
            break;
        for (size_t i = upper; i > prevJ; --i)
            order.push_back(i - 1);

        prevJ = upper;
        ++k;
    }

    //securtie si doublon & check 
    std::vector<bool> seen(m, false);
    std::vector<size_t> clean;
    clean.reserve(m);

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        if (idx < m && !seen[idx])
        {
            seen[idx] = true;
            clean.push_back(idx);
        }
    }

    return clean;
}
