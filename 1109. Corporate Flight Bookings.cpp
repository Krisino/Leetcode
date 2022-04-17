class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> difference(n + 1, 0);
        for(int i = 0; i < bookings.size(); i++) {
            int l = bookings[i][0];
            int r = bookings[i][1];
            int v = bookings[i][2];
            difference[l - 1] += v;
            difference[r] -= v;
        }
        difference.resize(n);
        for(int i = 1; i < n; i++) {
            difference[i] += difference[i - 1]; 
        }
        return difference;
    }
};