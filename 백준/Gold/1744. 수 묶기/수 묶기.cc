#include <iostream>
#include <queue>
#include <vector>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::priority_queue<int> pos;
	std::priority_queue<int, std::vector<int>, std::greater<int>> neg;
	

	int N;
	std::cin >> N;

	long long sum = 0;

	for(int idx = 0; idx<N; ++idx)
	{
		int x;
		std::cin >> x;
		if (x > 1)
		{
			pos.emplace(x);
		}
        else if (x == 1)
        {
	        sum += 1;
        }
		else
		{
			neg.emplace(x);
		}
	}

	while (pos.size() >= 2)
	{
		int a = pos.top();
		pos.pop();
		int b = pos.top();
		pos.pop();

		sum += 1LL * a * b; //lLL
	}
	if (pos.empty() == false)
	{
		sum += pos.top();
	}

	while (neg.size() >= 2)
	{
		int a = neg.top();
		neg.pop();
		int b = neg.top();
		neg.pop();
		sum += 1LL * a * b;
	}
	if (neg.empty() == false)
	{
		sum += neg.top();
	}

	std::cout << sum;
}