#include <stdexcept>
#include <iostream>

template<typename T>
struct linkedListItem {
    linkedListItem * next;
    T* data;
};

template<typename T>
class CLinkedList {
    public:
        ~CLinkedList() {
            linkedListItem<T> * tmp;

            while (this->first != nullptr) {
                tmp = this->first;
                this->first = this->first->next;
                delete tmp->data;
                delete tmp;
            }
        }
        void insertStart(const T x) {
            linkedListItem<T> * newItem = new linkedListItem<T>;

            newItem->data = new T;
            *(newItem->data) = x;
            newItem->next = this->first;

            this->first = newItem;

            this->itemCount++;
        }

        void insertEnd(const T x) {
            linkedListItem<T> * newItem = new linkedListItem<T>;
            newItem->data = new T;
            *(newItem->data) = x;
            newItem->next = nullptr;

            if (this->last)
                this->last->next = newItem;
            else {
                this->first = newItem;
            }

            this->last = newItem;

            this->itemCount++;
        }

        void deleteAll(void) {
            linkedListItem<T> * tmp;

            while (this->first != nullptr) {
                tmp = this->first;
                this->first = this->first->next;
                delete tmp->data;
                delete tmp;
            }

            this->first = nullptr;
            this->last = nullptr;
            this->it = nullptr;
            this->itemCount = 0;
        }

        T * at(const unsigned n) const { // Starting with 0
            if (!itemCount || n >= itemCount)
                throw std::invalid_argument("This item does not exist in singly linked list");

            linkedListItem<T> * tmp = this->first;

            for (unsigned i = 0; i < n; i++) {
                tmp = tmp->next;
            }
            return tmp->data;
        }

        unsigned size(void) const {
            return itemCount;
        }

        T * next() {
            if (this->it == nullptr || this->it->next == nullptr)
                this->it = this->first;
            else
                this->it = this->it->next;
            return this->it->data;
        }

        void remove(const T* item) {
            linkedListItem<T> * tmp = this->first;

            if (tmp->data == item) {
                if (itemCount == 1)
                    this->last = nullptr;
                this->first = tmp->next;
                if (itemCount == 2)
                    this->last = tmp;
                delete tmp->data;
                delete tmp;
                itemCount--;
                return;
            }

            unsigned counter = 0;
            while (!(tmp->next->data == item)) {
                tmp = tmp->next;
                counter++;
            }
            linkedListItem<T> * nextnext = tmp->next->next;
            delete tmp->next->data;
            delete tmp->next;
            if (counter == this->itemCount - 2)
                tmp->next = nullptr;
            else
                tmp->next = nextnext;
            itemCount--;
        }

    private:
        linkedListItem<T> * first = nullptr;
        linkedListItem<T> * last = nullptr;
        linkedListItem<T> * it = nullptr;
        unsigned itemCount = 0;
};