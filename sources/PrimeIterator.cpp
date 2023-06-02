//
// Created by malaklinux on 5/27/23.
//


#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator() : index(0), container(new MagicalContainer()) {}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : index(other.index), container(other.container) {}
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : index(0), container(&container) {}
MagicalContainer::PrimeIterator::~PrimeIterator() = default;
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) { return *this; }
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const { return false; }
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const { return false; }
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const { return false; }
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const { return false; }
int MagicalContainer::PrimeIterator::operator*() const { return 0; }
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() { return *this; }
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int) { return *this; }
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() { return *this; }
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() { return *this; }
MagicalContainer MagicalContainer::PrimeIterator::getContainer() const { return *container; }
int MagicalContainer::PrimeIterator::getIndex() const { return index; }
bool MagicalContainer::PrimeIterator::isPrime(int num) { return false; }


