#include <bits/stdc++.h>
using namespace std;
// Find nearest smaller to left and nearest smaller to right
class Solution
{
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n == 1) return heights[0];
		stack<int> st;
		int i = 0;
		long long area = 0;
		while (i < n) {
			if (st.empty() || heights[st.top()] <= heights[i]) {
				st.push(i);
				i++;
			} else {
				int top_id = st.top();
				st.pop();

				if (st.empty()) {
					//there is no smaller element in left
					area = max(area, 1LL * heights[top_id] * i);
				} else {
					//find area between i-1 to left small el i.e. st.top()
					area = max(area, 1LL * heights[top_id] * (i - 1 - st.top()));
				}
			}
		}
		while (!st.empty()) {
			int top_id = st.top();
			st.pop();

			if (st.empty()) {
				//there is no smaller element in left
				area = max(area, 1LL * heights[top_id] * i);
			} else {
				//find area between i-1 to left small el i.e. st.top()
				area = max(area, 1LL * heights[top_id] * (i - 1 - st.top()));
			}
		}
		return area;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n ;
		cin >> n;
		std::vector<int> heights(n, 0);
		for (int i = 0; i < n; i++) cin >> heights[i];
		Solution solve;
		cout << solve.largestRectangleArea(heights) << endl;
	}
}
