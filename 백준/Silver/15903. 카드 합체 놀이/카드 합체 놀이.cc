#include <iostream>
#include <queue>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::priority_queue<long long,std::vector<long long>, std::greater<long long>> card;
	int n, m;
	long long result = 0;

	std::cin >> n >> m;

	while (n-- > 0)
	{
		long long a;
        
		std::cin >> a;
		card.emplace(a);
	}

	for (int idx = 0; idx < m; ++idx)
	{
		long long min = card.top();
		card.pop();
		long long sec_min = card.top();
		card.pop();
		long long res = min + sec_min;
		
		card.emplace(res);
		card.emplace(res);
	}

	while (card.empty() == false)
	{
		result += card.top();
		card.pop();
	}
	std::cout << result<<'\n';

}