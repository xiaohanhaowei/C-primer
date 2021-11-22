#include <iostream>
#include "strvec.h"
void StrVec::chk_n_alloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

std::size_t StrVec::size() const {
    return first_free - elements;
}

std::size_t StrVec::capacity() const {
    return cap - elements;
}

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string*e) {
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b, e ,data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p!=elements; ) { //括号里不能是--p
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}   

StrVec::StrVec(const StrVec& rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs) {
    free();
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcap = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcap);
    auto dst =newdata;
    auto elem = elements;
    for(std::size_t i = 0; i != size(); ++i) {
        alloc.construct(dst++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dst;
    cap = elements + newcap;
    
}
//初始化这一句必须有
std::allocator<std::string> StrVec::alloc;

int main() {
    StrVec s;
    s.push_back(std::string("abc"));
    std::cout << *s.begin() << std::endl;
    s.push_back(std::string("efg"));
    for (auto b = s.begin(); b != s.end(); ++b) {
        std::cout << *b << " "; 
    }
    std::cout << std::endl;
    return 0;
}