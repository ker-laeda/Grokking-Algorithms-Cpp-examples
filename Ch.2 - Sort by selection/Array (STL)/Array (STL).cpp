#include <iostream>
#include <vector>

int find_min(std::vector<int>& tmpArr)
{
    std::vector<int>::iterator iter = tmpArr.begin();
    int smallest = *iter;
    int smallest_index = 0;
    for (int n = 0; n < tmpArr.size(); n++)
    {
        if (*iter < smallest)
        {
            smallest = *iter;
            smallest_index = n;
        }
        iter++;
    }
    return smallest_index;
}

void sort_arr(std::vector<int> tmpArr, std::vector<int>& secondArr)
{
    int smallest;
    int size_tmpArr = tmpArr.size();
    std::vector<int>::iterator iter;
    for (int n = 0; n < size_tmpArr; n++)
    {
        iter = tmpArr.begin();
        smallest = find_min(tmpArr);
        secondArr.push_back(tmpArr.at(smallest));
        std::advance(iter, smallest);
        tmpArr.erase(iter);
    }

}

int main()
{
    std::vector<int> firstArr, secondArr;
    firstArr.push_back(3);
    firstArr.push_back(5);
    firstArr.push_back(7);
    firstArr.push_back(1);
    firstArr.push_back(4);
    firstArr.push_back(2);
    firstArr.push_back(6);
    sort_arr(firstArr, secondArr);
    for (int n = 0; n < secondArr.size(); n++)
        std::cout << secondArr.at(n) << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int n = 0; n < firstArr.size(); n++)
        std::cout << firstArr.at(n) << std::endl;
    return 0;
}