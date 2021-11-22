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

HasPtrRef::~HasPtrRef() {
    if(--*use == 0) {
        delete use;
        delete ps;
        val = 0;
    }
}

int main() {
    HasPtrRef hprf(std::string("abc"));
    std::cout << hprf.printref() << std::endl;
    HasPtrRef hprf1(hprf);
    std::cout << hprf1.printref() << std::endl;
    std::cout << hprf.printref() << std::endl;
}