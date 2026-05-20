#include <string>
#include <vector>
#include <queue>
int solution(std::vector<int> priorities, int location) 
{
    int answer = 0;
  	std::queue<std::pair<int, int>> stor;
    std::priority_queue<int> index;
    
    for(int idx = 0; idx<priorities.size() ; ++idx)
    {
        stor.emplace(priorities[idx] , idx);
        index.emplace(priorities[idx]);
    }
    
    while(stor.empty() == false)
    {
        int cur_pri = stor.front().first;
        int cur_idx = stor.front().second;
        
        if(cur_pri == index.top())
        {
            answer++;
            stor.pop();
            index.pop();
            
            if(cur_idx == location)
            {
                break;
            }
        }
        else
        {
           stor.pop();
           stor.emplace(cur_pri, cur_idx);
        }
    }
    return answer;
}