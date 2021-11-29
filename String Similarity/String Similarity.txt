#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stringSimilarity' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int checkSuffix(string str, string s){
  int count = 0;
  cout << str;
  cout << "  "+ s +" -> ";
  
  for (int i = 0 ; i < str.length(); i++ ){
    if (i < str.length() && i < s.length()){
      if (str[i] == s[i]){
        count ++;
      }else {
        return count;
      }
    }else {
      return  count;
    }
  }
  cout << count;
  cout << "\n"; 
  return count;
}

int stringSimilarity(string s) {
  int count = 0;
  if (s.length() > 100000){
    return 0;
  }
  for (int i = 0  ; i < s.length()  ; i++){
    string str = s.substr(i,s.length()-i);
    count += checkSuffix(str,s);
  }
  
  return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = stringSimilarity(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
