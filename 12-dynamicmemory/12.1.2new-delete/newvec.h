#include <iostream>
#include <vector>
#include <memory>
using namespace std;

vector<int>* func1() 
{
    // vector<int> *p = new vector<int>();  //考虑到vector有自己的构造函数可不可以不使用后边的括号（值初始化）？
    // return p;
    return new vector<int>();
}

vector<int>* read(istream &is, vector<int> *p) {
    int ival;
    while(is >> ival){
        p->push_back(ival);
        char ic = is.get();
        if (ic == '\n') {
            break;
        }
    }
        
    cout << "read data done!" << endl;;
    return p;
}

void print(ostream &os, vector<int> *p) {
    // for (auto iter = p->begin(); iter!=p->end(); ++iter) {
    //     os << *iter << " ";
    // }
    for (auto val : *p) {
        os << val << " ";
    }
    os << endl;
    std::cout << "print data done!" << endl;
    delete p;
}


