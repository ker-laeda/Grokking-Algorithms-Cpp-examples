#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#define INFINITY INT_MAX

using namespace std;

typedef multimap<string, pair<string, int>> mmap;

void buildGraph(mmap& graph)
{
    graph.emplace("START", pair<string, int>("A", 6));
    graph.emplace("START", pair<string, int>("B", 2));
    graph.emplace("A", pair<string, int>("END", 1));
    graph.emplace("B", pair<string, int>("A", 3));
    graph.emplace("B", pair<string, int>("END", 5));
    graph.emplace("END", pair<string, int>("-", -1));
}

bool first_step(mmap& graph, map<string, string>& parents, map<string, int>& costs, const string& startNode, const string& endNode)
{
    bool endExists = false;
    pair<mmap::iterator, mmap::iterator> pairIter;
    if (graph.count(endNode) != 0)
        endExists = true;
    pairIter = graph.equal_range(startNode);
    if ((pairIter.second != graph.begin()) && (endExists))
    {
        for (; pairIter.first != pairIter.second; pairIter.first++)
        {
            costs.emplace(((*pairIter.first).second).first, ((*pairIter.first).second).second);
            parents.emplace(((*pairIter.first).second).first, startNode);
        }
        for (auto iterGraph : graph)
        {
            if (costs.count((iterGraph.second).first) == 0)
            {
                if (iterGraph.first == endNode)
                    costs.emplace(endNode, INFINITY);
                else
                    costs.emplace((iterGraph.second).first, INFINITY);
            }
            if (parents.count((iterGraph.second).first) == 0)
            {
                if (iterGraph.first == endNode)
                    parents.emplace(endNode, "-");
                else
                    parents.emplace((iterGraph.second).first, "-");
            }
        }
        return true;
    }
    else
        return false;
}

void getNeighbors(map<string, int>& neighbors, mmap& graph, const string& node)
{
    pair<mmap::iterator, mmap::iterator> pairIter;
    neighbors.clear();
    pairIter = graph.equal_range(node);
    for (; pairIter.first != pairIter.second; pairIter.first++)
        neighbors.emplace(((*pairIter.first).second).first, ((*pairIter.first).second).second);
}

string findLowestCostNode(map<string, int>& costs, vector<string>& processed)
{
    int lowest_cost = INFINITY;
    string lowest_cost_node = "none";
    for (auto iterCost : costs)
    {
        int cost = iterCost.second;
        if ((cost < lowest_cost) && (find(processed.begin(), processed.end(), iterCost.first) == processed.end()))
        {
            lowest_cost = cost;
            lowest_cost_node = iterCost.first;
        }
    }
    return lowest_cost_node;
}

void buildRoute(map<string, string>& parents, const string& endNode)
{
    string nextNode;
    for (int iter = 0; iter < parents.size(); iter++)
    {
        if (iter == 0)
        {
            nextNode = endNode;
            cout << endNode << " <- ";
        }
        cout << parents.find(nextNode)->second;
        if (iter < parents.size() - 1)
            cout << " <- ";
        nextNode = parents.find(nextNode)->second;
    }
}

int main()
{
    mmap graph;
    map<string, string> parents;
    map<string, int> costs, neighbors;
    vector<string> processed;
    string node;

    buildGraph(graph);

    if (first_step(graph, parents, costs, "START", "END"))
    {
        node = findLowestCostNode(costs, processed);
        while (node != "none")
        {
            int cost = costs[node];
            getNeighbors(neighbors, graph, node);
            for (auto iterNeigh : neighbors)
            {
                int new_cost = cost + iterNeigh.second;
                if (costs[iterNeigh.first] > new_cost)
                {
                    costs[iterNeigh.first] = new_cost;
                    parents[iterNeigh.first] = node;
                }
            }
            processed.push_back(node);
            node = findLowestCostNode(costs, processed);
        }
        buildRoute(parents, "END");
    }
    else
        cout << "Oops! Something went wrong!";
    return 0;
}