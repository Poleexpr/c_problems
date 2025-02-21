#include <iostream>
using namespace std;

unsigned strlentest(const char *str)
{
    int i = 0;
    int count = 0;
    while(str[i] != '\0'){
        count ++;
        i++;
    }
    return count;
}

int strstrtest(const char *text, const char *pattern)
{
    unsigned textLen = strlentest(text);
    unsigned patternLen = strlentest(pattern);

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    if(patternLen == 0){
      return 0;
    }

    if(textLen == 1 && patternLen == 1 && text[i] == pattern[j]){
      return 0;
    }

    while(i < textLen && j < patternLen){
      if(text[i] == pattern[j]){
        m = i;
        ++k;
        ++i;
        ++j;
      } else {
        i = (i + 1) - j;
        j = 0;
        k = 0;
      }
    }

    if(k == patternLen){
      if(m == 0){
        return m;
      } else {
        return m - (patternLen - 1);
      }  
    } else {
      return -1;
    }
}

int main(){
  cout << strstrtest("ab", "a") << endl;
  return 0;
}