//
// Created by malaklinux on 5/27/23.
//
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;
TEST_SUITE("Test MagicalContainer class") {
    MagicalContainer container;
    int SIZE = 50;

    TEST_CASE("Test addElement function") {
        //Adding 50 element.
        int i = 0;
        while (i < SIZE) {
            CHECK_NOTHROW(container.addElement(i));
            CHECK_EQ(container.getElements().back(), i);
            CHECK_EQ(container.size(), i + 1);
            i++;
        }
    }

    TEST_CASE("Test removeElement function") {
        int size = SIZE;
        int i = 10;
        while (i < SIZE) {
            CHECK_FALSE(!container.removeElement(i));
            CHECK_EQ(container.size(), --size);
            i++;
        }
        CHECK_THROWS(container.removeElement(SIZE));
    }

    TEST_CASE("Test size function") {
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        CHECK_EQ(container.size(), 15);
    }


    TEST_CASE("Test getElements function") {
        MagicalContainer container1;
        container1.addElement(17);
        container1.addElement(2);
        vector<int> expected_elements = {17, 2};
        CHECK_EQ(container1.getElements(), expected_elements);
    }
}

//****************************************************************************************

/*
 * 1,2,4,5,14

• Ascending: 1,2,4,5,14
  operator> should return true on 5>2, 14>1

• prime: 2,5
  operator> should return true on 5>2

• cross: 1,14,2,5,4
  operator> should return true on 5>14, 2>1, 4>14
 */

TEST_SUITE("Test AscendingIterator class") {
    MagicalContainer container;

    TEST_CASE("Add Elements To The Container") {
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);
    }

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(container);

    TEST_CASE("Test operator* function") {
        CHECK_EQ(*ascIter.begin(), 1);  // The smallest element
        ascIter++;
        CHECK_EQ(*ascIter, 2);
        ascIter++;
        CHECK_EQ(*ascIter, 4);
        ascIter++;
        CHECK_EQ(*ascIter, 5);
        ascIter++;
        CHECK_EQ(*ascIter, 14);  // The largest element
        ascIter++;
        CHECK_THROWS_AS(*ascIter, out_of_range);  // Trying to dereference end
    }

    TEST_CASE("Test operator++ function") {
        *ascIter.begin();
        ++ascIter;
        CHECK_EQ(*ascIter, 2);
        ++ascIter;
        CHECK_EQ(*ascIter, 4);
        ++ascIter;
        CHECK_EQ(*ascIter, 5);
        ++ascIter;
        CHECK_EQ(*ascIter, 14);
        CHECK_THROWS_AS(++ascIter, out_of_range);  // Trying to increment past the end
    }

    TEST_CASE("Test end function") {
        CHECK_EQ(*ascIter.end(), 14);
    }

    TEST_CASE("Test begin function") {
        CHECK_EQ(*ascIter.begin(), 1);
    }

    TEST_CASE("Test operator= function") {
        *ascIter.begin();
        *ascIter2.begin();
        CHECK_NOTHROW(ascIter = ascIter2);  // Assignment operator
        CHECK_EQ(*ascIter, *ascIter2); // They should point to the same element
    }

    TEST_CASE("Test operator== function") {
        *ascIter.begin();
        *ascIter2.begin();
        CHECK_EQ(ascIter == ascIter2, true);  // Both at the beginning
        ++ascIter;
        CHECK_EQ(ascIter == ascIter2, false);  // ascIter moved forward
        ++ascIter2;
        CHECK_EQ(ascIter == ascIter2, true);  // Both moved forward
    }

    TEST_CASE("Test operator!= function") {
        *ascIter.begin();
        *ascIter2.begin();
        CHECK_EQ(ascIter != ascIter2, false);  // Both at the beginning
        ++ascIter;
        CHECK_EQ(ascIter != ascIter2, true);  // ascIter moved forward
        ++ascIter2;
        CHECK_EQ(ascIter != ascIter2, false);  // Both moved forward
    }

    TEST_CASE("Test operator> and operator< function") {
        *ascIter.begin();
        *ascIter2.begin();
        ++ascIter;

        CHECK_EQ(ascIter > ascIter2, true);  // ascIter is greater
        CHECK_EQ(ascIter2 < ascIter, true);  // ascIter2 is less
    }
}

//****************************************************************************************

