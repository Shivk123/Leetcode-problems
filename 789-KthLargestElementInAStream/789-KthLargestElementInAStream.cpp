// Last updated: 5/28/2025, 9:54:22 PM
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> minHeap;
    int kthSize;
    KthLargest(int k, vector<int>& nums) {
        kthSize = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kthSize) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */