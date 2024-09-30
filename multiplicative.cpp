#include<bits/stdc++.h>
using namespace std;
int gcdExt(int a,int b,int& x,int& y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1,y1;
    int gcd=gcdExt(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return gcd;
}
int modInv(int a,int m){
    int x,y;
    int gcd=gcdExt(a,m,x,y);
    return (gcd==1)?(x%m+m)%m:-1;
}
string enc(const string& text,int k){
string result="";
for(char ch:text){
    if(isalpha(ch)){
        char base=islower(ch)?'a':'A';
        result+=((ch-base)*k)%26+base;
    }else if(ch==' '){
        result+=' ';
    }
}
return result;
}
string dec(const string& text,int k){
string result="";
int mInverse=modInv(k,26);
for(char ch:text){
    if(isalpha(ch)){
        char base=islower(ch)?'a':'A';
        result+=((ch-base)*mInverse)%26+base;
    }else if(ch==' '){
        result+='';
    }
}
return result;
}
int main()
{
    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    int k;
    cout << "Enter the key(must be coprime with 26): ";
    cin >> k;

    string cipherText = enc(text, k);
    cout << "The cipherText is: " << cipherText << "\n";

    string decipherText = dec(cipherText, k);
    cout << "The decipherText is: " << decipherText << "\n";

    return 0;
}

