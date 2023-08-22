 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int check(char n, vector<char> vall)
{
    for (int i = 0; i < vall.size(); i++)
    {
        if (n == vall[i])
        {
            // cout << i << endl;
            return i;
            break;
        }
        else
        {
            continue;
        }
    }
}
void solve(){
	cout << "What would you like to do : " << endl;
    cout << "1 . Plain text -> Cipher text " << endl;
    cout << "2 . Cipher Text -> Plain text " << endl;
    int n;
    cin >> n;
    vector<char> val;
    for (int i = 0; i < 26; i++)
    {
        char cha = char(i + 65);
        val.push_back(cha);
    }
   
     if (n == 1)
    {
        cout << "Enter the Plain text : " << endl;
        string s;
        cin >> s;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (isupper(s[i]))
            {
                continue;
            }
            else
            {
                s[i] = s[i] - 32;
            }
        }
        cout << "Enter the First Key :" << endl;
        int key1;
        cin >> key1;
        while (key1 < 0)
        {
            key1 += 26;
        }
        cout << "Enter the Second Key :" << endl;
        int key2;
        cin >> key2;
        while(key2 < 0){
        	key2+=26;
		}
		cout << "The Cipher text : " << endl;
        // c= (p * k ) % 26;
        vector<char> ans;
        for (int i = 0; i < s.length(); i++)
        {
            char docheck = s[i]; 

            int got = check(docheck, val);
            char cipher = (val[(got * key1 + key2) % 26]);
            ans.push_back(cipher);
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }else if(n == 2){
        cout << "Enter the Cipher text : " << endl;
        string cipher;
        cin >> cipher;
        int len = cipher.length();
        for (int i = 0; i < len; i++)
        {
            if (isupper(cipher[i]))
            {
                continue;
            }
            else
            {
                cipher[i] = cipher[i] - 32;
            }
        }
        cout << "Enter the first key :" << endl;
        int key1;
        cin >> key1;
        while (key1 < 0)
        {
            key1 += 26;
        }
        cout << "Enter the Second Key :" <<endl;
        int key2 ; 
        cin >> key2;
        
        while(key2 < 0){
        	key2 += 26;
		}
		
		//finding the k inverse
		
		cout << "The Plain text : " << endl;
        int r1 = 26;
        int r2 = key1;
        int t1 = 0;
        int t2 = 1;
        int q;
        int t;
        int r;
        while (r1 * r2 != 0)
        {
            q = r1 / r2;
            r = r1 % r2;
            t = t1 - (q * t2);
            r1 = r2;
            r2 = r;
            t1 = t2;
            t2 = t;
        }
        while(t1 < 0)
        {
            t1 += 26;
        }

        vector<char> ans;
        for (int i = 0; i < cipher.length(); i++)
        {
            char docheck = cipher[i];
            int got = check(docheck, val);
            int sub ; 
			if((got - key2)>0){
               sub = got - key2;
			}
			else{
			   sub = got - key2;
			   while(sub < 0 ){
			   	 sub +=26;
			   }
			}
//			cout << sub << endl;
            char cipher = (val[(sub * t1) % 26]);
            ans.push_back(cipher);
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
	}
	else{
		cout << "Enter the Valid Input.." << endl;
	}
}
int main(){
	solve();
}
