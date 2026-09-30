#include <string>
#include <vector>

using namespace std;

int getCol(int k , int w)
{
    int idx = k - 1;
    int row = idx /w , pos = idx % w;
    return (row % 2 == 0) ? pos : w - 1 - pos;
}

int solution(int n, int w, int num) 
{
    int target = getCol(num, w);
    int answer = 0;
    
    for (int k = num; k<=n; ++k)
        {
            if(getCol(k,w) == target)
            {
                answer++;
            }
        }
    return answer;
    
}