// Last updated: 5/28/2025, 9:47:53 PM
#include <algorithm>
#include <vector>

class Solution {
public:
    long long maxWeight(std::vector<int>& pizzas) {
        std::sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size(), odd = ((n / 4) + 1) / 2, even = (n / 4) - odd,
            j = n - 1;
        long long ans = 0;

        for (int i = 0; i < odd; i++) {
            ans += pizzas[j--];
        }
        for (int i = 0; i < even; i++) {
            j--;
            ans += pizzas[j--];
        }
        return ans;
    }
};