//
// Created by malaklinux on 5/27/23.
//


#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::MagicalContainer() : vec(0) {
}

void MagicalContainer::addElement(int element) {
    vec.push_back(element);
}

bool MagicalContainer::removeElement(int element) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it == element) {
            vec.erase(it);
            return true; // Element was found and removed
        }
    }
    return false; // Element was not found
}


size_t MagicalContainer::size() const {
    return vec.size();
}

vector<int> MagicalContainer::getElements() {
    return vec;
}