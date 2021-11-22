#include <iostream>
#include <utility>
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
//push_back的右值定义
void StrVec::push_back(std::string&& s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
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

//移动构造函数与移动赋值运算符
StrVec::StrVec(StrVec &&s) noexcept :
    elements(s.elements), first_free(s.first_free), cap(s.cap) 
{
        s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    //检测自赋值
    if(this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    } 
    return *this;
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

// void StrVec::reallocate() {
//     auto newcap = size() ? 2*size() : 1;
//     auto newdata = alloc.allocate(newcap);
//     auto dst =newdata;
//     auto elem = elements;
//     for(std::size_t i = 0; i != size(); ++i) {
//         alloc.construct(dst++, std::move(*elem++));
//     }
//     free();
//     elements = newdata;
//     first_free = dst;
//     cap = elements + newcap;
    
// }

//13.6移动迭代器 
void StrVec::reallocate() {
    auto newcap = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcap);
    auto dst = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);

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
    //移动构造函数
    StrVec s1(std::move(s));
    for (auto b = s1.begin(); b != s1.end(); ++b) {
        std::cout << *b << " "; 
    }
    std::cout << std::endl;

    std::cout << "s: " << s.size() << "; " << s.capacity() << std::endl;
    
    //测试标准库中的函数
    std::string ss = std::string("hij");
    std::string ss1 = std::string(std::move(ss));

    std::cout << "ss: " << ss  << std::endl;   //空
    std::cout << "ss.size(): " << ss.size()  << std::endl; //0 
    //问题：不能对移后源对象做什么？能对移后源对象做什么？
    return 0;
}