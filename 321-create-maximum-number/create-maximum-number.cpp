class Solution {
public:
    // Get max subsequence of length k from a vector
    vector<int> getMaxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;
        for (int num : nums) {
            while (!st.empty() && st.back() < num && drop > 0) {
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }
        st.resize(k);
        return st;
    }

    // Compare sequences by lexicographic order starting from i and j
    bool greaterSeq(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        return j == b.size() || (i < a.size() && a[i] > b[j]);
    }

    // Merge two sequences into max lexicographic result
    vector<int> merge(vector<int>& a, vector<int>& b, int k) {
        vector<int> res;
        int i = 0, j = 0;
        while (res.size() < k) {
            if (greaterSeq(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best(k, 0);
        int n1 = nums1.size(), n2 = nums2.size();

        for (int i = max(0, k - n2); i <= min(k, n1); i++) {
            vector<int> s1 = getMaxSubsequence(nums1, i);
            vector<int> s2 = getMaxSubsequence(nums2, k - i);
            vector<int> candidate = merge(s1, s2, k);

            if (greaterSeq(candidate, 0, best, 0))
                best = candidate;
        }

        return best;
    }
};
