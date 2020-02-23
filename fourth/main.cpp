#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>

//std::vector < std::vector <int> > grafSmezh(20);
//std::vector<bool> used(20);
//std::vector<bool> used_1 (15);

struct graph {
    std::string root;
    std::unordered_map < std::string , std::pair < std::vector <std::string> , bool >> table;
};

void dfs (graph& gr){
    std::stack <std::string> s;
    s.push(gr.root);
    while (!s.empty()) {
        std::string u = s.top();
        s.pop();
        if (!gr.table.at(u).second) {
            std::cout << u << std::endl;
            gr.table.at(u).second = true;
            std::sort(gr.table[u].first.begin(), gr.table[u].first.end());
            std::reverse(gr.table[u].first.begin(), gr.table[u].first.end());
            for (size_t i = 0; i < gr.table[u].first.size(); i++) {
                if (!gr.table[gr.table[u].first.at(i)].second)
                    s.push(gr.table[u].first.at(i));
            }
        }
    }
}
void bfs(graph& gr) {
    std::queue<std::string> q;
    q.push(gr.root);
    while (!q.empty()) {
        std::string u = q.front();
        q.pop();
        if ( !gr.table.at(u).second ) {
            std::cout << u << std::endl;
            gr.table.at(u).second = true;
            std::sort(gr.table[u].first.begin(), gr.table[u].first.end());
            for (size_t i = 0; i < gr.table[u].first.size(); i++) {
                if (!gr.table[gr.table[u].first.at(i)].second)
                    q.push(gr.table[u].first.at(i));
            }
        }
    }
}

int main() {

    int parametr = 0 ; //1 to 4
    std::string orietation ; // ориентированный или нет
    std::string width_or_depth;

    std::string str; // для ввода
    bool set = 0;
    std::string ver  ; // начало обхода

    while (  std::getline(std::cin , str ) && set == 0) {
        int counterPr = 0;
        std::string a;
        std::string b;
        int position;

        for (unsigned int h = 0; h < str.size(); h++) {
            if (str[h] == ' ') {
                counterPr++;
            }
            if (counterPr > 2) {
                break;
            }
        }

        ver = str.substr( 2, str.size() - 4);

        for (unsigned int i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                a += str[i];
            } else {
                position = i;
                break;
            }
        }
        for (unsigned int i = position + 1 + ver.size() + 1; i < str.size(); i++) {
            if (str[i] != '\0') {
                b += str[i];
            } else {
                break;
            }
        }

        //const char *ch = &str[2];
        //ver = std::atoi(ch);
        //ver = str.substr( 2, str.size() - 4);
        orietation = a;
        width_or_depth = b;
        if ((a == "u" && b == "d") && counterPr == 2) {
            parametr = 1;
            set = 1; //не ориент в глуб
        } else {
            if ((a == "d" && b == "d") && counterPr == 2) {
                parametr = 2;
                set = 1;  //ориент в глуб
            } else {
                if ((a == "u" && b == "b") && counterPr == 2) {
                    parametr = 3;
                    set = 1; // не ориент в ширину
                } else {
                    if ((a == "d" && b == "b") && counterPr == 2) {
                        parametr = 4;
                        set = 1; //ориент в ширину
                    }
                }
            }
        }
    }

    graph gr;
    gr.root = ver;
    gr.table[ver].second = false;

    std::string first = str.substr(0 ,str.find(' '));
    std::string second = str.substr(str.find(' ') + 1 , str.size());

    gr.table[first].second = false;
    gr.table[first].first.push_back(second);
    if (orietation == "u") {
        // gr.table[example].first.push_back(example2);
        gr.table[second].first.push_back(first);
    }

    while (getline(std::cin, str, '\n')) {
        if ( str != "EOF") {
            std::string example = str.substr(0, str.find(' '));
            std::string example2 = str.substr(str.find(' ') + 1, str.size());
            gr.table[example].second = false;
            gr.table[example].first.push_back(example2);
            if (orietation == "u") {
                gr.table[example2].first.push_back(example);
            }
        }
        else {
            break;
        }
    }

    if ( parametr == 1){
       dfs(gr);
    }
    if ( parametr == 2){
        dfs(gr);
    }
    if ( parametr == 3){
        bfs(gr);
    }
    if ( parametr == 4){
        bfs(gr);
    }
    return 0;
}
