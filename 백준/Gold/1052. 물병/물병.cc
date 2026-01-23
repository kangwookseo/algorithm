#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	
	int N,K; //N이 물병 개수, K는 한번에 옮길수 있는 물병 수
	std::cin >> N>>K;
	
	int ans = 0;

	while(true)
	{
		int tempN = N;
		int count = 0;

		while (tempN > 0)
		{
			if (tempN % 2 == 1)
			{
				count ++ ;

			}
			tempN /= 2;
		}
		if (count <= K)
		{
			break;
		}
		N++;
		ans++;
	}
	std::cout << ans;
	
}