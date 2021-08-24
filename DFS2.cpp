#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAZE_XSIZE = 5; // 미로의 X좌표 크기
const int MAZE_YSIZE = 5; // 미로의 y좌표 크기
int cnt = 0; // DFS미로 탐색 횟수

enum direction { // 비트 연산으로 상하좌우 구분 (예: B = 000001)
    NONE = 0, 
    B = 1, T = 2, R = 4, L = 8,
    BLOCK = 16, NOW_DIR = 32 // NONE은 뚫지 않은 길, BLOCK은 막힌 길, NOW_DIR은 현재위치
};

void Get_Maze_DirChar(int left, int me, int top, int row, char* wall) {
    if(row == 0) {
        wall[0] = '+'; 
        if((me >> 1) & 1 || top & 1){
            wall[1] = ' '; 
            wall[2] = ' '; 
        }
        else{
            wall[1] = '-'; 
            wall[2] = '-'; 
        }
    }

    if(row == 1) {
        if((me >> 3) & 1 || (left >> 2) & 1) {
            wall[0] = ' ';
        }
        else {
            wall[0] = '|';
        }

        switch(me) {
            case NOW_DIR: // 현재 위치
                wall[1] = '#';
                wall[2] = ' ';
                break;
            case NONE: // 아직 이동하지 않은 길
                wall[1] = '.';
                wall[2] = '.';
                break;          
            default:
                wall[1] = ' ';
                wall[2] = ' ';
                    break;
        }
    }
}

int Rand_Maze_Dir() { // 랜덤으로 상하좌우 이동할(생성할) 길 정하기
    int dir = rand() % 4;

    switch(dir){
        case 0:
            return L;
        case 1:
            return R;
        case 2:
            return B;
        case 3:
            return T;
    }
}

void Maze_Print(int a[MAZE_XSIZE][MAZE_YSIZE], int x, int y) {
    for(int j = 0; j < MAZE_YSIZE; j++) {
        for(int k = 0; k < 2; k++) { // 2칸마다 한 번씩 + 아니면 |(벽)을 세움
            for(int i = 0; i < MAZE_XSIZE; i++) {                
                int left, me, top;

                left = i > 0 ? a[i - 1][j] : (j == 0 ? R : BLOCK);
                me = i == x && j == y ? NOW_DIR : a[i][j];               
                top = j > 0 ? a[i][j - 1] : BLOCK;              

                char wall[3] = { ' ', ' ', ' ' }; 
                Get_Maze_DirChar(left, me, top, k , wall);
                cout << wall[0] << wall[1] << wall[2];
            }
            if(k == 0) 
                cout << "+\n";
            else 
                cout << "|\n";
        };
    }
    for(int i = 0; i < MAZE_XSIZE; i++) { // 위, 아래 줄에 벽을 생성
        cout << "+--";
    }
    cout << "+\n"; // 맨 오른쪽 코너 벽 생성
}

int goTo(int a[MAZE_XSIZE][MAZE_YSIZE], int x, int y){ // #(자신)이 이동하는(길을 생성하는) 함수
    Maze_Print(a, x, y);
    int b = 0;
    while(1) {
        if((x == 0 || a[x - 1][y] != NONE) &&           // 왼쪽 이동불가하고
            (x == MAZE_XSIZE - 1 || a[x + 1][y] != NONE) &&  // 오른쪽 이동불가하며
            (y == MAZE_YSIZE - 1 || a[x][y + 1] != NONE)) {  // 아래쪽 이동불가할 때
                return 0; // 프로그램 종료
        }
        b = Rand_Maze_Dir();
        switch(b){
            case L: // 왼쪽일 때
                if(x > 0 && a[x - 1][y] == NONE) { // x좌표가 미로 x왼쪽 외벽을 통과하지 않고 왼쪽이 아직 뚫지 않은 벽일 때
                    a[x][y] += L;
                    x--; 
                    goTo(a, x, y); // 왼쪽으로 이동
                    a[x][y] += R;
                    cnt++;
                }
                break;
            case R: // 오른쪽 일 때
                if(x < MAZE_XSIZE - 1 && a[x + 1][y] == NONE) { // x좌표가 미로 x오른쪽 외벽을 통과하지 않고 오른쪽이 아직 뚫지 않은 벽일 때
                    a[x][y] += R;
                    x++;
                    goTo(a, x, y); // 오른쪽 이동
                    a[x][y] += L;
                    cnt++;
                }
                break;
            case T: // 위쪽 일때
                if(y > 0 && a[x][y - 1] == NONE) { // y좌표가 미로 y윗벽을 통과하지 않고 위쪽이 아직 뚫지 않은 벽일 때
                    a[x][y] += T;
                    y--;
                    goTo(a, x, y); // 위쪽 이동
                    a[x][y] += B;
                    cnt++;
                }
                break;
            case B: // 아래쪽 일때
                if(y < MAZE_YSIZE - 1 && a[x][y + 1] == NONE) { // y좌표가 미로 y아래벽을 통과하지 않고 아래쪽이 아직 뚫지 않은 벽일 때
                    a[x][y] += B;
                    y++;
                    goTo(a, x, y); // 아래쪽 이동
                    a[x][y] += T;
                    cnt++;
                }
                break;
        }
    }
}

int main() {
    clock_t start, end;
    double result;
    start = clock();
    srand(time(NULL));
    int a[MAZE_XSIZE][MAZE_YSIZE];
    for(int i = 0; i < MAZE_XSIZE; i++) {
        for(int j = 0; j < MAZE_YSIZE; j++) {
            a[i][j] = NONE;
        }
    }
    a[0][0] = L;
    goTo(a, 0, 0);
    Maze_Print(a, MAZE_XSIZE - 1, MAZE_YSIZE - 1);
    end = clock();
    result = (double)(end - start);
    cout << "미로 X크기 : " << MAZE_XSIZE << endl;
    cout << "미로 y크기 : " << MAZE_YSIZE << endl;
    cout << "탐색 횟수 : " << cnt << endl;
    cout << "탐색 시간(ms) : " << result << "ms" << endl;
}