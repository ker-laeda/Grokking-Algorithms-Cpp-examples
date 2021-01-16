#include <iostream>

bool inArr(int* firstArr, int sizeArr, int keyVal);
void sort_arr(int* firstArr, int* secondArr, int sizeArr);

bool inArr(int* firstArr, int sizeArr, int keyVal)
{
    for (int n = 0; n < sizeArr; n++)
        if (firstArr[n] == keyVal) return true;
    return false;
}

void sort_arr(int* firstArr, int* secondArr, int sizeArr)
{
    int* notIndex = new int[sizeArr];
    int minElement = firstArr[0];

    for (int x = 0; x < sizeArr; x++)
    {
        for (int y = 0; y < sizeArr; y++)
        {
            if (!(inArr(notIndex, x + 1, y)))
            {
                if (firstArr[y] == minElement)
                    notIndex[x] = y;
                if (firstArr[y] < minElement)
                {
                    minElement = firstArr[y];
                    notIndex[x] = y;
                }
            }
        }
        secondArr[x] = minElement;
        for (int yy = 0; yy < sizeArr; yy++)
            if (!(inArr(notIndex, x + 1, yy)))
            {
                minElement = firstArr[yy];
                break;
            }
    }
    delete[] notIndex;
}


int main()
{
    int testArr[7] = { 6,2,5,1,3,6,0 };
    int resArr[7];
    int arrSize = sizeof(testArr) / sizeof(*testArr);
    sort_arr(testArr, resArr, arrSize);
    for (int nn = 0; nn < arrSize; nn++)
    {
        std::cout << resArr[nn] << std::endl;
    }
    return 0;
}