class Solution {
 public:
  bool isTransformable(string s, string t) {
    if (getCount(s) != getCount(t))
      return false;

    vector<queue<int>> positions(10);

    for (int i = 0; i < s.length(); ++i)
      positions[s[i] - '0'].push(i);
    for (const char c : t) {
      const int d = c - '0';
      const int front = positions[d].front();
      positions[d].pop();
      for (int smaller = 0; smaller < d; ++smaller)
        if (!positions[smaller].empty() && positions[smaller].front() < front)
          return false;
    }
    return true;
  }

 private:
  vector<int> getCount(const string& s) {
    vector<int> count(10);
    for (const char c : s)
      ++count[c - '0'];
    return count;
  }
};