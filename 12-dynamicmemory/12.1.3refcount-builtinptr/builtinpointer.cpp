#include <iostream>
#include "builtinpointer.h"

void BuiltinPointer::set_ptr_val(int i) {
    *ptr = i;
}

void BuiltinPointer::set_val(int i) {
    val = i;
}

BuiltinPointer::~BuiltinPointer() {
    std::cout << "destroy BuiltinPointer" << std::endl;
    if (nullptr != ptr) {
        delete ptr;
        ptr = nullptr;
    }
}

int main() {
    int v = 42;
    BuiltinPointer ptr(&v, 20);
    BuiltinPointer ptr1(ptr);
    ptr1.set_ptr_val(30);
    int ptr_val = ptr.get_ptr_val();
    int ptr_val1 = ptr1.get_ptr_val();
    std::cout << ptr_val << std::endl;
    std::cout << ptr_val1<< std::endl;
    return 0;

}