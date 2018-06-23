/// @file
/// @version Accepted.
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
  vector<int>scale(N);
  scale[0]=1;
  for(int i=0;i<N-1;++i){
    vector<int>tmp=scale;
    for(int j=0;j<i+1;++j){
      scale[j+1]+=tmp[j];
    }
  }
  for(int i=1;i<=N;++i){
    xs.push_back(i);
  }
  do{
    int total=0;
    for(int i=0;i<N;++i){
      total+=scale[i]*xs[i];
    }
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
