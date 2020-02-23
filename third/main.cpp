#include <iostream>
#include <fstream>



int main(int argc, char *argv[]) {
    int size = 0;
    std::string  *arrQueue = nullptr;
    int head = 0;
    int tail = -1;
    int countOfElement = 0;

    int counter = 0;
    int counterExp = 0;

    bool set = 0;


    std::string str;
    std::string nameFrom;
    std::string nameIn;


    std::string exampleStr;
    std::getline(std::cin , exampleStr);

    std::ifstream in(argv[1]);
    //std::ifstream in(nameFrom);
    char *gg = argv[2];
    std::ofstream out;

    if (in.is_open()) {
        while ( std::getline(in,str)){
            int number = 0;
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
                out.open(gg, std::ios::app);
                if (out.is_open()) {
                    out << "error" << std::endl;
                }
                out.close();
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

            number = std::atoi(strExp.c_str());


            if (strTest == "set_size" && counterPr == 1  && number!= 0) {
                counterExp++;
            }

            if (strTest == "set_size" && counterExp == 1 && number != 0) {

                size = number;
                arrQueue = new std::string[size];
                set = 1;

            }
            else {
                if( strTest == "set_size") {
                    out.open(gg, std::ios::app);
                    if (out.is_open()) {
                        out << "error" << std::endl;
                    }
                    out.close();
                }
            }
          
            if (strTest == "print") {
                out.open(gg, std::ios::app);
                if( counterPr == 0 && set == 1) {
                    if (out.is_open()) {
                        if (countOfElement == 0) {
                            out << "empty" << std::endl;
                        } else {
                            if ( (head - tail) < 0 ) {
                                for (int i = head ; i < tail + 1 ; ++i){
                                    out << arrQueue[i];
                                    if(i != tail)
                                        out << " ";
                                }
                           
                            } else {
                                if ( (head - tail) > 0) {
                                    for ( int i = head ; i < size ; ++i ){
                                        out << arrQueue[i];
                                        if(i < size)
                                            out << " ";
                                    }
                                    for ( int i = 0 ; i < tail +1 ; ++i){
                                        out << arrQueue[i];
                                        if(i < tail){
                                            out << " ";
                                        }
                                    }
                                } else {
                                    if ( head == tail ){
                                        out << arrQueue[head];
                                    }
                                   // out<< std::endl;
                                }
                            }
                            out<< std::endl;
                        }
                    }
                } else {
                    out <<"error"<<std::endl;
                }
                out.close();
            }

            if ( strTest == "push") {
                out.open(gg, std::ios::app);
                if ( counterPr == 1 && set == 1) {
                    if ( out.is_open()) {
                        if ( countOfElement >= size ){
                            out << "overflow" << std::endl;
                        }
                        else {
                            if ( tail >= size - 1 ){
                                tail = -1 ;
                            }
                            arrQueue[++tail] = strExp;
                            countOfElement++;
                        }
                       
                    }

                } else {
                    out <<"error"<<std::endl;
                }
                out.close();
            }

            if (strTest == "pop") {
                out.open(gg, std::ios::app);
                if ( counterPr == 0 && set == 1) {
                    if (out.is_open()) {
                        if (countOfElement == 0) {
                            out << "underflow" << std::endl;
                        } else {
                           
                           if ( head >= size){
                               head = 0 ;
                           }
                           out << arrQueue[head] << std::endl;
                           arrQueue[head++].clear();
                           if ( --countOfElement == 0 ){
                               head = 0;
                               tail = -1;
                           }
                        }
                    }
                } else {
                    out <<"error"<<std::endl;
                }
                out.close();
            }
        }
    }
    in.close();
    if ( arrQueue != nullptr) {
        delete []arrQueue;
    }

    return 0;
}
