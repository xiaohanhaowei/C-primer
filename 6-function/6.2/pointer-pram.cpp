#include <iostream>

void reset (int *Ip) 
{
    *Ip = 0;
    Ip = 0; //this stage, do not randomly change the pointer value 
}
// function reload
void reset (int &i) {
    i = 0;
}

std::string::size_type find_char (const std::string &s, const char c, std::string::size_type &occur) {
    std::string::size_type ret = s.size();
    occur = 0;
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occur;
        }
    }
    return ret;
}

int main ()
{
    // int n = 0, i = 43;
    // int *p = &n;
    // int *q = &i;
    // std::cout << "original n = " << n << std::endl;
    // std::cout << "original i = " << i << std::endl;
    // *p = 42;
    // p = q;
    // std::cout << "now n = " << n << std::endl;
    // std::cout << "now i = " << i << std::endl;
    // std::cout << "now *p = " << *p << std::endl;
    // std::cout << "now *q = " << *q << std::endl;
    
    //test reset function refernce pointer version
    // int i = 42;
    // std::cout << "original &i = " << &i << std::endl;

    // reset(&i);
    // std::cout << "now i = " << i << std::endl;
    // std::cout << "now &i = " << &i << std::endl;
    // // test reset function reference version
    // int j = 54;
    // reset(j);
    // std::cout << "now j = " << j << std::endl;
    std::string::size_type a = 0;
    char b = 'l';
    auto ret = find_char("hello, world.", b, a);
    std::cout << "a = " << a << "; ret = " << ret << std::endl;
    return 0;
    
}