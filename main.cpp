#include <stdexcept>

template<typename T>
struct linkedListItem {
    linkedListItem * next;
    T data;
};

template<typename T>
class CLinkedList {
    public:
        ~CLinkedList() {
            linkedListItem<T> * tmp;

            while (this->first != nullptr) {
                tmp = this->first;
                this->first = this->first->next;
                delete tmp;
            }
        }
        void insertStart(const T x) {
            linkedListItem<T> * newItem = new linkedListItem<T>;

            newItem->data = x;
            newItem->next = this->first;

            this->first = newItem;

            this->itemCount++;
        }

        void insertEnd(const T x) {
            linkedListItem<T> * newItem = new linkedListItem<T>;
            newItem->data = x;
            newItem->next = nullptr;

            if (this->last)
                this->last->next = newItem;
            else
                this->first = newItem;

            this->last = newItem;

            this->itemCount++;
        }

        void deleteAll(void) {
            linkedListItem<T> * tmp;

            while (this->first != nullptr) {
                tmp = this->first;
                this->first = this->first->next;
                delete tmp;
            }

            this->first = nullptr;
            this->last = nullptr;
            this->itemCount = 0;
        }

        T & at(const unsigned n) const { // Starting with 0
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

    private:
        linkedListItem<T> * first = nullptr;
        linkedListItem<T> * last = nullptr;
        unsigned itemCount = 0;
};


#include <stdlib.h>
#include <stdint.h>
#include <string>

using namespace std;


struct Politician {
    string name;
    uint32_t popularity;
    uint8_t gender;
    size_t degree;

    Politician * parent, * rightestChild, * leftSibling;    // Pointers to another politicians
};


int main(void) {
    CLinkedList<Politician *> list;
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertStart(new Politician);
    list.insertStart(new Politician);
    list.insertStart(new Politician);
    list.insertStart(new Politician);
    for (unsigned i = 0; i < list.size(); i++) {
        delete list.at(i);
    }
    list.deleteAll();
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertEnd(new Politician);
    list.insertStart(new Politician);
    list.insertStart(new Politician);
    list.insertStart(new Politician);
    list.insertStart(new Politician);
    list.at(10);
    for (unsigned i = 0; i < list.size(); i++) {
        delete list.at(i);
    }
    list.deleteAll();
    list.at(0);
    return 0;
}
