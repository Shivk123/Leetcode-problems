// Last updated: 5/28/2025, 9:50:26 PM
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int it: nums){
            pq.push(it);
        }
        unsigned long long int c=0,a=0;
        while(k--){
            a=pq.top();
            c+=a;
            pq.pop();
            pq.push(ceil(a/3.0));
        }
        return c;
    }
};