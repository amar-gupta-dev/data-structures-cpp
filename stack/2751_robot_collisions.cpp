// Leetcode 2751
// Problem: robot collisions
// Topic: stack, simulation, sorting
// Diff: hard

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // store index and sort by position
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st; // store indices of robots moving right

        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                // moving left
                while (!st.empty() && healths[i] > 0) {
                    int j = st.top();
                    st.pop();

                    if (healths[j] > healths[i]) {
                        healths[j]--;
                        healths[i] = 0;
                        st.push(j);
                    } else if (healths[j] < healths[i]) {
                        healths[i]--;
                        healths[j] = 0;
                    } else {
                        healths[i] = 0;
                        healths[j] = 0;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};
