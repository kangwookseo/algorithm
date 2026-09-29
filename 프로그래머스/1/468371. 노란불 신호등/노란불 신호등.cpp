#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while((b ==0) == false)
    {
        int x = a % b;
        a = b;
        b = x;
        
    }
    return a;
}

int solution(vector<vector<int>> signals) 
{
    int n = signals.size();
    
    int limit = 1;
    
    for(auto& s : signals)
    {
        int cycle = s[0] + s[1] + s[2];
        limit = limit / gcd(limit, cycle) * cycle;
    }
    
    for (int t = 1; t<= limit; ++t )
    {
        bool allYellow = true;
        for(auto& s : signals)
        {
            int cycle = s[0] + s[1] + s[2];
            int pos = (t-1)%cycle;
            
            if((((s[0]) <= pos) && (pos < s[0] + s[1])) == false)
            {
                allYellow = false;
                break;
            }
        }
        
        if(allYellow)
        {
            return t;
        }
    }
    return -1;
}

