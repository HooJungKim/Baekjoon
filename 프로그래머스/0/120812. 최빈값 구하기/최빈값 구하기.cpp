#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int table[1000] = {0, };
    for(int a: array){
        table[a]++;
    }
    int max = *max_element(table, table + 1000);
    int count = 0;
    for(int i=0; i<1000; i++){
        if(table[i] == max) {
            answer = i; 
            count++;
        }
    }
    if(count > 1) answer = -1;
    return answer;
}