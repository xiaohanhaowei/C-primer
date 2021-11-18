#include <iostream>
#include "intelpointer.h"

IntelPointer::IntelPointer(int *p, int i) : m_ref(new RefCount(p)), val(i) {  //默认函数只在声明时就可以。
    std::cout << "IntelPointor constructor" << std::endl;
}
int* IntelPointer::get_ptr() const {
    return m_ref->ptr;
}

void IntelPointer::set_ptr(int *p) {
    m_ref->ptr = p;
}

int IntelPointer::get_val() const {
    return val;
}

void IntelPointer::set_val(int i) {
    val = i;
}

int IntelPointer::get_ptr_val() const {
    return *(m_ref->ptr);
}

void IntelPointer::set_ptr_val(int i) {
    *(m_ref->ptr) = i;
}

//赋值拷贝引起的引用数量变化--拷贝构造函数和拷贝赋值运算符
IntelPointer::IntelPointer(const IntelPointer& ip) : m_ref(ip.m_ref), val(ip.val) {
     std::cout << "IntelPointer copy constructor m_ref->ref_count = " << m_ref->refcount << std::endl;
     ++m_ref->refcount;
}

IntelPointer& IntelPointer::operator=(const IntelPointer& rhs) {
    std::cout << "IntelPointer assignment rhs.m_ref->refcount = " << rhs.m_ref->refcount << std::endl;
    std::cout << "IntelPointer assignment m_ref->refcount = " << m_ref->refcount << std::endl;
    ++rhs.m_ref->refcount;
    if (--m_ref->refcount == 0) {
        delete m_ref;
    }
    m_ref = rhs.m_ref;
    val = rhs.val;
    return *this;
}

IntelPointer::~IntelPointer() {
    std::cout << "destroy IntelPointer" << std::endl;
    if (--m_ref->refcount == 0) {
        delete m_ref;
        m_ref = nullptr;
    }

}

int main() {
    int *intp = new int(12);
    IntelPointer sp(intp, 10);
    IntelPointer sp1(sp);
    IntelPointer sp2(sp);
    {
        IntelPointer ptr3;
        ptr3 = sp;
    }
    return 0;
}