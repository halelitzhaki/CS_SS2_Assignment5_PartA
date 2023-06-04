#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::MagicalContainer() {
}

void MagicalContainer::addElement(int element) {
    _elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    int result = 0;
    for(int _element : _elements) if (element == _element) result = 1;
    if(result == 0) throw runtime_error("not in elements");
    _elements.pop_back();
}

int MagicalContainer::size() const {
    return _elements.size();
}

const std::vector<int>& MagicalContainer::getElements() const {
    return _elements;
}

/**********************
 * Ascending Iterator *
**********************/

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container, int index)
: container(container), currentIndex(index) {

}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
: container(container), currentIndex(0) {

}


bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return false;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container._elements[(unsigned long) currentIndex];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++currentIndex;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return *this;
}

const MagicalContainer& MagicalContainer::AscendingIterator::getContainer() const {
    return this->container;
}

/***********************
 * Side Cross Iterator *
***********************/

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container, int leftIndex, int rightIndex, bool leftToRight)
: container(container), leftIndex(leftIndex), rightIndex(rightIndex), leftToRight(leftToRight) {

}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
: container(container), leftIndex(0), rightIndex(container.size() - 1), leftToRight(container.size() > 0 ? 1 : 0) {

}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return false;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return leftToRight ? container._elements[(unsigned long) leftIndex] : container._elements[(unsigned long) rightIndex];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (leftToRight) ++leftIndex;
    else --rightIndex;
    leftToRight = !leftToRight;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return *this;
}

const MagicalContainer& MagicalContainer::SideCrossIterator::getContainer() const {
    return this->container;
}

/******************
 * Prime Iterator *
******************/

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container, int index)
: container(container), currentIndex(index) {
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
: container(container), currentIndex(0) {
}

bool MagicalContainer::PrimeIterator::isPrime(int num) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return false;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return container._elements[(unsigned long) currentIndex];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    ++currentIndex;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return *this;
}

const MagicalContainer& MagicalContainer::PrimeIterator::getContainer() const {
    return this->container;
}
