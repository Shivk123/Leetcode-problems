// Last updated: 5/28/2025, 9:53:34 PM
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        using CharIntPair = pair<char, int>;

        auto compare = [](const CharIntPair& x, const CharIntPair& y) {
            return x.second < y.second;
        };

        priority_queue<CharIntPair, vector<CharIntPair>, decltype(compare)>
            maxHeap(compare);

        if (a > 0)
            maxHeap.push({'a', a});
        if (b > 0)
            maxHeap.push({'b', b});
        if (c > 0)
            maxHeap.push({'c', c});

        string result;

        while (!maxHeap.empty()) {
            CharIntPair current = maxHeap.top();
            maxHeap.pop();

            int length = result.size();
            if (length >= 2 && result[length - 1] == current.first &&
                result[length - 2] == current.first) {
                if (maxHeap.empty()) {
                    break;
                }

                CharIntPair next = maxHeap.top();
                maxHeap.pop();
                result.push_back(next.first);

                if (--next.second > 0) {
                    maxHeap.push(next);
                }

                maxHeap.push(current);
            } else {
                result.push_back(current.first);
                if (--current.second > 0) {
                    maxHeap.push(current);
                }
            }
        }

        return result;
    }
};