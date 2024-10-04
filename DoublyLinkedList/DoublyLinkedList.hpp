#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include"head.hpp"
#include"node.hpp"



template<typename T>
class  MyList{
    private:
        Node<T>* Head;
        Node<T>* Tail;
        size_t size;
    public:
        MyList() : Head(nullptr), Tail(nullptr), size(0){}
        size_t get()const{
            return size;
        }
        MyList(std::initializer_list<T> init) : MyList() {
            for (const T& element : init) {
                push_back(element);
            }
        }
        MyList* operator+(const MyList& other) const {
            MyList* result = new MyList(); // Создаем новый объект MyList
            Node<T>* current = this->Head;
        while (current) {
            result->push_back(current->Data);
            current = current->nextNode;
        }
        current = other.Head;
        while (current) {
            result->push_back(current->Data);
            current = current->nextNode;
        }

        return result; 
    }
        void push_back(const T& _Element);
        void push_front(const T& _Element);
        T pop_front();
        T pop_back();
        void insert(const int& _Index, const T& _Data);
        void erase(const int& _index);
        void display();
        ~MyList() {
        Node<T>* current = Head;
        while (current) {
            Node<T>* nextNode = current->nextNode; 
            delete current; 
            current = nextNode; 
        }
    }

        class Iterator
        {
            private:
                Node<T>* current;
            public:
                Iterator(Node<T>* _node): current(_node){}
                T& operator*(){
                    return current->Data;
                }
                Iterator& operator++(){
                    current = current->nextNode;
                    return *this;
                }
                bool operator!=(const Iterator& other)const{
                    return current != other.current;
                }
        };
        Iterator begin()
            {
                return Iterator(Head);
            }
        Iterator end()
            {
                return Iterator(nullptr);
            }
};
#include"DoublyLinkedList.tpp"

#endif