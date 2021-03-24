#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> map;

bool can_sum(int tagret_sum, const initializer_list<int> &numbers)
{
    if (map.find(tagret_sum) != map.end())
        return map[tagret_sum];
    if (tagret_sum == 0)
        return true;
    if (tagret_sum < 0)
        return false;
    for (auto num : numbers)
    {
        int remainder = tagret_sum - num;
        if (can_sum(remainder, numbers))
        {
            map.insert(make_pair(tagret_sum, true));
            return true;
        }
    }
    map.insert(make_pair(tagret_sum, false));
    return false;
}

bool can_do_sum(int tagret_sum, const initializer_list<int> &numbers)
{
    map.erase(map.begin(), map.end());
    return can_sum(tagret_sum, numbers);
}

int main()
{
    cout << can_do_sum(7, {2, 3}) << endl;
    cout << can_do_sum(7, {5, 3, 4, 7}) << endl;
    cout << can_do_sum(7, {2, 4}) << endl; // false
    cout << can_do_sum(8, {2, 3, 5}) << endl;
    cout << can_do_sum(300, {7, 14}) << endl; // false
    return 0;
}