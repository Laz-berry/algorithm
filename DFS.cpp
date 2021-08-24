#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

const int MAZE_SIZE = 10;
int map[MAZE_SIZE][MAZE_SIZE];

struct Location2D {
    int row;
    int col;
    Location2D(int r=0, int c=0) {
        row = r;
        col = c;
    }
    bool isNeighbor(Location2D &p) {
        return((row==p.row && col==p.col - 1) ||
        (row==p.row && col==p.col + 1) ||
        (row==p.row - 1 && col==p.col) ||
        (row==p.row + 1 && col==p.col) 
        );
    }
    bool operator==(Location2D &p) { return row==p.row && col==p.col; }
};

bool isValidLoc(int r, int c) {
    if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) { return false; }
    else return map[r][c] == 1 || map[r][c] == 9; // 길(1)이거나 도착(9)이거나 
}

void mz_value() {
    for(int i = 0; i < MAZE_SIZE; i++) {
      for(int j = 0; j < MAZE_SIZE; j++) {
          map[i][j] = 3;
        }
    }
    srand((unsigned int)time(NULL));
    for(int i = 1; i < MAZE_SIZE-1; i++) {
      for(int j = 1; j < MAZE_SIZE-1; j++) {
          map[i][j] = rand() % 2;
       }
    }
    map[0][1] = 5; // 출발지점
    map[MAZE_SIZE-1][MAZE_SIZE-2] = 9; // 도착지점
}

void mz_exp() {
    cout << "\n------------------------------------ \n";
    cout << "■ = 막힌 벽 \n";
    cout << "★ = 출, 도착 지점 \n";
    cout << "☆ = 지나온 길 \n";
    cout << "□ = 이동 가능 한 길 \n";
}

void mz_show() { 
    map[0][1] = 5;
    for(int i = 0; i < MAZE_SIZE; i++) {
      for(int j = 0; j < MAZE_SIZE; j++) {
          if(map[i][j] == 3) // 외부 벽
          cout << "■ ";
          else if(map[i][j] == 0) // 내부 막힌 길
          cout << "■ ";
          else if(map[i][j] == 5) // 출발 지점
          cout << "★ ";
          else if(map[i][j] == 7) 
          cout << "☆ ";
          else if(map[i][j] == 9) // 도착 지점
          cout << "★ ";
          else if(map[i][j] == 1) // 이동 가능 길
          cout << "□ ";
       }
       cout << endl;
    }
}

int main() {
    mz_value();
    mz_show();

    stack<Location2D> locstack;
    Location2D stackentry(0, 1);
    locstack.push(stackentry);
    int a = 0; // DFS 탐색 횟수
    
    while(locstack.empty() == false) {
        Location2D here = locstack.top();
        locstack.pop();
        int r = here.row;
        int c = here.col;
        cout << "(" << r << "," << c << ") ";

        if(map[r][c] == 9) {
            cout << "탈출 \n";
            cout << endl;
            cout << "D F S 탐 색 \n";
            mz_show();
            mz_exp();
            cout << a << endl;
        }
        else {
            map[r][c] = 7;
            if(isValidLoc(r-1, c)) locstack.push(Location2D(r-1, c));
            if(isValidLoc(r+1, c)) locstack.push(Location2D(r+1, c));
            if(isValidLoc(r, c-1)) locstack.push(Location2D(r, c-1));
            if(isValidLoc(r, c+1)) locstack.push(Location2D(r, c+1));
        }
        a++;
    }
    cout << "탈출실패 \n";
    cout << endl;
    cout << "D F S 탐 색 \n";
    mz_show();
    mz_exp();
    cout << a << endl;
    
    queue<Location2D> locqueue;
    Location2D queueentry(0, 1);
    locqueue.push(queueentry);
    int aa = 0; // BFS탐색횟수

    while(locqueue.empty() == false) {
        Location2D here = locqueue.front();
        locqueue.pop();
        int rr = here.row;
        int cc = here.col;
        cout << "(" << rr << "," << cc << ") ";
        if(map[rr][cc] == 9) {
            cout << "탈출 ";
            cout << endl;
            cout << "B F S 탐 색 \n";
            mz_show();
            mz_exp();
            cout << aa;
        }
        else {
            map[rr][cc] = 7;
            if(isValidLoc(rr-1, cc) == true) locqueue.push(Location2D(rr-1, cc)); 
            if(isValidLoc(rr+1, cc) == true) locqueue.push(Location2D(rr+1, cc));
            if(isValidLoc(rr, cc-1) == true) locqueue.push(Location2D(rr, cc-1));
            if(isValidLoc(rr, cc+1) == true) locqueue.push(Location2D(rr, cc+1));
        }
        aa++;
    }
    cout << "탈출실패 \n";
    cout << endl;
    cout << "B F S 탐 색 \n";
    mz_show();
    mz_exp();
    cout << aa;
}