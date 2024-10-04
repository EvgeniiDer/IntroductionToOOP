#ifndef NODE_HPP
#define NODE_HPP
#include"head.hpp"

template<typename T>
class Node
{
public:
    T Data;
    Node* nextNode;
    Node* prevNode;
    Node(const T& _Data) : nextNode(nullptr), prevNode(nullptr)
    {
        this->Data = _Data;
    }
    auto returnData() -> decltype(Data)
    {
        return Data;
    }
};
template class Node<int>;

#endif