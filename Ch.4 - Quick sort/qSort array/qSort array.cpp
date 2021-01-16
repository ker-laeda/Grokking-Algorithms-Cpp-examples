#include <iostream>
#include <vector>

std::vector<int> q_sort_arr(std::vector<int> firstArr)
{
    int arrSize = firstArr.size();
    if (arrSize < 2)
        return firstArr;
    int* refElem = &firstArr.front() + firstArr.size() / 2 - 1;
    std::vector<int> lessElem, greaterElem, resArr, tmpArr;
    for (int* item = &firstArr.front(); item <= &firstArr.back(); item++)
    {
        if (item == refElem)
            continue;
        if (*item <= *refElem)
            lessElem.push_back(*item);
        else
            greaterElem.push_back(*item);
    }
    resArr = q_sort_arr(lessElem);
    tmpArr = q_sort_arr(greaterElem);
    resArr.push_back(*refElem);
    resArr.insert(resArr.end(), tmpArr.begin(), tmpArr.end());
    return resArr;
}


int main()
{
    std::vector<int> firstArr, secondArr;
    firstArr.push_back(3);
    firstArr.push_back(5);
    firstArr.push_back(4);
    firstArr.push_back(2);
    firstArr.push_back(1);
    firstArr.push_back(7);
    firstArr.push_back(6);
    secondArr = q_sort_arr(firstArr);
    for (int n = 0; n < secondArr.size(); n++)
        std::cout << secondArr[n] << std::endl;
    return 0;
}