// Last updated: 5/28/2025, 9:47:54 PM
class Solution {
    private:
    long long digit_sum(int num){
        int ans=0;
        while(num){
            ans+=num%10;
            num=num/10;
        }
        return ans*1LL*INT_MAX*1LL;
    }
public:
    int minSwaps(vector<int>& nums) {
        const int n=nums.size();
        vector<long long> sumed(n);
        for(int i=0;i<n;i++){
            sumed[i]=nums[i]+(digit_sum(nums[i])*1LL);
        }

        vector<bool> vis(n,false);

        unordered_map<long long,int> pos;
        for(int i=0;i<n;i++){
            pos[sumed[i]]=i;
        }
        sort(sumed.begin(),sumed.end());
        int swaps=0;
        for(int i=0;i<n;i++){
            if(vis[i]||pos[sumed[i]]==i)continue;
            int j=i,cSize =0;

            while(!vis[j]){
                vis[j]=true;

                j=pos[sumed[j]];
                cSize++;
            }

            if(cSize>0){
                swaps+=cSize-1;
            }
        }
        return swaps;
    }
};