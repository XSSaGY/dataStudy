#pragma once

/// <summary>
/// 动态顺序表
/// </summary>
class Dynamic_list
{
public:
    int Length();                                                            //求表长
    void Insert(int location, int elem);                                     //向表中插入元素
    bool Delete(int location);                                               //在表中删除元素
    int LocateElem(int elem);                                                //按值查找表中元素
    int& operator [](int index);
    const int& operator [](int index) const;
protected:
    /**
     * @brief 检查尺寸并按需扩充
     * @param sz 需要检查的新尺寸
    */
    inline void check_resize(int sz);

private:
    int* m_data = nullptr;
    int m_len{};
    int m_cap{};


};
