class Solution {
    private:
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>& visited){
        visited[i]=true;
        for(int j=0;j<isConnected[i].size();j++){
            if(isConnected[i][j]==1 && !visited[j])dfs(j,isConnected,visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
};