#include <iostream>
#include <cctype>

int main() {

    int i = -1; // count of element
    int size = 0;
    std::string  *arrStack = nullptr;
    std::string str;
    int counter = 0;
    bool set = 0;

    while ( std::getline(std::cin , str)) {
        int a = 0;
        std::string strTest;
        std::string strExp;
        bool b;
        int counterPr = 0;
        int position = 0;

        for (unsigned int h = 0; h < str.size(); h++) {
            if (str[h] == ' ') {
                counterPr++;
            }
            if ( counterPr >10) {
                break;
            }
        }

        for (unsigned int ii = 0; ii < str.size(); ii++) {

            if (str[ii] == ' ') {
                position = ii;
                break;
            }
            strTest += str[ii];
        }

        if ( strTest == "set_size" || strTest == "pop" || strTest == "push" || strTest == "print" || strTest == "" ){
            b = 1;
        }
        else {
            std::cout << "error" << std::endl;
        }


        for (unsigned int j = position + 1; j < str.size(); j++) {

            if (str[j] == ' ') {
                break;
            }
            if (str[j] == '\0') {
                break;
            }
            strExp += str[j];
        }

        a = std::atoi(strExp.c_str());



        if (strTest == "set_size" && counterPr == 1  && a!= 0) {
            counter++;
        }// else {
          //  if (strTest == "set_size") {
          //      std::cout << "error" << std::endl;
        //    }
       // }

        if (strTest == "set_size" && counter == 1 && a != 0) {
        //    if ( counterPr > 1 || a == 0 ) {
       //         std::cout << "error" << std::endl;
     //       } else {
                size = a;
                arrStack = new std::string[size];
                set = 1;
          //  }
        }
        else {
            if( strTest == "set_size") {
                std::cout << "error" << std::endl;
            }
        }


        if (strTest == "pop") {
            if (  counterPr == 0 && set == 1) {
                    if (i == -1) {
                        std::cout << "underflow" << std::endl;
                    } else {
                        std::cout << arrStack[i] << std::endl;
                        i--;
                    }
            } else {
                std::cout<<"error"<<std::endl;
            }
        }

        if (strTest == "print") {
            if( counterPr == 0 && set == 1) {
                if (i == -1) {
                    std::cout << "empty" << std::endl;
                } else {
                    if (i == size - 1) {
                        for (unsigned int j = 0; j < size ; j++) {
                           // std::cout << arrStack[j] << ' ';
                            std::cout << arrStack[j];
                            if(j < size - 1 ){
                                std::cout << ' ';
                            }
                        }
                        //std::cout << arrStack[size];
                    } else {
                        for (unsigned int j = 0; j < i; j++) {
                            std::cout << arrStack[j] << ' ';
                        }
                        std::cout << arrStack[i];
                    }
                    std::cout << std::endl;
                }
            } else {
                std::cout <<"error"<<std::endl;
            }
        }

        if ( strTest == "push") {
            if ( counterPr == 1 && set == 1) {
                if (i == size - 1) {
                    std::cout << "overflow" << std::endl;
                } else {
                    i++;
                    arrStack[i] = strExp;
                }
            }
            else {
                std::cout <<"error"<<std::endl;
            }
        }
    }
    if ( arrStack != nullptr) {
        delete []arrStack;
    }
    return 0;
};
