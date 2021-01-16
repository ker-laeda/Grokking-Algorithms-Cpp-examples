#include <iostream>
#include <string>
#include <map>

int main()
{
    // Map container implementation
    std::map<std::string, float> priceList;
    std::map<std::string, float>::iterator iter;

    priceList["apple"] = 0.56;
    priceList.emplace("pineapple", 2.1);
    priceList.insert(std::pair<std::string, float>("orange", 1.76));
    priceList.insert(std::make_pair("banana", 1.5));

    // All output from map container
    for (iter = priceList.begin(); iter != priceList.end(); iter++)
        std::cout << (*iter).first << " - " << (*iter).second << "$" << std::endl;

    std::cout << "-------------------------" << std::endl;

    // Output found element from map container
    std::string findStr = "orange";
    iter = priceList.find(findStr);
    if (iter != priceList.end())
        std::cout << (*iter).first << " - " << (*iter).second << "$" << std::endl;
    else
        std::cout << "Element not found!" << std::endl;

    std::cout << "-------------------------" << std::endl;

    // Multimap container implementation
    typedef std::multimap<std::string, std::string> mmap;
    mmap booksList;
    mmap::iterator mIter;
    std::pair<mmap::iterator, mmap::iterator> pairIter;
    int amount;

    booksList.emplace("Harry Harrison", "Deathworld");
    booksList.emplace("Harry Harrison", "One King’s Way");
    booksList.emplace("Harry Harrison", "Stainless Steel Rat");
    booksList.emplace("Edmond Hamilton", "The Star Kings");
    booksList.emplace("Edmond Hamilton", "Return to the Stars");
    booksList.emplace("Edmond Hamilton", "City at World's End");
    booksList.emplace("Edmond Hamilton", "The Valley of Creation");
    booksList.emplace("Robert Anson Heinlein", "Orphans of the Sky");

    // All output from multimap container
    mIter = booksList.begin();
    while (mIter != booksList.end())
    {
        amount = 1;
        pairIter = booksList.equal_range((*mIter).first);
        std::cout << (*pairIter.first).first << ": " << std::endl;
        for (; pairIter.first != pairIter.second; pairIter.first++, amount++, mIter++)
            std::cout << "     " << amount << ") " << (*pairIter.first).second << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    // Output found element from multimap container
    findStr = "Edmond Hamilton";
    pairIter = booksList.equal_range(findStr);
    if (pairIter.second != booksList.begin())
    {
        amount = 1;
        std::cout << (*pairIter.first).first << ": " << std::endl;
        for (; pairIter.first != pairIter.second; pairIter.first++, amount++)
            std::cout << "     " << amount << ") " << (*pairIter.first).second << std::endl;
    }
    else
        std::cout << "Element not found!" << std::endl;

    return 0;
}