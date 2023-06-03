
#include "ohtoai/allocator.hpp"
#include <cstddef>

template <typename T, typename Allocator = ohtoai::allocator<T>> class Linklist;
template <typename T>                                           //使用模板
class Linknode
{
public:
    Linknode()                                                  //委托构造
        : Linknode({})
    {}
    Linknode(const T& value)                                           //值在方括号中
        : data{ value }, next{ nullptr }
    {}
    Linknode<T>* getNext() const{ return next; }                      //返回next值
    Linknode<T>* getNext() { return next; }                      //返回next值
    void setNext(Linknode<T>* next)                             //修改next的值
    {
        this->next = next;
    }

    operator T& ()
    {
        return data;
    }

    Linknode<T>& operator=(const T& a)
    {
        data = a;
        return *this;
    }

    Linknode<T>& operator=(T&& a)
    {
        data = a;
        return *this;
    }

    Linknode<T>& operator=(const Linknode<T>& a)
    {
        data = a;
        return *this;
    }

    Linknode<T>& operator=(Linknode<T>&& a)
    {
        data = a;
        return *this;
    }

    ~Linknode() = default;
protected:

private:
    T data;
    Linknode<T>* next{};
};

/// <summary>
/// 迭代器
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
struct Linklist_iterator
{
public:
    friend Linklist<T, ohtoai::allocator<Linknode<T>>>;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using node_type = Linknode<T>;
    using node_pointer = node_type*;
    using iterator = Linklist_iterator;

    Linklist_iterator(node_pointer node = nullptr)
        : node{ node }
    {}
    ~Linklist_iterator()
    {}
    // 重载运算符
    bool operator== (iterator other) const
    {
        return node == other.node;
    }

    bool operator!= (iterator other) const
    {
        return node == other.node;
    }

    operator bool() const
    {
        return node != nullptr;
    }

    iterator& operator=(const iterator& it)
    {
        node = it.node;
        return *this;
    }

    T& operator*()
    {
        return *node;
    }

    T& operator->()
    {
        return operator*();//*(*this);
    }

    iterator& operator++()                                         // 令iterator指向容器下一个位置
    {
        if (node != nullptr)
            node = node->getNext();
        return *this;
    }

    iterator operator++(int)                                       // 令iterator指向容器下一个位置
    {
        auto temp = *this;
        ++(*this);
        return temp;
    }

protected:
    node_pointer node{};
};


/// <summary>
/// 
/// </summary>
template <typename T, typename Allocator = ohtoai::allocator<Linknode<T>>>                                           // 使用模板
class Linklist
{
public:
    using iterator = Linklist_iterator<T>;
    using value_type = T;
    using reference = T&;
    using pointer = T*;

    Linklist()
        : size{}
    {}
    ~Linklist()
    {}

    size_t length() const
    {
        return size;
    }
    iterator end() const { return {}; }                                      // 尾迭代器
    iterator begin() const                                                   // 头迭代器
    {
        return { head.getNext() };
    }
    iterator end() { return {}; }                                            // 尾迭代器
    iterator begin()                                                         // 头迭代器
    {
        return { head.getNext() };
    }

    iterator insert_back(const iterator& it, const T& elem)
    {
        auto next = it.node->getNext();
        auto node = allocator.allocate();
        allocator.construct(node, elem);
        it.node->setNext(node);
        node->setNext(next);
        return node;
    }

    iterator erase_back(const iterator& it)
    {
        if (it.node->getNext() != nullptr)
        {
            auto next = it.node->getNext();
            it.node->setNext(next->getNext());

        }
    }

protected:

private:
    int size;													              // 长度
    Linknode<T> head;											              // 头节点
    Allocator allocator;
};