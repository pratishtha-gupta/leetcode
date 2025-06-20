class Solution {
    long long cnt = 0;

    void merge(int l, int r, int mid, vector<int>& nums) {
        int lsz = mid - l + 1;
        int rsz = r - mid;

        vector<int> left(lsz);
        vector<int> right(rsz);
        for (int i = 0; i < lsz; i++) {
            left[i] = nums[l + i];
        }
        for (int i = 0; i < rsz; i++) {
            right[i] = nums[mid + 1 + i];
        }

        int li = 0, ri = 0, idx = l;
        while (li < lsz && ri < rsz) {
            if (left[li] <= right[ri]) {
                nums[idx++] = left[li++];
            } else {
                nums[idx++] = right[ri++];
            }
        }
        while (li < lsz) nums[idx++] = left[li++];
        while (ri < rsz) nums[idx++] = right[ri++];
    }

    void countpairs(int left, int mid, int right, vector<int>& nums) {
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
    }

    void mergesort(int l, int r, vector<int>& nums) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergesort(l, mid, nums);
        mergesort(mid + 1, r, nums);
        countpairs(l, mid, r, nums);  // Count before merging
        merge(l, r, mid, nums);       // Then merge
    }

public:
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergesort(0, nums.size() - 1, nums);
        return (int)cnt;
    }
};
