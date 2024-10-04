#include "DoublyLinkedList.hpp"

template<typename T>
void MyList<T>::push_back(const T& _Element) {
    Node<T>* newNode = new Node<T>(_Element);
    if (Head == nullptr) {
        this->Head = this->Tail = newNode;
    } else {
        this->Tail->nextNode = newNode;
        newNode->prevNode = this->Tail;
        this->Tail = newNode;
    }
    size++;
}

template<typename T>
void MyList<T>::push_front(const T& _Element) {
    Node<T>* newNode = new Node<T>(_Element);
    if (Head == nullptr) {
        this->Head = this->Tail = newNode;
    } else {
        this->Head->prevNode = newNode;
        newNode->nextNode = this->Head;
        this->Head = newNode;
    }
    size++;
}

template<typename T>
T MyList<T>::pop_back() {
    if (Tail == nullptr) {
        throw std::runtime_error("List is empty");
    }
    Node<T>* iterator = Tail;
    T value = iterator->Data;
    Tail = Tail->prevNode;
    if (Tail) {
        Tail->nextNode = nullptr;
    } else {
        Head = nullptr;
    }
    delete iterator; 
    size--;   
    return value;
}

template<typename T>
T MyList<T>::pop_front() {
    if (Head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    Node<T>* iterator = Head;
    T value = iterator->Data;
    Head = Head->nextNode;
    if (Head) {
        Head->prevNode = nullptr;
    } else {
        Tail = nullptr;
    }
    delete iterator;
    size--;
    return value;
}

template<typename T>
void MyList<T>::insert(const int& _Index, const T& _Data) {   
    if (_Index > size || _Index < 0) {
        throw std::out_of_range("Index out of range");
    } else if (_Index == 0) {
        push_front(_Data);
    } else if (_Index == size) {
        push_back(_Data);
    } else {
        Node<T>* iterator = Head;
        for (size_t i = 0; i < _Index; i++) {
            iterator = iterator->nextNode;
        }
        Node<T>* newNode = new Node<T>(_Data);
        newNode->prevNode = iterator->prevNode;
        newNode->nextNode = iterator;
        if (iterator->prevNode) {
            iterator->prevNode->nextNode = newNode;
        }
        iterator->prevNode = newNode; // Обновляем указатель prevNode для текущего узла
        if (_Index == 1) {
            Head = newNode; // Если вставляем в начало
        }
    }
    size++;
}

template<typename T>
void MyList<T>::erase(const int& _index) {
    if (_index >= size || _index < 0) {
        throw std::out_of_range("Index out of range");
    } else if (_index == 0) {
        pop_front();
    } else if (_index == size - 1) {
        pop_back();
    } else {
        Node<T>* iterator = Head;
        for (size_t i = 0; i < _index; i++) {
            iterator = iterator->nextNode;
        }
        if (iterator == nullptr) {
            throw std::runtime_error("Iterator is nullptr");
        }
        if (iterator->prevNode) {
            iterator->prevNode->nextNode = iterator->nextNode;
        }
        if (iterator->nextNode) {
            iterator->nextNode->prevNode = iterator->prevNode;
        }
        delete iterator;
        size--;
    }
}

template<typename T>
void MyList<T>::display() {
    if (Head == nullptr) {
        std::cerr << "DoublyLinkedList is empty" << std::endl;
        return;
    } else {
        Node<T>* iterator = this->Head;
        while (iterator) {
            std::cout << iterator->Data << " ";
            iterator = iterator->nextNode;
        }
        std::cout << "\nDoublyLinkedList's size is: " << size << std::endl; 
    }
}
