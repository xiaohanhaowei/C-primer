#include <iostream>
class IntelPointer;
class RefCount
{
friend class IntelPointer;
public:
    RefCount(int* p) : ptr(p), refcount(1) {
        std::cout << "RefCount  constructor." << std::endl;
    }
    ~RefCount();
private:
    int *ptr;
    int refcount;
};

RefCount::~RefCount() {
    std::cout << "destroy RefCount object." << std::endl;
    if (nullptr != ptr) {
        delete ptr;
        ptr = nullptr;
    }
}