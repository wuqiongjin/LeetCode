class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        int x = pq.top(), y = 0;    //x = pq.top()防止只有1个元素的时候，无法进入循环
        while(pq.size() > 1)
        {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            x -= y;
            pq.push(x);
        }
        return x;
    }
};