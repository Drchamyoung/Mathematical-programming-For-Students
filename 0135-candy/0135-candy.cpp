class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        vector<int> candies(ratings.size(),1);
        for(int i = 1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                candies[i]=max(candies[i],candies[i-1]+1);
            }
        }
        for(int i = ratings.size()-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        int total = accumulate(candies.begin(),candies.end(),0);
        return total;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 0;
} ();