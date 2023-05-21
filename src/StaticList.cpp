#include <iostream>

using namespace std;

constexpr int MAXLENGTH{ 10 };                                                               //最大表长
/// <summary>
/// 静态顺序表
/// </summary>
class Static_list
{
public:
    bool InitList(Static_list &L);                                                           //初始化表
    int Length(Static_list L);                                                               //求表长
    bool ListInsert(Static_list & L, int location, int elem);                                //向表中插入元素
    bool ListDelete(Static_list& L, int location, int& e);                                   //在表中删除元素
    int LocateElem(Static_list L, int elem);                                                 //按值查找表中元素
private:
    int data[MAXLENGTH];
    int length;                                                                              //表的长度
};
/// <summary>
/// 初始化表
/// </summary>
/// <param name="L">创建的Static_list类型的表</param>
/// <returns>true</returns>
bool Static_list::InitList(Static_list &L) {
    L.length = 0;
    for (int i = 0; i < MAXLENGTH; i++)
    {
        L.data[i] = 0;
    }
    return true;
}
/// <summary>
/// 返回表长度
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
int Static_list::Length(Static_list L)
{
    return L.length;
}
/// <summary>
/// 向表中插入元素
/// </summary>
/// <param name="L">顺序表</param>
/// <param name="location">要插入的位置</param>
/// <param name="elem">要插入的元素</param>
/// <returns>成功返回true失败返回false</returns>
bool Static_list::ListInsert(Static_list& L, int location, int elem)
{
    if (location > MAXLENGTH && location > L.length)
    {
        cout << "location is illegal\n";
        return false;
    }
    for (int i = L.length; i >= location; i--)
        L.data[i] = L.data[i - 1];
    L.data[location] = elem;
    L.length++;
    return true;
}
/// <summary>
/// 删除表中元素
/// </summary>
/// <param name="L">表</param>
/// <param name="location">删除元素的位置</param>
/// <param name="e">删除元素的值</param>
/// <returns>成功true失败false</returns>
bool Static_list::ListDelete(Static_list& L, int location, int& e)
{
    if (location >= L.length)
    {
        cout << "location is illegal\n";
        return false;
    }
    e = L.data[location];
    for (int i = location; i < L.length; i++)
        L.data[i] = L.data[i + 1];
    L.length--;
    return true;
}
/// <summary>
/// 按值查找
/// </summary>
/// <param name="L">表</param>
/// <param name="elem">查找的元素</param>
/// <returns>下标</returns>
int Static_list::LocateElem(Static_list L, int elem)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == elem)
            return i;
    }
}