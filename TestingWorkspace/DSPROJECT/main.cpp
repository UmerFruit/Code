#include "Headers.h"
#include <ctime>
using namespace std;
/*
    A user logs in as either the controller or a
truck driver. If the user is a controller, he can view the bin fill data for the past hour (randomly
pick a time from the 3 days of data you generated). Based on the data, he can set a collection
threshold (say 75%, so all bins that are above 75% fill level will be considered collectible). The
controller then selects a truck departure location. The trucks in one departure location are
responsible for a certain section of the map (you will decide which – essentially each truck is
responsible for 10 bins on the map, as there are 5 departure locations). Now you will generate
a new graph comprising only of the collectible bins from the last hour from the given section
of the map (say, only the bins in F sector that are collectible). Now you run a shortest-path
algorithm (specifically you will implement Djikstra’s algorithm) over the graph to decide the
best possible route for collections. That is, use Djikstra’s algorithm to find the most optimised
(shortest) route from the source to destination while collecting all the bins.
*/


void read_locations(vector<location> &v1)
{
    ifstream fin;
    fin.open("locations.txt");
    string name, sector, isbin;
    while (fin >> name >> sector >> isbin)
    {
        location l1(name, sector, stoi(isbin));
        v1.push_back(l1);
    }
    fin.close();
}
int main()
{
    srand(time(0));
    vector<location> v1;
    read_locations(v1);
    menu();
    return 0;
}
