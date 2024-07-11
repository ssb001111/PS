#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 
 
int main() {
  
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;

  long long real[n-1];

  long long m = 0;

  for (int i = 0; i < n-1; i++){
      long long a;
      cin >> a;
      real[i] = a;
      m += a;
  }

  long long nodes[n];
 
  long long addition = 0;

  for (int i = 0; i < n-1; i++){
      cin >> nodes[i];
      addition += nodes[i];
  }

  long long result = 0;
  long long curr_min = nodes[0];

  if (addition != n){
      for (int i = 0; i < n-1; i++){
          long long t = curr_min * real[i];
          result += t;
          if (curr_min > nodes[i+1]){
              curr_min = nodes[i+1];
          }
      }
  }
  else{
      result = m;
  }

  cout << result;
        
  return 0;
}
