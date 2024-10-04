#include"DoublyLinkedList.hpp"
int main()
{
    MyList<int>* list = new MyList<int>{3, 5, 8, 13, 21 }; 
    
    list->push_front(1);
    list->push_front(2);
    list->push_front(3);
    list->push_front(4);
    list->push_front(5);
    list->push_back(0);
    list->display();
    std::cout << std::endl;
    list->erase(0);
    MyList<int>* list2 = new MyList<int>{3, 4, 5 ,2 };
    MyList<int>* list3 = *list + *list2;
    for(int i: *list3)
    {
        std::cout << i << std::endl;
    }

    
    return 0;
}