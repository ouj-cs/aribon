/// @file
/// @version Time Limit Exceeded.
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int N,sum;
vector<int>xs;
vector<vector<int> >xss;
void print(const vector<int>&xs){
  for(int i=0;i<xs.size();++i)cout<<xs[i]<<",";
  cout<<endl;
}
int main(){
  cin>>N>>sum;
  for(int i=1;i<=N;++i){
    xs.push_back(i);
  }
  do{
    vector<int>tmp=xs;
    for(int i=0;i<N-1;++i){
      for(int j=0;j<N-i-1;++j){
        tmp[j]+=tmp[j+1];
      }
    }
    const int total=tmp[0];
    if(total==sum){
      xss.push_back(xs);
      // print(xs);
      // printf("total=%d\n",total);
    }
  }while(next_permutation(xs.begin(),xs.end()));
  sort(xss.begin(),xss.end());
  vector<int>best=xss.front();
  for(int i=0;i<best.size();++i){
    cout<<best[i];
    if(i!=best.size()-1)cout<<" ";
    else cout<<endl;
  }
}
