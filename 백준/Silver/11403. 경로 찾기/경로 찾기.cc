#include <iostream>
#include <vector>
#include <algorithm>

int main()

{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> matrix(N, std::vector<int> (N));
    
    for (int idx = 0 ; idx<N; ++idx)
    {   
        for (int s_idx = 0; s_idx <N; ++s_idx)
        {
            std::cin>>matrix[idx][s_idx];
        }
    }
    
    for (int s_idx = 0; s_idx<N;++s_idx)
    {
        for (int idx = 0; idx<N; ++idx)
        {
            for (int t_idx = 0; t_idx<N; ++t_idx)
            {
                if (matrix[idx][s_idx] == 1 && matrix[s_idx][t_idx]==1)
                {
                    matrix[idx][t_idx] =1;
                }
            }
            
        }
    }

    for (int idx = 0; idx<N; ++idx)
    {
        for (int s_idx = 0; s_idx<N; ++s_idx)
        {
            std::cout<<matrix[idx][s_idx]<<" ";
        }
        std::cout<<'\n';
    }
}