#include <iostream>
#include <queue>
#include <algorithm>

int bfs(int start, int target)
{
	std::vector<int> visited(100001, 1000000);
	std::deque<int> q;
	
	q.push_front(start);
	visited[start] = 0;
	
	while (q.empty() == false)
	{
		int cur = q.front();
		q.pop_front();
		
		if (cur == target)
		{
			return visited[cur];
		}
		
		int tele = cur*2;
		if (cur <target && tele <= 100000 && visited[tele] > visited[cur])
		{
			visited[tele] = visited[cur];
			q.push_front(tele);
		}
		
		int move_front = cur +1;
		if (cur<target && move_front <= 100000 && visited[move_front] > visited[cur] +1)
		{
			visited[move_front] = visited[cur] + 1;
			q.push_back(move_front);
		}
		
		int move_back = cur -1;
		if (move_back >=0 && move_back <= 100000 && visited[move_back] > visited[cur] + 1)
		{
			visited[move_back] = visited[cur] + 1;
			q.push_back(move_back);
		}
	}
	
	return -1;
	
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
		
	int N, K;
	std::cin>>N>>K;
	
	std::cout<<bfs(N,K);
}
