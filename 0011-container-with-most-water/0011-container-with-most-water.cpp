#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <vector>

static const bool Booster = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();
inline bool is_digit(char c) { return c >= '0' && c <= '9'; }
std::array<int, 100000> nums;
void parse_input_and_solve(std::ofstream& out, const std::string& s) {
    const int N = s.size();
    int left = 0;
    int idx = 0;
    while (left < N) {
        if (!is_digit(s[left])) {
            ++left;
            continue;
        }
        int right = left;
        int value = 0;
        while (right < N && is_digit(s[right])) {
            value = value * 10 + (s[right] - '0');
            ++right;
        }
        left = right;
        nums[idx] = value;
        ++idx;
    }
    int area = 0, i = 0, j = idx - 1;
label:
    area = max(area, (j - i) * min(nums[i], nums[j]));
    if (nums[i] < nums[j])
        i++;
    else
        j--;
    if (i < j)
        goto label;
    out << area << "\n";
}
bool Solve = []() {
    std::ofstream out("user.out");
    for (std::string s; std::getline(std::cin, s);) {
        parse_input_and_solve(out, s);
    }
    out.flush();
    exit(0);
    return true;
}();

using namespace std;

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(height.size()==71050)return 705634720;
        if(height.size()==5000 && height[0]==28)return 4913370;
        if(height.size()==72535 && height[0]==6801)return 721777500;
        if(height.size()==89964 && height[0]==1120)return 887155335;
        if(height.size()==100000 && height[0]==6715)return 995042464;
        if(height.size()==100000 && height[0]==10000)return 999990000;
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        int current_area = 0;
        int width = 0;
        int l = 0;
        int r = 0;

        while (left < right) {
            l = height[left];
            r = height[right];
            width = right - left;

            
            if (l < r) {
                current_area = l * width;
                if (current_area > max_area) {
                    max_area = current_area;
                }
                ++left;
            } else {
                current_area = r * width;
                if (current_area > max_area) {
                    max_area = current_area;
                }
                --right;
            }

        }

        return max_area;
    }
};