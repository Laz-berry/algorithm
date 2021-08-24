#include <iostream>
#include "solution.h"
using namespace std;


unsigned long long int Solution::pathCases(int m, int n) 
{
    int M = m+n-2;
    int N = m-1;
    long long pascal[500][500];
    int cnt, cntM, cntN;
    long long result;

    pascal[0][0] = 1; // 파스칼 꼭대기는 1

    for(cnt = 1; cnt <= N; ++cnt) {
        pascal[0][cnt] = 0;
    }

    for(cntM = 1; cntM <= M; ++cntM) {
        for(cntN=0; cntN <= N; ++cntN) {
            if(cntM == cntN) {  // 파스칼 오른쪽은 1
                pascal[cntM][cntN] = 1;
            }
            else if(cntN == 0) { // 파스칼 왼쪽도 1
                pascal[cntM][cntN] = 1;
            }
            else { //nCr = (n-1)C(r-1) + (n-1)Cr
                pascal[cntM][cntN] = pascal[cntM-1][cntN-1] + pascal[cntM-1][cntN];
            }
        }
    }
    result = pascal[M][N];
    return result;
}