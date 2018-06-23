/// @file
/// @version Time Limit Exceeded.
#include<iostream>
#include<vector>
using namespace std;
const int MAX_N=11;

void print(const vector<int>&xs){
  for(int i=0;i<xs.size();++i)cout<<xs[i]<<",";
  cout<<endl;
}
vector<bool>used(MAX_N);
vector<int>perm;
int n_cases,n_digits,n_series,smallest_difference;
vector<int>digits;
bool divide(int*left,int*right){
  const int size=perm.size();
  const int size_left=size/2;
  const int size_right=size-size_left;
  if(size_left!=1&&perm[0]==0)return false;
  if(size_right!=1&&perm[size_left]==0)return false;
  *left=0;
  for(int i=0;i<size_left;++i){
    *left*=10;
    *left+=perm[i];
  }
  *right=0;
  for(int i=size_left;i<size;++i){
    *right*=10;
    *right+=perm[i];
  }
  return true;
}
void doSeries(){
  int left,right;
  const bool is_success=divide(&left,&right);
  if(!is_success)return;
  const int difference=abs(left-right);
  smallest_difference=min(smallest_difference,difference);
  // printf("left,right,difference=%d,%d,%d\n",left,right,difference);
}
/// p. 39
void permutation1(int pos,int n){
  // printf("%d %d\n",pos,n);
  if(pos==n){
    ++n_series;
    // print(perm);
    doSeries();
    return;
  }
  for(int i=0;i<digits.size();++i){
    const int digit=digits[i];
    if(!used[digit]){
      perm[pos]=digit;
      used[digit]=true;
      permutation1(pos+1,n);
      used[digit]=false;
    }
  }
  return;
}
int main(){
  cin>>n_cases;
  char chars[80];
  cin.getline(chars,sizeof(chars));   // Consumes a newline.
  for(int i=0;i<n_cases;++i){
    digits.clear();
    cin.getline(chars,sizeof(chars));
    for(int i=0;true;i+=2){
      digits.push_back(chars[i]-'0');
      if(chars[i+1]=='\0')break;
    }
    n_digits=digits.size();
    perm=vector<int>(n_digits);
    n_series=0;
    smallest_difference=0x3f3f3f3f;
    permutation1(0,n_digits);
    // printf("n_series=%d\n",n_series);
    cout<<smallest_difference<<endl;
  }
}
