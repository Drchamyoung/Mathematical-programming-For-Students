#pragma GCC optimize("O3,unroll-loops")

constexpr u_int SIZE = 600;
constexpr u_int DIV = 256 + 300;

constexpr int NUM = 1l << 15;

class Solution {
private:
    int dydxs[DIV];
    short divs[DIV];
    short rems[DIV];
public:
    int maxPoints(vector<vector<int>>& points) {
        u_int n = points.size();
        if (n < 3)
            return n;
        int p[SIZE];
        int* pp = p;
        for (auto it = points.begin(); it < points.end(); it++) {
            *pp++ = (*it)[0];
            *pp++ = (*it)[1];
        }
        const int* end = pp;
        u_int maxc = 0;
        const int* p0 = p;
        while (p0 < end) {
            int x0 = *p0++; int y0 = *p0++;
          
            for (u_int i = 0; i < DIV; i++) {
                dydxs[i] = 0;
            }
            u_int zyc = 0;
            u_int zxc = 0;
            u_int lm = 0;
            const int* p1 = p0;
            while (p1 < end) {
                int x = *p1++; int y = *p1++;
                int dx = x - x0; int dy = y - y0;
                if (dx == 0) {
                    zxc++;
                
                } else if (dy == 0) {
                    zyc++;
                 
                } else {
                    int dyd = dy * NUM;
                    int dydx = dyd / dx;
                    int rem = dyd % dx;
                 
                    u_int pos = dydx & 0xffu;
                    u_int c = 0;
                    while (dydxs[pos] != 0) {
                        c += dydxs[pos] == dydx && divs[pos] * rem == rems[pos] * dx;
                        pos++;
                    }
                 
                    lm = std::max(lm, ++c);
                 
                    dydxs[pos] = dydx;
                    rems[pos] = rem;
                    divs[pos] = dx;
                }
            }
            maxc = std::max(maxc, std::max(lm, std::max(zyc, zxc)));
        
        }
        return ++maxc;
    }
};