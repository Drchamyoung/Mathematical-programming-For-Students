class Solution {
 public:
  vector<int> countPairs(int n, vector<vector<int>>& edges,
                         vector<int>& queries) {
    vector<int> ans(queries.size());
    vector<int> count(n + 1);
    vector<unordered_map<int, int>> shared(n + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      ++count[u];
      ++count[v];
      ++shared[min(u, v)][max(u, v)];
    }

    vector<int> sortedCount(count);
    ranges::sort(sortedCount);

    int k = 0;
    for (const int query : queries) {
      for (int i = 1, j = n; i < j;)
        if (sortedCount[i] + sortedCount[j] > query)
          ans[k] += (j--) - i;
        else
          ++i;
      for (int i = 1; i <= n; ++i)
        for (const auto& [j, sh] : shared[i])
          if (count[i] + count[j] > query && count[i] + count[j] - sh <= query)
            --ans[k];
      ++k;
    }

    return ans;
  }
};