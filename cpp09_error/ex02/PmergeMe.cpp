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

void PmergeMe::process(char **argv) {
    std::vector<int> input;

    // parsing
    for (int i = 1; argv[i]; ++i) {
        std::stringstream ss(argv[i]);
        long val;

        // lecture + vérif qu’il n’y a rien d’autre après le nombre
        if (!(ss >> val) || !ss.eof() || val <= 0 || val > INT_MAX) { //ss >> val (convertit/lit en long si ok parfait sinon ca veut dire que : "9e" "9 3" etc)
            std::cerr << "Error" << std::endl; //eof = EndofFile bien a la fin du flux ?
            return;
        }
        input.push_back(static_cast<int>(val));
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
    if (vec.size() <= 1) //petit check des familles, si 0 ou 1 element = deja classe
        return;

    //1) PAring
    std::vector< std::pair<int, int> > pairs; //outil stl avoir une valeur double = deux valeur ? "Je crée un vector qui contient plusieurs paires (donc plusieurs couples de 2 ints)."
    pairs.reserve(vec.size() / 2);              //"alloue la memoire de size / 2 elements, evite reallocations pour pushback"

    bool hasOdd = (vec.size() % 2 != 0);
    int  odd = 0;
    for (std::vector<int>::size_type i = 0; i + 1 < vec.size(); i += 2) {
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    if (hasOdd) {
        odd = vec.back();
    }

    // 2) Tri interne des paires (max en first)
    for (std::vector< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i) { //convention, et size renvoie size_type donc i size_type
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    // 3) cree et initialise chaines
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    mainChain.reserve(pairs.size()); //reserve = pour reserver suffisament de memoire pour eviter une reallocation apres le pushback
    pendChain.reserve(pairs.size());

    for (std::vector< std::pair<int, int> >::size_type i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendChain.push_back(pairs[i].second);
    }

    // 4) Tri récursif sur mianChain
    _fordJohnsonSort(mainChain);

    // 5) insert lower_bound = min
    for (std::vector<int>::size_type i = 0; i < pendChain.size(); ++i) {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), pendChain[i]);
        mainChain.insert(it, pendChain[i]);
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
    if (deq.size() <= 1) //idem check
        return;

    std::deque< std::pair<int, int> > pairs;
    bool hasOdd = (deq.size() % 2 != 0); //idem si nombre pair
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

    for (std::deque<int>::size_type i = 0; i < pendChain.size(); ++i) {
        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), pendChain[i]);
        mainChain.insert(it, pendChain[i]);
    }

    if (hasOdd) {
        std::deque<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), odd);
        mainChain.insert(it, odd);
    }

    deq = mainChain;
}
