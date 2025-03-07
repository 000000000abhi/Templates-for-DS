#include <vector>
#include <climits>
using namespace std;

class Sgt {
    vector<int> seg;

public:
    Sgt(int n) {
        seg.resize(4 * n + 1, INT_MAX);
    }

    void build(int low, int high, vector<int>& nums, int idx) {
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(low, mid, nums, 2 * idx + 1);
        build(mid + 1, high, nums, 2 * idx + 2);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if (r < low || l > high) return INT_MAX;
        if (low >= l && high <= r) return seg[ind];
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]); // Update internal nodes
    }
};
