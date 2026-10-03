#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0;
    int member_count = schedules.size();
    
    for(int count = 0; count < member_count ; ++count)
    {
        int hour = schedules[count]/100;
        int minute = schedules[count]%100+10;
        bool success = true;
        
        if(minute>=60)
        {
           minute -= 60;
            hour++;
        }
        
        int limit = hour * 100 + minute;
        
        for (int idx= 0; idx < 7; ++idx)
        {
            int day = (startday - 1 + idx) % 7 + 1;
            
            if(day == 6 || day == 7)
            {
                continue;
            }

            if(timelogs[count][idx] > limit)
            {
                success = false;
                break;
            }
        }
        if(success)
        {
            answer++;
        }
    }
    
    return answer;
  
}