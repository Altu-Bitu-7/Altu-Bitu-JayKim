#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string makeIt(map<char, int> m) {
    int count = 0;
    char odd = 'z';  // 초기화
    string firstHalf = "", secondHalf = "", answer = "";

    for (const auto &pair : m) {
        if (pair.second % 2 == 1) {
            count += 1;
            odd = pair.first; 
        }

        // 짝수 개의 문자를 절반씩 나누어 양쪽에 추가하기 위해, 처음 앞쪽 firstHalf 생성. 
        firstHalf += string(pair.second / 2, pair.first);
    }

    if (count > 1) {
        return "I'm Sorry Hansoo"; //return이 걸리면 더 이상의 연산은 없다. 
    }

    secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end()); //뒤집기 

    if (odd != 'z') {
        answer = firstHalf + odd + secondHalf;
    } else {
        answer = firstHalf + secondHalf;
    }

    return answer;
}

int main() {
    string name;
    map<char, int> freq;

    cin >> name;

    for (char c : name) {
        freq[c]++;
    }

    cout << makeIt(freq);

    return 0;
}
