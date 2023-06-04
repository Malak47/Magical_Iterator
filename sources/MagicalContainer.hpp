//
// Created by malaklinux on 5/24/23.
//

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
#define MAGICAL_ITERATORS_MAGICALCONTAINER_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;
namespace ariel {

    class MagicalContainer {
    private:
        vector<int> vecElements;
        vector<int> vecPrime;
    public:
        MagicalContainer();

        void addElement(int element);
        bool removeElement(int element);
        size_t size() const;
        vector<int> getElements();

        int searchElementAt(int element, const vector<int>& vec);       //O(N)
        void addAndSortElement(int element, vector<int> &vec);
        static bool isPrime(int number);

        //****************************************************************************************
        //********** A S C E N D I N G   I T E R A T O R *****************************************
        //****************************************************************************************

        class AscendingIterator {
        private:
            MagicalContainer *container;
            int index;
        public:
            AscendingIterator();
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(MagicalContainer &container);
            ~AscendingIterator();
            AscendingIterator(AscendingIterator &&) noexcept = delete;
            AscendingIterator &operator=(AscendingIterator &&) noexcept = delete;
            AscendingIterator &operator=(const AscendingIterator &other);

            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*() const;

            AscendingIterator &operator++();
            AscendingIterator operator++(int);

            AscendingIterator begin();
            AscendingIterator end();

            MagicalContainer getContainer() const;
            int getIndex() const;
        };

        //****************************************************************************************
        //********** S I D E - C R O S S   I T E R A T O R ***************************************
        //****************************************************************************************

        class SideCrossIterator {
        private:
            MagicalContainer *container;
            int frontIndex, backIndex;
        public:
            SideCrossIterator();
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(MagicalContainer &container);
            ~SideCrossIterator();
            SideCrossIterator(SideCrossIterator &&) noexcept = delete; // Move Constructor.
            SideCrossIterator &operator=(SideCrossIterator &&) noexcept = delete;
            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*() const;

            SideCrossIterator &operator++();
            SideCrossIterator operator++(int);

            SideCrossIterator begin();
            SideCrossIterator end();

            MagicalContainer getContainer() const;
            int getFrontIndex() const;
            int getBackIndex() const;

        };

        //****************************************************************************************
        //********** P R I M E   I T E R A T O R *************************************************
        //****************************************************************************************

        class PrimeIterator {
        private:
            MagicalContainer *container;
            int index;
            bool isPrime(int num);

        public:
            PrimeIterator();
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(MagicalContainer &container);
            ~PrimeIterator();
            PrimeIterator(PrimeIterator &&) noexcept = delete; // Move Constructor.
            PrimeIterator &operator=(PrimeIterator &&) noexcept = delete;
            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*() const;

            PrimeIterator &operator++();
            PrimeIterator operator++(int);

            PrimeIterator begin();
            PrimeIterator end();

            MagicalContainer getContainer() const;
            int getIndex() const;
        };
    };
}
#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
