#include <iostream>
#include <stack>
#include <vector>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N;
	std::cin >> N;

	std::vector<int> arr(N);
	std::vector<int> output(N, -1);
	std::stack<int> not_f;
	
	for (int idx = 0; idx < N; ++idx)
	{
		std::cin >> arr[idx];

		while (not_f.empty() == false && arr[not_f.top()] < arr[idx])
		{
			output[not_f.top()] = arr[idx];
			not_f.pop();
		}
		not_f.push(idx);
	}
	
	for (int idx = 0; idx < N; ++idx)
	{
		std::cout << output[idx]<<" ";
	}
}