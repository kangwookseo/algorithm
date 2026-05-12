#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> solution(std::vector<int> arr) 
{
    std::vector<int> answer;
    answer.reserve(arr.size());
    
    for(int idx = 0 ; idx<arr.size() ; ++idx)
    {
       if(answer.empty() || answer.back() != arr[idx])
       {
           answer.emplace_back(arr[idx]);
       }     
    }
    return answer;
}