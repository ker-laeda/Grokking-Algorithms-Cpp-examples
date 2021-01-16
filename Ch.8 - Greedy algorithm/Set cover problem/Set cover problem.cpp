#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void buildStationRange(map<string, set<string>>& stations, set<string> &states_needed)
{
	stations["kone"] = { "id", "nv", "ut" };
	stations["ktwo"] = { "wa", "id", "mt" };
	stations["kthree"] = { "or", "nv", "ca" };
	stations["kfour"] = { "nv", "ut" };
	stations["kfive"] = { "ca", "az" };
	states_needed = { "id", "nv", "ut", "wa", "mt", "or", "ca", "az" };
}

int main()
{
	map<string, set<string>> stations;
	set<string> states_needed;
	set<string> states_for_station;
	set<string> states_covered;
	set<string> covered;
	set<string> final_stations;
	string best_station;

	buildStationRange(stations, states_needed);

	while (states_needed.size() > 0)
	{
		best_station = "none";
		states_covered.clear();
		for (auto station : stations)
		{
			set_intersection(states_needed.begin(), states_needed.end(), station.second.begin(), station.second.end(), inserter(covered, covered.begin()));
			if (covered.size() > states_covered.size())
			{
				best_station = station.first;
				states_covered.clear();
				states_covered.insert(covered.begin(), covered.end());
			}
			covered.clear();
		}
		for (auto state_covered : states_covered)
			states_needed.erase(state_covered);
		final_stations.insert(best_station);

	}
	
	for (auto station : final_stations)
		cout << station << endl;
}
