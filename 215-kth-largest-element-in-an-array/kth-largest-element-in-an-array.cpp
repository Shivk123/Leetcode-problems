class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i:nums){
            pq.push(i);
            if(pq.size()==k+1)pq.pop();
        }
        return pq.top();
    }
};