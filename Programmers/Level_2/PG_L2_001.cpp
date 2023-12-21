#include <vector>
#include <algorithm>

// Programmers 코딩테스트 LV.2: 카카오 프렌즈 컬러링북

using namespace std;

int M, N;
int Area_num;
bool con[101][101];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline void DFS(const int& i, const int& j, const vector<vector<int>>& pic){
    con[i][j] = true;
    Area_num++;
    for (const auto &P : dir){
        int r_i = i + P.first;
        int c_j = j + P.second;
        if ((0 <= r_i) && (r_i < M) &&
           (0 <= c_j) && (c_j < N) &&
           !con[r_i][c_j] &&
           (pic[i][j] == pic[r_i][c_j])) DFS(r_i, c_j, pic);
    }
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    M = m;
    N = n;
    fill(&con[0][0], &con[M][N], false);
    
    Area_num = 0;
    vector<int> total_area;
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if((picture[i][j] != 0) && !(con[i][j])){
                Area_num = 0;
                DFS(i, j, picture);
                total_area.push_back(Area_num);
            }
    
    number_of_area = total_area.size();
    max_size_of_one_area = *max_element(total_area.begin(), total_area.end());
        
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
