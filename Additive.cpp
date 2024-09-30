#include<bits/stdc++.h>
using namespace std;
string enc(const string& text,int k){
string result="";
for(char ch:text){
    if(isalpha(ch)){
        char base=islower(ch)?'a':'A';
        result+=((ch-base+k)%26+base);
    }else if(ch==' '){
        result+=' ';
    }
}
return result;
}
string dec(const string& text,int k){
string result="";
for(char ch:text){
    if(isalpha(ch)){
        char base=islower(ch)?'a':'A';
        result+=((ch-base-k+26)%26+base);
    }else if(ch==' '){
        result+=' ';
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
    cout << "Enter the key: ";
    cin >> k;

    string cipherText = enc(text, k);
    cout << "The cipherText is: " << cipherText << "\n";

    string decipherText = dec(cipherText, k);
    cout << "The decipherText is: " << decipherText << "\n";

    return 0;
}
