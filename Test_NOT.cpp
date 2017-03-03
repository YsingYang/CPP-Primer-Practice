#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> num(n,1);
        for(int i=2;i<=n;++i){
            for(int j=0;j<n;++j){
                if(((j+1)%i)==0){
                   num[j] =(!num[j]);
                }
            }
        }
        int count=0;
        for(bool i:num)
            if(i)
                ++count;

        return count;
    }
};

int main(){
    Solution *sol = new Solution();
    cout<<sol->bulbSwitch(25);
    return 1;
}
