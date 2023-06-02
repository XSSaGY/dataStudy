#include "Linklist.hpp"
#include "Linknode.hpp"


int main()
{
    std::cout << __LINE__ << std::endl;
    Linknode<int> node1(1);
    Linknode<int> node2(2);
    Linknode<int> node3(3);
    Linknode<int> node4(4);
    Linklist<int> list;
    std::cout << __LINE__ << std::endl;
    list.Insert(&node1,list.getEnd());
    std::cout << __LINE__ << std::endl;
    list.it_Insert(list.end(),2);//bug
    std::cout << __LINE__ << std::endl;
    list.Insert(&node3, list.getEnd());
    std::cout << __LINE__ << std::endl;
    list.Insert(&node4, list.getEnd());
    std::cout << __LINE__ << std::endl;
    list.Delete(node3);
    std::cout << __LINE__ << std::endl;
    list.Modity(list.getBegin(), node3);
    std::cout << __LINE__ << std::endl;
    list.Length();
    list.show();
    return 0;
}