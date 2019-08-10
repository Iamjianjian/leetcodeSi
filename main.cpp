#include<bits/stdc++.h>
using namespace std;
int ans;
int find(string s){
    char ss[s.size()*2+1];
	int i=0,j=1,k=0,n=s.size();
    for(int a=0;a<n*2;a++){
        ss[a]=s[a%n];
    }
    ss[n*2]='\0';
    while(true){
        if(k==n||i==n||j==n){
            break;
        }
        if(s[i+k]!=s[j+k]){
            if(s[i+k]>s[j+k]){
                i=i+k+1;
                if(i==j){
                    i++;
                }
            }else{
                j=j+k+1;
                if(i==j){
                    j++;
                }
            }
            k=0;
        }else{
            k++;
        }
    }
	if(i>j){
		ans=j;
	}else{
		ans=i;
	}
	return ans;
}
int main(){
    string s="bacacabc";
    char ss[10];
    cout <<find(s);
    return 0;
}