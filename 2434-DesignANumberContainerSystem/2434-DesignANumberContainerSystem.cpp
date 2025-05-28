// Last updated: 5/28/2025, 9:51:04 PM
#include <map>
#include <set>

class NumberContainers {
public:
    std::map<int, int> indexToNumberMap;

    std::map<int, std::set<int>> numberToIndicesMap;

    NumberContainers() {}

    void change(int index, int number) {
        auto it = indexToNumberMap.find(index);
        if (it != indexToNumberMap.end()) {
            numberToIndicesMap[it->second].erase(index);
            it->second = number;
        } else {
            indexToNumberMap[index] = number;
        }
        numberToIndicesMap[number].insert(index);
    }

    int find(int number) {
        auto it = numberToIndicesMap.find(number);
        return (it == numberToIndicesMap.end() || it->second.empty())
                   ? -1
                   : *it->second.begin();
    }
};