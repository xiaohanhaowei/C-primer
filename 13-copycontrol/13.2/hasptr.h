#include <string>
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), val(0) {} //ps的存在哪？动态内存？
    HasPtr(const HasPtr& p) : 
        ps(new std::string(*p.ps)), val(p.val) {}
    HasPtr& operator=(const HasPtr&);
    ~HasPtr() {delete ps;}
private:
    std::string *ps;
    int val;
};