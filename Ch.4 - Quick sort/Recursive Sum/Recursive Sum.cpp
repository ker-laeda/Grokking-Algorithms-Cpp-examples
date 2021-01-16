#include <iostream>

int sumArr(int* arr, int arrSize, int currPos, int tmpSum);

int sumArr(int* arr, int arrSize, int currPos, int tmpSum)
{
    if (currPos != (arrSize - 1))
        tmpSum = sumArr(arr, arrSize, currPos + 1, tmpSum);
    return arr[currPos] + tmpSum;
}

int main()
{
    int tmpArr[7] = { 0,1,2,3,4,5,6 };
    int arrSize = sizeof(tmpArr) / sizeof(*tmpArr);
    std::cout << sumArr(tmpArr, arrSize, 0, 0) << std::endl;
    return 0;
}