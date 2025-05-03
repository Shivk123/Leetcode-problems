class Solution {
private:
    bool valid(int a, vector<int>& tops, vector<int>& bottoms) {
        for (int i = 0; i < tops.size(); i++) {
            if (a != tops[i] && a != bottoms[i])
                return false;
        }
        return true;
    }

    int min_shuffle(int a, vector<int>& tops, vector<int>& bottoms) {
        int nt = 0, nb = 0;
        for (int i = 0; i < tops.size(); i++) {
            if (a != tops[i])
                nt++;
            if (a != bottoms[i])
                nb++;
        }
        return min(nt, nb);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = tops[0], b = bottoms[0], ans = INT_MAX;
        if (valid(a, tops, bottoms)) {
            ans = min_shuffle(a, tops, bottoms);
        }
        if (a != b && valid(b, tops, bottoms)) {
            ans = min(ans, min_shuffle(b, tops, bottoms));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};