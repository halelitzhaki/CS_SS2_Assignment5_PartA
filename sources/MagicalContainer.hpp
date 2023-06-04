#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

namespace ariel {
class MagicalContainer {
        private:
            std::vector<int> _elements;

        public:
            MagicalContainer();

            void addElement(int element);
            void removeElement(int element);

            int size() const;
            const std::vector<int>& getElements() const;

            class AscendingIterator {
                private:
                    const MagicalContainer& container;
                    int currentIndex;

                public:
                    AscendingIterator(const MagicalContainer&, int);
                    AscendingIterator(const MagicalContainer&);
                    

                    bool operator==(const AscendingIterator&) const;
                    bool operator!=(const AscendingIterator&) const;
                    bool operator>(const AscendingIterator&) const;
                    bool operator<(const AscendingIterator&) const;

                    int operator*() const;
                    AscendingIterator& operator++();

                    AscendingIterator begin();
                    AscendingIterator end();

                    const MagicalContainer& getContainer() const;
            };

            class SideCrossIterator {
                private:
                    const MagicalContainer& container;
                    int leftIndex;
                    int rightIndex;
                    bool leftToRight;

                public:
                    SideCrossIterator(const MagicalContainer& container, int leftIndex, int rightIndex, bool leftToRight);
                    SideCrossIterator(const MagicalContainer& container);

                    bool operator==(const SideCrossIterator& other) const;
                    bool operator!=(const SideCrossIterator& other) const;
                    bool operator>(const SideCrossIterator& other) const;
                    bool operator<(const SideCrossIterator& other) const;

                    int operator*() const;
                    SideCrossIterator& operator++();

                    SideCrossIterator begin();
                    SideCrossIterator end();

                    const MagicalContainer& getContainer() const;
            };

            class PrimeIterator {
                private:
                    const MagicalContainer& container;
                    int currentIndex;

                    bool isPrime(int num) const;

                public:
                    PrimeIterator(const MagicalContainer& container, int index);
                    PrimeIterator(const MagicalContainer& container);

                    bool operator==(const PrimeIterator& other) const;
                    bool operator!=(const PrimeIterator& other) const;
                    bool operator>(const PrimeIterator& other) const;
                    bool operator<(const PrimeIterator& other) const;

                    int operator*() const;
                    PrimeIterator& operator++();

                    PrimeIterator begin();
                    PrimeIterator end();

                    const MagicalContainer& getContainer() const;
            };
    };
}