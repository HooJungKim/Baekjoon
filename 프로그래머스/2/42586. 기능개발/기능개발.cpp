#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i = 0;
    int cnt = 0;
    while(i < progresses.size()){
        for(int j = i; j< speeds.size(); j++){
            progresses[j] += speeds[j];
        }
        cnt = 0;
        while(progresses[i] >= 100){
            if( i < progresses.size()){
                i++;
                cnt++;
            }
            else break;            
        } 
        if(cnt != 0)answer.push_back(cnt);
    }
    return answer;
}