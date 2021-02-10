//5-1
/*
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10000;

int main(){
    int n, q, x, a[], kase=0;
    while(scanf("%d%d", &n, &q)==2 && n){
        printf("CASE# %d:\n", ++kase);
        for(int i=0; i<n; i++) 
            scanf("%d", &a[i]);
        sort(a, a+n);
        while(q--){
            scanf("%d", &x);
            int p=lower_bound(a, a+n, x)-a;//在已排序数组a中寻找x
            if(a[p]==x)
                printf("%d found at %d\n", x, p+1);
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}
*/

//5-3
#include <cstdio>
#include <string>
#include <set>
#include <iostream>
using namespace std;

set<string> dict; //string集合

int main(){
    string s, buf;
    while(cin>>s){
        for(int i=0; i<s.length(); i++){
            if(isalpha(s[i]))
                s[i]=tolower(s[i]);
            else
                s[i]=' ';
        }
        //输入时把所有非字母的字符变成空格，然后利用stringstream得到各个单词
        stringstream ss(s);
        while(ss >> buf)
            dict.insert(buf);
    }
    for(set<string>::iterator it=dict.begin(); it!=dict.end(); ++it){
        cout<<*it<<"\n";
    }
    return 0;
}

//5-4
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, int> cnt;
vector<string> words;

string repr(const string& s){

}

int main(){
    int n=0;
    string s;
    while(cin>>s){
        if(s[0]=='#')
            break;
        words.push_back();
        string r=repr(s);
        if(!cnt.count(r))
            cnt[r]=0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i=0; i<words.size(); i++){
        if(cnt[repr(words[i])]==1)
            ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}