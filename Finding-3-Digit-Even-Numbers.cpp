class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> count(10);

        for (const int digit : digits)
            ++count[digit];

        for (int a = 1; a <= 9; ++a) {
            if (count[a] == 0)
                continue;
            count[a]--;
            for (int b = 0; b <= 9; ++b) {
                if (count[b] == 0)
                    continue;
                count[b]--;
                for (int c = 0; c <= 8; c += 2) {
                    if (count[c] == 0)
                        continue;

                    ans.push_back(a * 100 + b * 10 + c);
                }
                count[b]++;
            }
            count[a]++;
        }
        return ans;
    }
};