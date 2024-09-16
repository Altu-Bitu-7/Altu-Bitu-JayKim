#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

//  모든 알파벳의 빈도수를 저장한다. 

vector <int> getfreq(string str){
    
    vector<int> freq(26, 0);
    for (char c : str) {
        freq[c - 'A']++;
    }
    return freq;
}
// 두 단어의 유사도를 확인한다. 
bool areSimilar(string word1, string word2) {
    vector<int> freq1 = getfreq(word1);
    vector<int> freq2 = getfreq(word2);

    int len = abs((int)word1.size() - (int)word2.size());
    
    // 길이 차이가 2 이상이면 바로 탈락!
    if (len > 1) return false;

    // 문자 빈도수 차이
    // 모든 알파벳에 따라 그 frequency를 비교한다. 
    int diffCount = 0;
    
    for (int i = 0; i < 26; i++) {
        diffCount += abs(freq1[i] - freq2[i]);
    }

    // 완전히 같으면? 
    if (diffCount == 0) return true;

    // 한 문자를 더하거나, 빼거나, 바꿔서 비슷하게 만들 수 있는 경우
    if (len == 0 && diffCount == 2) return true; // 한 문자를 다른 문자로 바꾸는 경우, diffCount는 차이가 2개이다. 
    if (len == 1 && diffCount == 1) return true; // 한 문자를 추가하거나 빼는 경우

    return false;  // 비슷하지 않음
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string firstWord = words[0];
    int similarCount = 0;

    // 첫 번째 단어와 다른 모든 단어를 비교
    for (int i = 1; i < n; i++) {
        if (areSimilar(firstWord, words[i])) {
            similarCount++;
        }
    }

    cout << similarCount << "\n";
    return 0;
}
