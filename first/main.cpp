#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>


int main() {
    char ch;
    long long sum = 0;
    std::string str;
    std::string strExp;

    while ( std::cin.get(ch)){
        if ( (ch >= '0' && ch <= '9') || (ch == '-' && strExp.empty())){
            strExp += ch;
        }
        else {
            if ((strExp >= "0" && strExp <= "9") || strExp.size() > 1 ){
                sum += std::atoi(strExp.c_str());
            }
            if ( ch == EOF ){
                break;
            }
            strExp.clear();
        }
    }
    std::cout << sum ;
    return 0;
}
