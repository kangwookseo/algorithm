#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    int size = prices.size();
    vector<int> answer(size);
    stack<int> index;
    
    for(int idx = 0; idx<size ; ++idx)
    {
        while(index.empty() == false && prices[index.top()] > prices[idx])
        {
            int top = index.top();
            index.pop();
            
            answer[top] = idx-top;
        }
        
        index.emplace(idx);
    }
    
    while(index.empty() == false)
    {
        int top = index.top();
        index.pop();
        
        answer[top] = (size-1) - top;
    }
    return answer;
}