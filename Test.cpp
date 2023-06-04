#include "doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

using namespace doctest;

#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Testing adding and removing elements...") {
    MagicalContainer container;

    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    CHECK(container.size() == 3);

    container.removeElement(10);

    CHECK(container.size() == 2);
}

TEST_CASE("Testing iterator functionality...") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    SUBCASE("AscendingIterator") {
        MagicalContainer::AscendingIterator it(container);

        CHECK(*it == 5);
        ++it;
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 15);
    }

    SUBCASE("SideCrossIterator") {
        MagicalContainer::SideCrossIterator it(container);

        CHECK(*it == 5);
        ++it;
        CHECK(*it == 15);
        ++it;
        CHECK(*it == 10);
    }

    SUBCASE("PrimeIterator") {
        MagicalContainer::PrimeIterator it(container);

        CHECK(*it == 5);
        ++it;
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 15);
        ++it;
    }
}

TEST_CASE("Testing container size...") {
    MagicalContainer container;

    SUBCASE("Empty container") {
        CHECK(container.size() == 0);
    }

    SUBCASE("Container with elements") {
        container.addElement(5);
        container.addElement(10);

        CHECK(container.size() == 2);
    }
}

TEST_CASE("Testing getting container elements...") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    const std::vector<int>& elements = container.getElements();

    CHECK(elements.size() == 3);
    CHECK(elements[0] == 5);
    CHECK(elements[1] == 10);
    CHECK(elements[2] == 15);
}

TEST_CASE("Testing removing a non-existing element...") {
    MagicalContainer container;

    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    CHECK_THROWS(container.removeElement(20));

    const std::vector<int>& elements = container.getElements();

    CHECK(elements.size() == 3);
    CHECK(elements[0] == 5);
    CHECK(elements[1] == 10);
    CHECK(elements[2] == 15);
}