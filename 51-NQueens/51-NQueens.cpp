// Last updated: 5/28/2025, 9:55:56 PM
class Solution {
private:
    void setQ(vector<vector<string>>& ans, vector<int>& pos) {
        string s;
        vector<string> temp;
        for (int i = 0; i < pos.size(); i++) {
            s += ".";
        }
        for (int i = 0; i < pos.size(); i++) {
            s[pos[i]] = 'Q';
            temp.push_back(s);
            s[pos[i]] = '.';
        }
        ans.push_back(temp);
    }

    bool check(vector<int>& pos, int& idx){
        for(int i=0;i<pos.size();i++){
            if(pos[i]==idx || pos.size()-i==abs(pos[i]-idx))return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<int>& pos, int& n) {
        if (pos.size() == n) {
            setQ(ans,pos);
            return;
        }

        for(int i=0;i<n;i++){
            if(check(pos,i)){
                pos.push_back(i);
                solve(ans,pos,n);
                pos.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos;
        vector<vector<string>> ans;
        solve(ans, pos, n);
        return ans;
    }
};