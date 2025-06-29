#include <bits/stdc++.h>
using namespace std;

vector<int> bit, nums;

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= (i & -i);
    }
    return s;
}

void update(int i, int val) {
    int n = bit.size();
    while (i < n) {
        bit[i] += val;
        i += (i & -i);
    }
}

int rangesum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    int n;
    cin >> n;

    nums.resize(n + 1);
    bit.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++) {
        update(i, nums[i]);
    }

    update(3, 10);
    cout << "Sum(5): " << sum(5) << endl;

    cout << "RangeSum(2,5): " << rangesum(2, 5) << endl;

    update(4, 9);
    cout << "RangeSum(4,8): " << rangesum(4, 8) << endl;

    return 0;
}
