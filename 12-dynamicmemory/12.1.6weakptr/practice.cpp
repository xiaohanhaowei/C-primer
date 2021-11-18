#include <fstream>
#include <iostream>
#include "strblobptr.h"

//exercise 12.20
void readfile(const std::string file, const strBlob &blob) {
   std::ifstream r_f(file);
   std::string s;
   while (getline(r_f, s))
   {
       blob.push_back(s);
   }
   r_f.close();
} 
void printcontent(const strBlob &blob) {
    // StrBlobPtr beg = blob.begin();
    // while(beg.curindex != end.curindex) {
    //     std::cout << beg.deref() << std::endl;
    //     beg.incur();
    // }
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); neq(pbeg, pend); pbeg.incr()) {
        std::cout << pbeg.deref() << std::endl;
    }
}

int main() 
{
    std::string rd_file = "data.txt";
    const strBlob fileblob;
    readfile(rd_file, fileblob);
    printcontent(fileblob);
    return 0;
}