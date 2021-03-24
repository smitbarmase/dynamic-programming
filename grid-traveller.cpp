#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, long long> map;

// I have used alternate key because say (30, 20) and (20, 30) will have same number of path.

long long grid_traveller(int m, int n)
{
    string key = to_string(m) + "," + to_string(n);
    string alternate_key = to_string(n) + "," + to_string(m);
    if (map.find(key) != map.end())
        return map[key];
    if (map.find(alternate_key) != map.end())
        return map[alternate_key];
    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;
    long long result = grid_traveller(m - 1, n) + grid_traveller(m, n - 1);
    map.insert(make_pair(key, result));
    return result;
    return 0;
}

int main()
{
    cout << grid_traveller(1, 1) << endl;
    cout << grid_traveller(2, 3) << endl;
    cout << grid_traveller(3, 2) << endl;
    cout << grid_traveller(3, 3) << endl;
    cout << grid_traveller(25, 25) << endl;
    return 0;
}