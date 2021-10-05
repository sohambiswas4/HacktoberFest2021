//frequency of all strings
#include <iostream>
#include<string>
using namespace std;


int main()
{   
    string s;
    //cout<<"Hello World";
    cin >> s;
    int b[26]={0};
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        b[index]++;
    }
    for(int i=0;i<26;i++){
        cout<<char(i+'a')<<"------->"<< b[i]<<endl;
    }


    return 0;
}