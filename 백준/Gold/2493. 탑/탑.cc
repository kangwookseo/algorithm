#include <iostream>
#include <vector>
#include <stack>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> top(N);
	std::stack<std::pair<int, int>> st;

	for (int idx = 0; idx < N; ++idx)
	{
		int height;
		std::cin >> height;

		while (st.empty() ==false && st.top().first <= height)
		{
			st.pop();
		}
		
		top[idx] = st.empty() ? 0 : st.top().second + 1;

		st.push(std::make_pair(height, idx));
	}
	for (int idx = 0; idx < N; ++idx)
	{
		std::cout << top[idx] << " ";
	}
}