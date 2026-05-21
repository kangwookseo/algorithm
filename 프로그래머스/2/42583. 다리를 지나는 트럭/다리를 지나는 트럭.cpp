#include <string>
#include <vector>
#include <queue>

int solution(int bridge_length, int weight, std::vector<int> truck_weights) 
{
    int answer = 0;
    int cur_wei = 0;
    std::queue<int> bridge;
   	
    for(int idx = 0; idx<bridge_length; ++idx)
    {
        bridge.emplace(0);
    }
   	
    int truck_idx = 0;
    
    while(truck_idx < truck_weights.size())
    {
        answer++;
        cur_wei-=bridge.front();
        bridge.pop();
        
        if(cur_wei + truck_weights[truck_idx] <= weight)
        {
         	bridge.emplace(truck_weights[truck_idx]);
            cur_wei+=truck_weights[truck_idx];
            truck_idx++;
        }
        else
        {
            bridge.emplace(0);
        }
    }
    answer += bridge_length;
    
    return answer;
}