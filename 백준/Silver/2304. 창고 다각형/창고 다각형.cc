#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> imm(N);

	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> imm[idx].first >> imm[idx].second;


	}
	sort(imm.begin(), imm.end());

	auto maxit = max_element(imm.begin(), imm.end(),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b)
		{
			return a.second < b.second;
		}
	);

		
	int max_idx = maxit - imm.begin();

	int total_area = 0;
	int cur_h = 0;

	for(int idx = 0; idx < max_idx; ++idx)
	{
		if (imm[idx].second > cur_h)
		{
			cur_h = imm[idx].second;
		}
		total_area += (imm[idx + 1].first - imm[idx].first) * cur_h;

	}

	cur_h = 0;
	for (int idx = N - 1; idx > max_idx; --idx)
	{
		if (imm[idx].second > cur_h)
		{
			cur_h = imm[idx].second;
		}
		total_area += (imm[idx].first - imm[idx - 1].first) * cur_h;
	}

	total_area += maxit->second;
	std::cout << total_area << '\n';

}