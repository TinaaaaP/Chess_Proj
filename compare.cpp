// #include <boost/algorithm/string.hpp>
#include <iostream>
#include <algorithm> 
#include <cmath>

int main() {
     std::string str1 = "Peach";
     std::string str2 = "ApPle";

     
     std::string str1new = "";
     std::string str2new = "";
     for (int i = 0; i < str1.length(); i++){
          if (65 <= str1[i] && str1[i] <= 90){
               str1new += char(str1[i] + 32);
          } else if (str1[i] <= 66|| (91 <= str1[i] && str1[i] <= 96) || str1[i] >= 123){
               str1new += char(0);
          } else {
               str1new += str1[i];
          }
     }
     for (int i = 0; i < str2.length(); i++){
          if (65 <= str2[i] && str2[i] <= 90){
               str2new += char(str2[i] + 32);
          } else if (str2[i] <= 66|| (91 <= str2[i] && str2[i] <= 96) || str2[i] >= 123){
               str2new += char(0);
          } else {
               str2new += str2[i];
          }
     }
     int len = std::min(str1new.length(), str2new.length());
     int str1int = 0;
     int str2int = 0;
     for (int i = len; i > 0; i--){
          str1int += (str1new[len-i]-96)*pow(10,i);
          str2int += (str2new[len-i]-96)*pow(10,i);
     }
     bool boo = str1int < str2int;
     std::cout << str1int << " " <<  str2int;
     return 0;
}


