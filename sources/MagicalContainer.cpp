//
// Created by malaklinux on 5/27/23.
//


#include "MagicalContainer.hpp"
#include "cmath"

using namespace ariel;

MagicalContainer::MagicalContainer() : vecElements(), vecPrime() {
}

void MagicalContainer::addElement(int element) {
    vecElements.push_back(element);
}

bool MagicalContainer::removeElement(int element) {
    for (auto it = vecElements.begin(); it != vecElements.end(); ++it) {
        if (*it == element) {
            vecElements.erase(it);
            return true; // Element was found and removed
        }
    }
    return false; // Element was not found
}


size_t MagicalContainer::size() const {
    return vecElements.size();
}

vector<int> MagicalContainer::getElements() {
    return vecElements;
}

void MagicalContainer::addAndSortElement(int element, vector<int> &vec) {
    auto it = vec.begin();

    vec.insert(it, element);
}

bool MagicalContainer::isPrime(int number) {
    if (number == 2) {
        return true;
    }
    if (number <= 1 || number % 2 == 0) {
        return false;
    }
    int i = 3;
    while (i <= sqrt(number)) {
        if (number % i == 0) {
            return false;
        }
        i += 2;
    }
    return true;
}

int MagicalContainer::searchElementAt(int element, const vector<int> &vec) {
    auto it = std::find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }
    return -1;
}