/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:13:05 by aneumann          #+#    #+#             */
/*   Updated: 2025/12/22 21:04:42 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>  // strtol
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <climits>

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

    static size_t _jacobsthal(size_t n);
    static std::vector<size_t> _buildJacobsthalInsertionOrder(size_t m);
};

#endif

