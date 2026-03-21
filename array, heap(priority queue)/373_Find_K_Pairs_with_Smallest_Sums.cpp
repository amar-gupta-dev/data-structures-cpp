// Leetcode 373
// Problem: Find K Pairs with Smallest Sums
// Topic: array, heap(priority queue)
// Diff: medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        if (nums1.empty() || nums2.empty() || k == 0) return result;

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > pq;

        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};
