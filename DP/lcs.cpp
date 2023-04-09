#include <bits/stdc++.h> 
using namespace std;

int getLengthOfLCS(string & str1, string & str2) {
  int n = str1.size();
  int m = str2.size();
  int arr[n+1][m+1];
  
  for(int i = 0;i <= n;i++)
    arr[i][0] = 0;
  
  for(int j = 0;j <= m;j++)
    arr[0][j] = 0;
  
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(str1[i-1] == str2[j-1])
        arr[i][j] = arr[i-1][j-1] + 1;
      else if(arr[i-1][j] >= arr[i][j-1])
        arr[i][j] = arr[i-1][j];
      else
        arr[i][j] = arr[i][j-1];
    }
  }
  return arr[n][m];
}