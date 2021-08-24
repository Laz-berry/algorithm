#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>
#include<string> 
#include <algorithm>
#include "solution.h"
using namespace std;

vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, vector<int> keypoint, int K) {

        vector<vector<double>> distance;
        vector<double> a(points.size());
        vector<vector<int>> result;

        for (int i = 0; i < points.size(); i++) {
            a[0] = sqrt((keypoint[0] - points[i][0]) * (keypoint[0] - points[i][0])
                + (keypoint[1] - points[i][1]) * (keypoint[1] - points[i][1]));
            a[1] = points[i][0];
            a[2] = points[i][1];
            distance.push_back(a);
        }
        sort(distance.begin(), distance.end());
              int cnt = 1;
              double first = distance[0][0];

              for (int i = 1; i < distance.size(); i++)
              {
                  if (first != distance[i][0]) {  
                      cnt++; first = distance[i][0]; 
                  }
                  if (cnt == K) { 
                      cnt = i; break;
                  }
              }

        double Kth = distance[cnt][0]; 
        vector <int> temp(2, (distance[cnt ][1], distance[cnt ][2]));
        result.push_back(temp);
        for (int i = cnt+1; i < distance.size(); i++) { 
            if (Kth == distance[i][0]) {
                vector <int> temp(2, (distance[i][1], distance[i][2]));
                result.push_back(temp);
            }
            else break;
        } 
        return result;
} 
