#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    bool plus = true;
    for(char c: s){
        if(c == '-') plus = false;
        else if( c == '+') continue;
        else{
            answer += c -'0';
            answer *= 10;
        }        
    }
    answer /= 10;
    if( plus == false) answer = - answer;
    return answer;
}