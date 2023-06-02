#include "Linknode.hpp"
#include <iostream>
#include <spdlog/spdlog.h>


template <typename T> class Linklist;
/// <summary>
/// 迭代器
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
struct Linklist_iterator
{
public:
    friend Linklist<T>;
    Linklist_iterator()
    {}
    ~Linklist_iterator()
    {}
    //重载运算符
    bool operator==(Linklist_iterator other);
    bool operator!=(Linklist_iterator other);
    Linklist_iterator& operator=(const Linklist_iterator& it);                //赋值运算符重载
    T& operator*();                                                           //解引用重载
    T& operator->();
    Linklist_iterator& operator++();                                         //令iterator指向容器下一个位置
    Linklist_iterator operator++(int);                                       //令iterator指向容器上一个位置
protected:
    Linknode<T>* node;
};


/// <summary>
/// 
/// </summary>
template <typename T>                                           //使用模板
class Linklist
{
public:
    using iterator = Linklist_iterator<T>;
	Linklist()
        : size{}
	{}
    ~Linklist()
    {}

	size_t Length();                                                        //求表长
    //Linknode<T>* getHead() { return &head; }                                //返回表头
    bool Insert(Linknode<T>* elem, Linknode<T>* location);                  //插入元素
    bool it_Insert(iterator it, T elem);                                    //使用迭代器插入元素
	bool Delete(Linknode<T> elem);                                          //删除元素
    bool it_Delete(T elem);                                                 //use iterator to delete
	bool Modity(Linknode<T>* location, Linknode<T> elem);                   //修改元素
    Linknode<T>* LocateElem(T elem);                                        //返回元素地址
    Linknode<T>* getEnd();                                                  //返回链表最后一个节点地址
    Linknode<T>* getBegin() { return head.getNext(); }                      //返回链表第一个节点地址
    iterator begin();                                                       //头迭代器
    iterator end() { return {}; }                                           //尾迭代器
    void show();                                                            //遍历打印表中元素
private:
	int size;													            //长度
    Linknode<T> head;											            //头节点
};

/// <summary>
/// 返回长度
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T>
size_t Linklist<T>::Length()
{
    return size;
}

/// <summary>
/// 后插法
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="elem">元素</param>
/// <param name="location">下标</param>
/// <returns></returns>
template <typename T>
bool Linklist<T>::Linklist::Insert(Linknode<T>* elem, Linknode<T>* location)
{
    if (location == nullptr)
    {
        return false;
    }
    else
    {
        elem->setNext(location->getNext());
        location->setNext(elem);
        size++;
        return true;
    }
}

template <typename T>
bool Linklist<T>::it_Insert(iterator it, T elem)
{
    std::cout << __LINE__ << std::endl;
    // Linknode<T> elem_node(elem);
    std::cout<<it.node<<std::endl;
    Linknode<T>* elem_node = new Linknode<T>(elem);
    std::cout << __LINE__ << std::endl;
    if(it == this->end())
    {
        std::cout << __LINE__ << std::endl;
        this->getEnd()->setNext(elem_node);
    }
    else
    {
        std::cout << __LINE__ << std::endl;
        elem_node->setNext(it.node->getNext());
        std::cout << __LINE__ << std::endl;
        it.node->setNext(elem_node);
        std::cout << __LINE__ << std::endl;
    }
    size++;
    return true;
}

template<typename T>
inline bool Linklist<T>::Delete(Linknode<T> elem)
{
    Linknode<T>* p = head.getNext();
    while (p != nullptr)
    {
        if (p->getData() == elem.getData())
        {
            p->setData(p->getNext()->getData());
            p->setNext(p->getNext()->getNext());
            delete p->getNext();
            size--;
            return true;
        }
        p = p->getNext();
    }
    return false;
}

template<typename T>
inline bool Linklist<T>::it_Delete(T elem)
{
    iterator it = std::find(begin(),end(),elem);
    if(it==nullptr) return false;
    iterator next = ++it;
    it.node.setData(next.getData());
    it.node.setNext(next.getNext());
    delete next.node;
    size--;
    return true;
}

template<typename T>
inline bool Linklist<T>::Modity(Linknode<T>* location, Linknode<T> elem)
{
    location->setData(elem.getData());
    return true;
}

template<typename T>
Linknode<T>* Linklist<T>::LocateElem(T elem)
{
    Linknode<T>* p = head.getNext();
    while (1)
    {
        if (p == nullptr)
            break;
        if (p->getData() == elem)
            break;
        p = p->getNext();
    }
    return p;
}

template<typename T>
inline Linknode<T>* Linklist<T>::getEnd()
{
    Linknode<T>* p = &head;
    while (1)
    {
        if (p->getNext() == nullptr)
            break;
        p = p->getNext();
    }
    return p;
}

template<typename T>
typename Linklist<T>::iterator Linklist<T>::begin()
{
    iterator it;
    it.node = head.getNext();
    return it;
}


template<typename T>
bool Linklist_iterator<T>::operator==(Linklist_iterator<T> other)
{
    return node == other.node;
}

template<typename T>
bool Linklist_iterator<T>::operator!=(Linklist_iterator<T> other)
{
    return node == other.node;
}

template<typename T>
Linklist_iterator<T>& Linklist_iterator<T>::operator=(const Linklist_iterator<T>& it)
{
    node = it.node;
    return *this;
}


template<typename T>
T& Linklist_iterator<T>::operator*()
{
    return node->getData();
}

template<typename T>
T& Linklist_iterator<T>::operator->()
{
    return operator*();//*(*this);
}

template<typename T>
Linklist_iterator<T>& Linklist_iterator<T>::operator++()
{
    if (node != nullptr)
        node = node->getNext();
    return *this;
}

template<typename T>
Linklist_iterator<T> Linklist_iterator<T>::operator++(int)
{
    auto temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
void Linklist<T>::show()
{
    for(iterator it=begin();it==end();++it)
    {
        std::cout<<it.node->getData()<<"\n";
    }
}