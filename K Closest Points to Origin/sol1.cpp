
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> triples;//dist,x,y
    vector<vector<int>> ans{};
    for (auto& p : points)
        triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
    // Min heap of vectors (triples). This constructor takes O(n) time (n = len(v))
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
    while(ans.size()<k){
        vector<int> temp =pq.top();
        ans.push_back(vector<int>{temp[1],temp[2]});
        pq.pop();//log(n)
    }
    return ans;
    }
};
