#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> score;
	std::priority_queue<int, std::vector<int>, std::greater<int>> ans;

	score.reserve(N);
	
	for(int idx = 0; idx<N; ++idx)
	{
		int d, w;
		std::cin >> d >> w;
		score.emplace_back(d, w);
	}

	std::sort(score.begin(), score.end());
	
	int sum = 0;
    
	for(int idx = 0; idx<N; ++idx)
	{
		ans.emplace(score[idx].second);

		if (ans.size() > score[idx].first)
		{
			ans.pop();
		}
	}

	while (ans.empty() == false)
	{
		sum += ans.top();
		ans.pop();
	}
	std::cout << sum;


}
