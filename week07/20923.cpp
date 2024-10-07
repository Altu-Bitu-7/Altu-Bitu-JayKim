#include <iostream>
#include <deque>
using namespace std;

void bell(deque<int>& winnerDeck, deque<int>& myGround, deque<int>& yourGround) {
    // 상대방 그라운드의 카드를 가져가서 뒤집어 덱에 추가
    while (!yourGround.empty()) {
        winnerDeck.push_back(yourGround.back());
        yourGround.pop_back();
    }
    // 내 그라운드의 카드를 가져가서 뒤집어 덱에 추가
    while (!myGround.empty()) {
        winnerDeck.push_back(myGround.back());
        myGround.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> dodo, suyeon;
    deque<int> dodoGround, suyeonGround;

    // 입력 처리: 도도와 수연이의 덱을 읽어들임
    for (int i = 0; i < n; i++) {
        int dCard, sCard;
        cin >> dCard >> sCard;
        dodo.push_front(dCard);    // 입력된 순서대로 덱에 저장
        suyeon.push_front(sCard);
    }

    // M번의 게임 진행
    bool doTurn = true;  // 도도가 먼저 시작
  
    for (int i = 0; i < m; i++) {
        if (dodo.empty() || suyeon.empty()) break;  // 누군가의 덱이 비면 종료

        if (doTurn) {
            // 도도의 차례
            int card = dodo.front();  // 도도의 덱에서 카드 꺼내기
            dodo.pop_front();
            dodoGround.push_front(card);  // 도도의 그라운드에 카드 놓기

            // 종 치는 조건 체크
            if (card == 5) {
                bell(dodo, dodoGround, suyeonGround);  // 도도가 종을 친다
            } 
        }
        
        else {
            // 수연이의 차례
            int card = suyeon.front();  // 수연이의 덱에서 카드 꺼내기
            suyeon.pop_front();
            suyeonGround.push_front(card);  // 수연이의 그라운드에 카드 놓기

            // 종 치는 조건 체크
            if (card == 5) {
                bell(dodo, dodoGround, suyeonGround);  // 도도가 종을 친다
            }
        }

        if (!dodoGround.empty() && !suyeonGround.empty() && (dodoGround.front() + suyeonGround.front() == 5)) {
          bell(suyeon, suyeonGround, dodoGround);  // 수연이가 종을 친다
      }
        
        doTurn = !doTurn;  // 차례 변경
    }

    // 게임 종료 후 승리 판정
    if(dodo.empty() && suyeon.empty()){
      cout << "dosu";
    }
    else if(dodo.empty()){
      cout << "su";
    }
    else if(suyeon.empty()){
      cout << "do";
    }
    else{
      if (dodo.size() > suyeon.size()) {
        cout << "do";
      } else if (dodo.size() < suyeon.size()) {
        cout << "su";
      } else {
        cout << "dosu";
      }
    }
    

    return 0;
}
