#include <string>
#include <vector>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds) 
{
    std::vector<int> answer;
    std::vector<int> res;
    res.reserve(progresses.size());
    
    for(int idx = 0; idx<progresses.size(); ++idx)
    {
        int x = 100- progresses[idx];
        int day = x/speeds[idx];
        
        if(x % speeds[idx] != 0)
        {
         	day++; 	
        }
        res.emplace_back(day);
    }
    
    int cur = res[0];
    int count = 1;
    
    for(int idx = 1; idx<res.size() ; ++idx)
    {
        if(res[idx] <=cur)
        {
            count++;
        }
        else
        {
          	answer.emplace_back(count);
            count = 1;
            cur = res[idx];
        }
    }
    
    answer.emplace_back(count);
    
    
    return answer;
}