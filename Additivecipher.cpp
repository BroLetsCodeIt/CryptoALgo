#include<iostream>
#include<vector>
using namespace std;
void solve(){
    cout << "What would you like to do : " << endl;
    cout << "1 . Plain text -> Cipher text " << endl;
    cout << "2 . Cipher Text -> Plain text " << endl;
    int n;
    cin >> n;
    if(n == 1){
      string s;
      cout << "Enter the Plain text : " << endl;
      cin >> s;
      int len = s.length();

      for(int i=0;i<len;i++){
        if(isupper(s[i])){
            continue;
        }
        else{
            s[i] = s[i] - 32;
        }
      }
      vector<char> ch;
      for(int i=0 ; i<len ; i++){
        ch.push_back( char(int(s[i]+3-65)%26 + 65));
      }
      cout << "The Cipher text : " << endl;
      for(int i=0 ; i<ch.size();i++){
         cout << ch[i] << " ";
      }
      cout << endl;
    }
    else if(n == 2){
         cout << "Enter the Cipher text :" << endl;
         string w;
         cin >> w;
         int lenn = w.length();

         for(int i=0;i<lenn ; i++){
            if(isupper(w[i])){
                continue;
            }
            else{
                w[i] = w[i] - 32;
            }
         }

         vector<char> chh;
         for(int i=0 ; i<lenn ; i++){
            chh.push_back( char(int(w[i]-3+65)%26 + 65));
         }
         for(int j = 0;j<chh.size() ; j++){
            cout << chh[j] << " ";
         }
         cout << endl;
    } 
    else{
        cout << "Invalid choice...Please Enter correct" << endl;
    }
}
int main(){
  solve();
}