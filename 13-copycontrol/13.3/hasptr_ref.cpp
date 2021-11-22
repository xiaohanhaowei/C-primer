#include <iostream>
#include "hasptr_refc.h"

// HasPtrRef::HasPtrRef(const HasPtrRef& hps) {
//     if(--*use == 0) {
//         delete use;
//         delete ps;
//         val = hps.val;
//         use = hps.use;
//         ps = hps.ps;
//         val = hps.val;
//         ++*use;
//     } 
// }


HasPtrRef& HasPtrRef::operator=(const HasPtrRef& rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete use;
        delete ps;
    }
    use = rhs.use;
    ps = rhs.ps;
    val = rhs.val;
    return *this;
}

//copy and swap
HasPtrRef& HasPtrRef::operator=(HasPtrRef rhs) {
    swap(*this, rhs);
    return *this;
}

HasPtrRef::~HasPtrRef() {
    if(--*use == 0) {
        delete use;
        delete ps;
        val = 0;
    }
}

void swap(HasPtrRef &lhs, HasPtrRef &rhs) {
    using std::swap;  // allow ADL
    swap(lhs.ps, rhs.ps);
    swap(lhs.val, rhs.val);
}

int main() {
    HasPtrRef hprf(std::string("abc"));
    std::cout << "hprf: " << hprf.printstring() << std::endl;
    HasPtrRef hprf1(std::string("efg"));
    std::cout << "hprf1: " << hprf1.printstring() << std::endl;
    swap(hprf1, hprf);
    std::cout << "hprf: " << hprf.printstring() << std::endl;
    std::cout << "hprf1: " << hprf1.printstring() << std::endl;
    return 0;
}