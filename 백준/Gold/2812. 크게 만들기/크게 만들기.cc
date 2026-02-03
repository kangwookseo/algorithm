#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;
	
	std::string num;
	std::cin >> num;

	std::string ans;
	ans.reserve(N);

	for (char c : num)
	{
		while (ans.empty() == false && K > 0 && ans.back() < c )
		{
			ans.pop_back();
			K--;
		}
		ans.push_back(c);
	}

	if (K > 0)
	{
		ans.resize(ans.size() - K);
	}

	for (char c : ans)
	{
		std::cout << c;
	}
}


