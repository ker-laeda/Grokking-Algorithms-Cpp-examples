#include <iostream>

bool search_num(int* myArr, int sizeArr, int findNum, int* findIndex)
{
    bool findOK = false;
    int lowNum = 0;
    int highNum = sizeArr - 1;
    int midNum, guessNum;
    while (lowNum <= highNum)
    {
        midNum = (lowNum + highNum) / 2;
        guessNum = myArr[midNum];
        if (guessNum == findNum)
        {
            *findIndex = midNum;
            findOK = true;
        }
        if (guessNum > findNum)
            highNum = midNum - 1;
        else
            lowNum = midNum + 1;
    }
    return findOK;
}

int main()
{
    int findIndex = 0;
    int findNum = 77;
    int myArr[101];
    for (int n = 0; n < 101; n++)
        myArr[n] = n;
    int sizeArr = sizeof(myArr) / sizeof(*myArr);
    if (search_num(myArr, sizeArr, findNum, &findIndex))
        std::cout << "Number " << findNum << " found in position - " << findIndex << std::endl;
    else
        std::cout << "Number " << findNum << " is not found!" << std::endl;
    return 0;
}