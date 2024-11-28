class Solution {
 public:
  long long appealSum(string s) {
    long ans = 0;
    int dp = 0;
    vector<int> lastSeen(26, -1);
    for (int i = 0; i < s.length(); ++i) {
      const int c = s[i] - 'a';
      dp += i - lastSeen[c];
      ans += dp;
      lastSeen[c] = i;
    }
    return ans;
  }
};