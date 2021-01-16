#include <iostream>

template<typename T>
class LList
{
public:

    LList();
    ~LList();
    void push_front(T dataNode);
    void push_back(T dataNode);
    void insert(T dataNode, int indexNode);
    void pop_front();
    void pop_back();
    void remove_at(int indexNode);
    void clear_all();
    int get_size() { return sizeLList; }
    T& operator[](const int indexNode);

private:

    class LinkNode
    {
    public:
        LinkNode* nextNode;
        T dataNode;

        LinkNode(T dataNode = T(), LinkNode* nextNode = nullptr)
        {
            this->dataNode = dataNode;
            this->nextNode = nextNode;
        }
    };

    LinkNode* firstNode;
    int sizeLList;
};

template<typename T>
LList<T>::LList()
{
    firstNode = nullptr;
    sizeLList = 0;
}

template<typename T>
LList<T>::~LList()
{
    clear_all();
}

template<typename T>
void LList<T>::push_back(T dataNode)
{
    if (firstNode == nullptr)
        firstNode = new LinkNode(dataNode);
    else
    {
        LinkNode* currNode = this->firstNode;
        while (currNode->nextNode != nullptr)
            currNode = currNode->nextNode;
        currNode->nextNode = new LinkNode(dataNode);
    }
    sizeLList++;
}

template<typename T>
T& LList<T>::operator[](const int indexNode)
{
    int countNode = 0;
    LinkNode* currNode = this->firstNode;
    while (currNode != nullptr)
    {
        if (countNode == indexNode)
            return currNode->dataNode;
        currNode = currNode->nextNode;
        countNode++;
    }
}

template<typename T>
void LList<T>::pop_front()
{
    LinkNode* tmpNode = firstNode;
    firstNode = firstNode->nextNode;
    delete tmpNode;
    sizeLList--;
}

template<typename T>
void LList<T>::clear_all()
{
    while (sizeLList)
        pop_front();
}

template<typename T>
void LList<T>::push_front(T dataNode)
{
    firstNode = new LinkNode(dataNode, firstNode);
    sizeLList++;
}

template<typename T>
void LList<T>::insert(T dataNode, int indexNode)
{
    if (indexNode == 0)
        push_front(dataNode);
    else
    {
        LinkNode* prevNode = this->firstNode;
        for (int n = 0; n < (indexNode - 1); n++)
            prevNode = prevNode->nextNode;
        LinkNode* newNode = new LinkNode(dataNode, prevNode->nextNode);
        prevNode->nextNode = newNode;
        sizeLList++;
    }
}

template<typename T>
void LList<T>::remove_at(int indexNode)
{
    if (indexNode == 0)
        pop_front();
    else
    {
        LinkNode* prevNode = this->firstNode;
        for (int n = 0; n < (indexNode - 1); n++)
            prevNode = prevNode->nextNode;
        LinkNode* delNode = prevNode->nextNode;
        prevNode->nextNode = delNode->nextNode;
        delete delNode;
        sizeLList--;
    }
}

template<typename T>
void LList<T>::pop_back()
{
    remove_at(sizeLList - 1);
}

int main()
{
    LList<int> lstest;
    lstest.push_back(7);
    lstest.push_back(13);
    lstest.push_back(23);
    std::cout << "Amount elements in linked list - " << lstest.get_size() << std::endl;
    std::cout << "Element 0 is - " << lstest[0] << std::endl;
    lstest.pop_front();
    std::cout << "Amount elements in linked list after delete - " << lstest.get_size() << std::endl;
    std::cout << "Element 0 is - " << lstest[0] << std::endl;
    lstest.push_front(1983);
    std::cout << "Amount elements in linked list after pop front - " << lstest.get_size() << std::endl;
    std::cout << "Element 0 is - " << lstest[0] << std::endl;
    lstest.insert(333, 1);
    std::cout << "Amount elements in linked list after insert - " << lstest.get_size() << std::endl;
    std::cout << "Element 1 is - " << lstest[1] << std::endl;
    lstest.remove_at(1);
    std::cout << "Amount elements in linked list after remove 1 - " << lstest.get_size() << std::endl;
    std::cout << "Element 1 is - " << lstest[1] << std::endl;
    lstest.pop_back();
    std::cout << "Amount elements in linked list after remove last - " << lstest.get_size() << std::endl;
    lstest.clear_all();
    std::cout << "Amount elements in linked list after clear all - " << lstest.get_size() << std::endl;
    return 0;
}