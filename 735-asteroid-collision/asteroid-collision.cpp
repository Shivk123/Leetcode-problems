class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int it : asteroids) {
            bool destroyed = false;

            // Collision condition: top > 0 and it < 0
            while (!st.empty() && st.top() > 0 && it < 0) {
                if (abs(st.top()) < abs(it)) {
                    st.pop(); // top is smaller → pop and continue checking
                } 
                else if (abs(st.top()) == abs(it)) {
                    st.pop(); // both destroy each other
                    destroyed = true;
                    break;
                } 
                else { 
                    destroyed = true; // new asteroid destroyed
                    break;
                }
            }

            // If not destroyed, push it
            if (!destroyed) st.push(it);
        }

        // Transfer stack to vector
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
