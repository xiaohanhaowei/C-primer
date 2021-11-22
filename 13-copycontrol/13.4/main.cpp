#include <iostream>
#include "message.h"
#include "folder.h"

int main() {
    Message ms("abc");
    Message ms1("efg");
    Folder f1;
    Folder f2;
    ms.save(f1);
    ms1.save(f2);
    auto ctms = f1.printms();
    bool f_r = ctms.size() > 0;
    std::cout << f_r << std::endl;
    return 0;
}