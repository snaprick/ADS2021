#include <bits/stdc++.h> 
  
using namespace std; 
 
bool Right(char c){ 
  return ('}' == c || ')' == c || ']' == c); 
} 
 
bool Left(char c){ 
  return ('{' == c || '(' == c || '[' == c);  
} 
  
bool Close(char lb, char rb){ 
  return ('(' == lb && ')' == rb) || ('[' == lb && ']' == rb) || ('{' == lb && '}' == rb); 
} 
 
int main(){ 
  string s; 
  cin >> s; 
  stack<char> st;
  for (int i = 0; i < s.size(); i ++){ 
    if (Left(s[i])){ 
      st.push(s[i]); 
    } 
    else if (!st.empty()){ 
      if (Close(st.top(), s[i])) 
        st.pop();
      else{
        cout << "no";
        return 0;
      }
        
    } 
    else{
        cout << "no";
        return 0;
    }
  } 
  if (st.empty()){ 
    cout << "yes" << endl; 
  } 
  else{ 
    cout << "no" << endl; 
  } 
   
  return 0; 
}