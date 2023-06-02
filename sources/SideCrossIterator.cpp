//
// Created by malaklinux on 5/27/23.
//


#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator() : frontIndex(0), backIndex(0), container(new MagicalContainer()) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : frontIndex(other.frontIndex),
                                                                       backIndex(other.backIndex),
                                                                       container(other.container) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : frontIndex(0), backIndex(0),
                                                                          container(&container) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) { return *this; }

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const { return false; }

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const { return false; }

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const { return false; }

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const { return false; }

int MagicalContainer::SideCrossIterator::operator*() const { return 0; }

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() { return *this; }

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) { return *this; }

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() { return *this; }

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() { return *this; }

MagicalContainer MagicalContainer::SideCrossIterator::getContainer() const { return *container; }

int MagicalContainer::SideCrossIterator::getFrontIndex() const { return frontIndex; }

int MagicalContainer::SideCrossIterator::getBackIndex() const { return backIndex; }
