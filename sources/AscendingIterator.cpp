//
// Created by malaklinux on 5/27/23.
//

#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::AscendingIterator::AscendingIterator() : index(0), container(new MagicalContainer()) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : index(other.index),
                                                                                         container(other.container) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container): index(0),
                                                                                            container(&container) {}

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) { return *this; }

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const { return false; }

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const { return false; }

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const { return false; }

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const { return false; }

int MagicalContainer::AscendingIterator::operator*() const { return 0; }

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() { return *this; }

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) { return *this; }

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() { return *this; }

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() { return *this; }

MagicalContainer MagicalContainer::AscendingIterator::getContainer() const { return *container; }

int MagicalContainer::AscendingIterator::getIndex() const { return index; }


