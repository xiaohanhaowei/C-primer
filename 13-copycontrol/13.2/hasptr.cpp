#include "hasptr.h"
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    auto p = new std::string(*rhs.ps);
    delete ps;
    ps = p;
    val = rhs.val;
    return *this;
}