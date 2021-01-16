#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

typedef std::multimap<std::string, std::string> mmap;

bool search_person(mmap& graph);

bool search_person(mmap& graph)
{
    std::queue<std::string> search_queue;
    std::vector<std::string> searched;
    std::string name;
    mmap::iterator mIter;
    std::pair<mmap::iterator, mmap::iterator> pairIter;

    search_queue.push("you"); //Graph vertex

    while (!search_queue.empty())
    {
        name = search_queue.front();
        search_queue.pop();
        if (name[name.length() - 1] == 'a')
        {
            std::cout << name << " is a mango seller!" << std::endl;
            return true;
        }
        mIter = graph.begin();
        pairIter = graph.equal_range(name);
        for (; pairIter.first != pairIter.second; pairIter.first++)
            if ((*pairIter.first).second != "" && find(searched.begin(), searched.end(), name) == searched.end())
                search_queue.push((*pairIter.first).second);
        searched.push_back(name);
    }
    return false;
}

int main()
{
    std::multimap<std::string, std::string> graph;

    graph.emplace("you", "alice"); //Graph nodes
    graph.emplace("you", "bob");
    graph.emplace("you", "claire");
    graph.emplace("alice", "peggy");
    graph.emplace("claire", "thom");
    graph.emplace("claire", "jonny");
    graph.emplace("aunj", "");
    graph.emplace("thom", "");
    graph.emplace("jonny", "");

    if (!search_person(graph))
        std::cout << "No mango seller!" << std::endl;
    return 0;
}