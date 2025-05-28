// Last updated: 5/28/2025, 9:52:05 PM
using Pair = pair<int, int>;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int, vector<int>, greater<int>> availableChairs;
      
        priority_queue<Pair, vector<Pair>, greater<Pair>> occupiedChairs;
      
        int numberOfFriends = times.size();
      
        for (int i = 0; i < numberOfFriends; ++i) {
            times[i].push_back(i);
            availableChairs.push(i);
        }
      
        sort(times.begin(), times.end());
      
        for (auto& time : times) {
            int arriveTime = time[0], leaveTime = time[1], index = time[2];
          
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arriveTime) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop(); 
            }
          
            int chair = availableChairs.top();
            availableChairs.pop();
          
            if (index == targetFriend) {
                return chair;
            }
          
            occupiedChairs.push({leaveTime, chair});
        }
      
        return -1;
    }
};