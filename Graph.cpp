#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

const float beta = 0.1934; // S->I 감염율(20. 2. 10에 발표한 중국논문발표 도입) 
const float gamma = 1/14;  // I->R 회복율(평균 회복기간 14일의 역수)
const float Rz = 2.76; // 초기 전파자의 감염된 사람 수
/* 취약자 변화율 = -(감염율*취약자 수*감염자 수)
	감염자 변화율 = (감염율*취약자*감염자) - 회복자
	회복자 변화율 = 회복율*감염자
	*/
 
// A function to generate random graph.
void GenerateRandGraphs(int NOE, int NOV)
{
	int i, j, count;
	float edge[NOE][3]; 
	i = 0;
	// Build a connection between two random vertex.
	while(i < NOE)
	{
		edge[i][0] = rand()%NOV+1;
		edge[i][1] = rand()%NOV+1;
		edge[i][2] = rand()%12; // 2주일 이내에 근무 비중치
 
		if(edge[i][0] == edge[i][1])
			continue;
		else
		{
			for(j = 0; j < i; j++)
			{
				if((edge[i][0] == edge[j][0] && edge[i][1] == edge[j][1]) || (edge[i][0] == edge[j][1] && edge[i][1] == edge[j][0]))
					i--;
			}
		}
		i++;
	}
 
	// Print the random graph.
	cout<<"\nThe generated random random graph is: ";
	for(i = 0; i < NOV; i++)
	{
		count = 0;
		int cnt=0;
		cout<<"\n\t"<<i+1<<"-> { ";
		for(j = 0; j < NOE; j++)
		{
			if(edge[j][0] == i+1)
			{
				int a = rand()%5;
				cout<<edge[j][1]<<" ";
				count++;
				cnt++;
			}
			else if(edge[j][1] == i+1)
			{
				//edge[j][0] = edge[j][0] * beta;
				cout<<edge[j][0]<<" ";
				count++;
				cnt++;
			}
			else if(j == NOE-1 && count == 0)
				cout<<"Isolated Vertex!";
		}
		cout<<" } " << "인접 노드 갯수: " << cnt;
	}

}
 
int main()
{
	int n, i, e, v;
    srand(GetTickCount());
 
	cout<<"Random graph generation: ";
 
	// 정점의 수를 입력하고 간선은 랜덤
	v = 48;
	cout<<"\nThe graph has "<<v<<" vertexes.";
	e = rand()%((v*(v-1))/2);
	cout<<"\nThe graph has "<<e<<" edges.";
 
	// 비방향성 그래프(가중치 포함)
	GenerateRandGraphs(e, v);

	
}