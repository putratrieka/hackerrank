#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

bool anyObsctacles(int n,int i,int j, int k, vector<vector<int>> obstacles){
  for (int l = 0 ; l < k ; l++){
    int ii =  abs(n - obstacles[l][0]);
    int jj = obstacles[l][1]-1;
    if ((ii == i) && (jj == j)){
      return true;
    }
    
  }
  return false;
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
  vector<string> obs ;
  int count = 0 ;
  r_q = abs(n - r_q);
  c_q = c_q -1;
  // find right
  if (c_q +1 <= n-1){
    for (int i = c_q + 1 ; i < n ; i ++){
      if (!anyObsctacles(n,r_q, i, k,obstacles)){
        count++;
      }else{
        break;
      }
    } 
  }
  // find left
  if (c_q -1 >= 0){
    for (int i = c_q -1  ; i >= 0 ; i --){
      // cout << to_string(r_q) + "," + to_string(i);
      if (!anyObsctacles(n,r_q, i, k,obstacles)){
        count++;
      }else {
        break;
      }
    } 
  }
  
  // find top
  if (r_q -1 >= 0){
    for (int i = (r_q -1)  ; i >= 0 ; i --){
      // cout << to_string(i) + "," + to_string(c_q);
      if (!anyObsctacles(n,i, c_q, k,obstacles)){
        count++;
      }else{
        break;
      }
    } 
  }
    
    // find bottom
  if ((r_q +1) <= n-1 ){
    for (int i = (r_q +1)  ; i < n ; i ++){
      // cout << to_string(i) + "," + to_string(c_q);
      if (!anyObsctacles(n,i, c_q, k,obstacles)){
        count++;
      }else{
        break;
      }
    }
  }
  
  // find buttom right diagonal
  if (((r_q +1) <= n-1 ) && (c_q +1 <= n-1)){
    int max = 0;
    for (int i = 1 ; i < n ; i++){
      if ((r_q + i <= n-1) && (c_q +i <= n-1)){
        if (!anyObsctacles(n,r_q + i, c_q +i, k,obstacles)){
          count++;
        }else{
          break;
        }
      }
    }
  }
  
  // find buttom left diagonal
  if (((r_q +1) <= n-1 ) && (c_q -1 >= 0)){
    int max = 0;
    for (int i = 1 ; i < n ; i++){
      if ((r_q + i <= n-1) && (c_q - i >= 0)){
        if (!anyObsctacles(n,r_q + i, c_q - i, k,obstacles)){
          count++;
        }else{
          break;
        }
      }
    }
  }
  
  // find top right diagonal
  if ((r_q -1 >= 0) && (c_q +1 <= n-1)){
    int max = 0;
    for (int i = 1 ; i < n ; i++){
      if ((r_q -i >= 0) && (c_q +i <= n-1)){
        if (!anyObsctacles(n,r_q - i, c_q +i, k,obstacles)){
          count++;
        }else{
          break;
        }
      }
    }
  }
  
  // find top left diagonal
  if ((r_q -1 >= 0) && (c_q -1 >= 0)){
    int max = 0;
    for (int i = 1 ; i < n ; i++){
      if ((r_q -i >= 0) && (c_q -i >= 0)){
        if (!anyObsctacles(n,r_q - i, c_q -i, k,obstacles)){
          count++;
        }else{
          break;
        }
      }
    }
  }
  
  return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