TEST_SUITE("Test SideCrossIterator class") {
    MagicalContainer container;

    TEST_CASE("Add Elements To The Container") {
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);
    }

    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::SideCrossIterator crossIter2(container);

    TEST_CASE("Test operator* function") {
        CHECK_EQ(*crossIter.begin(), 1);  // The smallest element
        crossIter++;
        CHECK_EQ(*crossIter, 14);
        crossIter++;
        CHECK_EQ(*crossIter, 2);
        crossIter++;
        CHECK_EQ(*crossIter, 5);
        crossIter++;
        CHECK_EQ(*crossIter, 4);  // The largest element
        crossIter++;
        CHECK_THROWS_AS(*crossIter, out_of_range);  // Trying to dereference end
    }

    TEST_CASE("Test operator++ function") {
        *crossIter.begin();
        ++crossIter;
        CHECK_EQ(*crossIter, 14);
        ++crossIter;
        CHECK_EQ(*crossIter, 2);
        ++crossIter;
        CHECK_EQ(*crossIter, 5);
        ++crossIter;
        CHECK_EQ(*crossIter, 4);
        CHECK_THROWS_AS(++crossIter, out_of_range);  // Trying to increment past the end
    }

    TEST_CASE("Test end function") {
        CHECK_EQ(*crossIter.end(), 4);
    }

    TEST_CASE("Test begin function") {
        CHECK_EQ(*crossIter.begin(), 1);
    }

    TEST_CASE("Test operator= function") {
        *crossIter.begin();
        *crossIter2.begin();
        CHECK_NOTHROW(crossIter = crossIter2);  // Assignment operator
        CHECK_EQ(*crossIter, *crossIter2); // They should point to the same element
    }

    TEST_CASE("Test operator== function") {
        *crossIter.begin();
        *crossIter2.begin();
        CHECK_EQ(crossIter == crossIter2, true);  // Both at the beginning
        ++crossIter;
        CHECK_EQ(crossIter == crossIter2, false);  // crossIter moved forward
        ++crossIter2;
        CHECK_EQ(crossIter == crossIter2, true);  // Both moved forward
    }

    TEST_CASE("Test operator!= function") {
        *crossIter.begin();
        *crossIter2.begin();
        CHECK_EQ(crossIter != crossIter2, false);  // Both at the beginning
        ++crossIter;
        CHECK_EQ(crossIter != crossIter2, true);  // crossIter moved forward
        ++crossIter2;
        CHECK_EQ(crossIter != crossIter2, false);  // Both moved forward
    }

    TEST_CASE("Test operator> and operator< function") {
        *crossIter.begin();
        *crossIter2.begin();
        ++crossIter;

        CHECK_EQ(crossIter > crossIter2, true);  // crossIter is greater
        CHECK_EQ(crossIter2 < crossIter, true);  // crossIter2 is less
    }
}

//****************************************************************************************

TEST_SUITE("Test PrimeIterator class") {
    MagicalContainer container;

    TEST_CASE("Add Elements To The Container") {
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);
    }

    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(container);

    TEST_CASE("Test operator* function") {
        CHECK_EQ(*primeIter.begin(), 2);  // The smallest element
        primeIter++;
        CHECK_EQ(*primeIter, 5);
        primeIter++;
        CHECK_THROWS_AS(*primeIter, out_of_range);  // Trying to dereference end
    }

    TEST_CASE("Test operator++ function") {
        *primeIter.begin();
        ++primeIter;
        CHECK_EQ(*primeIter, 5);
        CHECK_THROWS_AS(++primeIter, out_of_range);  // Trying to increment past the end
    }

    TEST_CASE("Test end function") {
        CHECK_EQ(*primeIter.end(), 5);
    }

    TEST_CASE("Test begin function") {
        CHECK_EQ(*primeIter.begin(), 2);
    }

    TEST_CASE("Test operator= function") {
        *primeIter.begin();
        *primeIter2.begin();
        CHECK_NOTHROW(primeIter = primeIter2);  // Assignment operator
        CHECK_EQ(*primeIter, *primeIter2); // They should point to the same element
    }

    TEST_CASE("Test operator== function") {
        *primeIter.begin();
        *primeIter2.begin();
        CHECK_EQ(primeIter == primeIter2, true);  // Both at the beginning
        ++primeIter;
        CHECK_EQ(primeIter == primeIter2, false);  // primeIter moved forward
        ++primeIter2;
        CHECK_EQ(primeIter == primeIter2, true);  // Both moved forward
    }

    TEST_CASE("Test operator!= function") {
        *primeIter.begin();
        *primeIter2.begin();
        CHECK_EQ(primeIter != primeIter2, false);  // Both at the beginning
        ++primeIter;
        CHECK_EQ(primeIter != primeIter2, true);  // primeIter moved forward
        ++primeIter2;
        CHECK_EQ(primeIter != primeIter2, false);  // Both moved forward
    }

    TEST_CASE("Test operator> and operator< function") {
        *primeIter.begin();
        *primeIter2.begin();
        ++primeIter;
        CHECK_EQ(primeIter > primeIter2, true);  // primeIter is greater
        CHECK_EQ(primeIter2 < primeIter, true);  // primeIter2 is less
    }
}

//****************************************************************************************
