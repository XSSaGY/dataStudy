#include "Linklist.hpp"
#include "Linknode.hpp"
#include <vector>
#include <iostream>


int main()
{

    //struct iterator {
    //     using value_type = T;
    //     
    //     iterator() = default;
    //     ~iterator() = default;
    //     iterator & iterator(const iterator&) = default;
    //     iterator & iterator(iterator&&) = default;
    //     iterator & operator=(const iterator&) = default;
    //     
    //         iterator & operator++()
    //          {
    //         if (m_node != nullptr)
    //              m_node = m_node->getNext();
    //         return *this;
    //         }
    //     
    //         iterator operator++(int)
    //         {
    //         auto tmp = *this;
    //          ++* this;
    //        return tmp;
    //        }
    //    
    // protected:
    //    Linknode<value_type>*m_node{};
    //    
    //};
    int a = 1;
    Linknode<int> node1(1);
    Linknode<int> node2(2);
    Linknode<int> node3(3);
    Linknode<int> node4(4);
    Linklist<int> list;
    list.Insert(&node1, list.getEnd());
    list.Insert(&node2, list.getEnd());
    list.Insert(&node3, list.getEnd());
    list.Insert(&node4, list.getEnd());
    list.Delete(node3);
    list.Modity(list.getBegin(), node3);
    list.Length();
    return 0;
}