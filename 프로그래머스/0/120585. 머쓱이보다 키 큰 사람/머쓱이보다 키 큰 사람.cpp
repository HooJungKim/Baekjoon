#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    for(int n : array){
        if( n > height) answer++;
    }
    return answer;
}