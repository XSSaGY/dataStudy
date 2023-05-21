#include "DynamicList.h"
#include <iostream>

/// <summary>
/// 向表中插入元素
/// </summary>
/// <param name="len">要插入的长度</param>
/// <returns>成功true 失败false</returns>
//bool Dynamic_list::Increase(int len)
//{
//    int* p = data;
//    data = new int[length + len];
//    for (int i = 0; i < length; i++)
//        *(data + i) = *(p + i);
//    length += len;
//    delete [] p;                  
//    return true;
//}

inline void Dynamic_list::check_resize(int sz)
{
    // m_cap 当前容量
    // m_size 当前尺寸
    // m_data 数据起始地址
    // m_mt 写入锁
    if (sz <= m_cap)
        return;

    auto old_data = m_data;
    auto old_cap = m_cap;
    auto new_cap = m_cap;
    while (sz > new_cap)
        new_cap = new_cap * 2 + 1;
    auto new_data = new int[new_cap];    // may throw

    //std::lock_guard<mutex> guard(m_mt);

    m_cap = new_cap;
    m_data = new_data;

    for (int index = 0; index < m_len; ++index)
        *(m_data + index) = *(old_data + index);
    delete[] old_data;
}

int& Dynamic_list::operator[](int index)
{
    return m_data[index];
}

const int& Dynamic_list::operator[](int index) const
{
    return m_data[index];
}

/// <summary>
/// 返回表长度
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
int Dynamic_list::Length()
{
    return m_len;
}
/// <summary>
/// 向表中插入元素
/// </summary>
/// <param name="L">顺序表</param>
/// <param name="location">要插入的位置</param>
/// <param name="elem">要插入的元素</param>
/// <returns>成功返回true失败返回false</returns>
void Dynamic_list::Insert(int location, int elem)
{
    check_resize(m_len + 1);
    ++m_len;
    for (int i = m_len - 1; i > location; i--)
        m_data[i] = m_data[i - 1];
    m_data[location] = elem;
}
/// <summary>
/// 删除表中元素
/// </summary>
/// <param name="L">表</param>
/// <param name="location">删除元素的位置</param>
/// <param name="e">删除元素的值</param>
/// <returns>成功true失败false</returns>
bool Dynamic_list::Delete(int location)
{
    if (location >= m_len)
        return false;
    --m_len;
    for (int i = location; i < m_len - 1; i++)
        m_data[i] = m_data[i + 1];
    return true;
}
/// <summary>
/// 按值查找
/// </summary>
/// <param name="L">表</param>
/// <param name="elem">查找的元素</param>
/// <returns>下标</returns>
int Dynamic_list::LocateElem(int elem)
{
    for (int i = 0; i < m_len; i++)
    {
        if (m_data[i] == elem)
            return i;
    }
    return -1;
}