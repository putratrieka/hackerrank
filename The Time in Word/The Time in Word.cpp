#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */
map<int, string> getDictionary(){
  map<int, string> dict;
  dict[1] = "one minute";
  dict[2] = "two minutes";
  dict[3] = "three minutes";
  dict[4] = "four minutes";
  dict[5] = "five minutes";
  dict[6] = "six minutes";
  dict[7] = "seven minutes";
  dict[8] = "eight minutes";
  dict[9] = "nine minutes";
  dict[10] = "ten minutes";
  dict[11] = "eleven minutes";
  dict[12] = "twelve minutes";
  dict[13] = "thirteen minutes";
  dict[14] = "fourteen minutes";
  dict[15] = "quarter";
  dict[16] = "sixteen minutes";
  dict[17] = "seventeen minutes";
  dict[18] = "eightteen minutes";
  dict[19] = "nineteen minutes";
  dict[20] = "twenty minutes";
  dict[21] = "twenty one minutes";
  dict[22] = "twenty two minutes";
  dict[23] = "twenty three minutes";
  dict[24] = "twenty four minutes";
  dict[25] = "twenty five minutes";
  dict[26] = "twenty six minutes";
  dict[27] = "twenty seven minutes";
  dict[28] = "twenty eight minutes";
  dict[29] = "twenty nine minutes";
  dict[30] = "half";
  dict[31] = "thirty one minutes";
  dict[32] = "thirt two minutes";
  dict[33] = "thirty three minutes";
  dict[34] = "thirty four minutes";
  dict[35] = "thirty five minutes";
  dict[36] = "thirty six minutes";
  dict[37] = "thirty seven minutes";
  dict[38] = "thirty eight minutes";
  dict[39] = "thirty nine minutes";
  dict[40] = "fouty minutes";
  dict[41] = "fourty one minutes";
  dict[42] = "fourty two minutes";
  dict[43] = "fourty three minutes";
  dict[44] = "fourty four minutes";
  dict[45] = "fourty five minutes";
  dict[46] = "fourty six minutes";
  dict[47] = "fourty seven minutes";
  dict[48] = "fourty eight minutes";
  dict[49] = "fourty nine minutes";
  dict[50] = "fifty minutes";
  dict[51] = "fifty one minutes";
  dict[52] = "fifty two minutes";
  dict[53] = "fifty three minutes";
  dict[54] = "fifty four minutes";
  dict[55] = "fifty five minutes";
  dict[56] = "fifty six minutes";
  dict[57] = "fifty seven minutes";
  dict[58] = "fisty eight minutes";
  dict[59] = "fifty nine minutes";
  dict[0] = "o' clock"; 
   
  
  return dict;
}

string timeInWords(int h, int m) {
 map<int, string> dict = getDictionary();
 if (m <= 30){
   string minutes = dict[m];
   string hour = dict[h];
   if (h == 1){
     hour = hour.replace(hour.find(" minute"),7,"");
   }else{
     hour.replace(hour.find(" minutes"),8,"");
   }
   
   if (m == 0){
     return hour +" " + dict[0];
   }
   return  minutes + " past " + hour; 
 }else {
   int reminder = 60 - m;
   string minutes = dict[reminder];
   string hour = dict[h+1];
   if (h == 1){
     hour = hour.replace(hour.find(" minute"),7,"");
   }else{
     hour.replace(hour.find(" minutes"),8,"");
   }
   
   if (m == 0){
     return hour +" " + dict[0];
   }
   
   return  minutes + " to " + hour; 
 }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
