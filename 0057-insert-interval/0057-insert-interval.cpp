class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        int n=v.size();
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        int prev_start=v[0][0],prev_end=v[0][1];
        
        for(int i=1;i<n;i++){
            int curr_start=v[i][0],curr_end=v[i][1];
            if(curr_start<=prev_end){
                prev_end=max(prev_end,curr_end);
                
            }else{
                ans.push_back({prev_start,prev_end});
                prev_start=curr_start;
                prev_end=curr_end;
            }
        }
        ans.push_back({prev_start,prev_end});
        return ans;
    }
};