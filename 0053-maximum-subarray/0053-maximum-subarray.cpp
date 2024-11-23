class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0;
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                s+=nums[j];
                maxi=max(maxi,s);
            }
        }
        return maxi;
    }
};

int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

int digit(char c) {
    return c & 15;
}
bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

int in = [] {
    std::ofstream out("user.out"); 
    std::cout.rdbuf(out.rdbuf());

    int ans, sum;
    bool _neg;
    
    
    for (std::string s; std::getline(std::cin, s); std::cout << '\n') {
        ans = -1e9, sum = 0; 
        
        for (int _i = 1, _n = s.length(), v; _i < _n; ++_i) {
            _neg = false; 
            
            if (s[_i] == '-') { 
                ++_i; 
                _neg = true; 
            }
            
            v = digit(s[_i]); 
            
            
            while (isDigit(s[++_i]))
                v = v * 10 + digit(s[_i]);
            
        
            if (_neg)
                v = -v;
            
            ans = std::max(ans, sum < 0 ? sum = v : sum += v);
        }
        
     
        std::cout << ans;
    }
    exit(0);
    return 0;
}();