#include <iostream>
#include <vector>

template <class T>
T sumArr(std::vector<T> tmpArr)
{
    if (tmpArr.empty())
        return 0;
    T tmpSum = tmpArr.back();
    tmpArr.pop_back();
    return tmpSum + sumArr(tmpArr);
}

int main()
{
    std::vector<int> tmpArr = { 0,1,2,3,4,5,6 };
    std::cout << sumArr(tmpArr) << std::endl;
    return 0;
}