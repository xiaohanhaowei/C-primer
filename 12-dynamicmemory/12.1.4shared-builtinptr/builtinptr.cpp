#include <iostream>
#include <memory>
#include <typeinfo>
#include "def.h"
using namespace std;

#if INIT
int main() {
    std::shared_ptr<int> p(new int(32));
    std::shared_ptr<int> p1(p);

    std::shared_ptr<int>p2(p);
    // std::shared_ptr<int> p2(std::shared_ptr<int>(p));
    std::cout << p.use_count() << std::endl;
    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
    return 0;
}
#endif
// TODO: C++ primer P414
#if P414
int main() {
    shared_ptr<int> p(new int(42));
    auto *q = p.get();
    {
        // shared_ptr<int>(q); //C++ primer P414
        /*
        上边代码运行后，输出
        42
        42
        */

        /**********************************************/
        (shared_ptr<int>(q));  //按照编译器的指示做更改
        /*
        按照编译器提示更改后
        在此条件下的两个输出
        0
        0
        test(99914,0x10c386e00) malloc: *** error for object 0x7fe902405a20: pointer being freed was not allocated
        test(99914,0x10c386e00) malloc: *** set a breakpoint in malloc_error_break to debug
        证明p被指向的内存已被释放，q也已被释放。p此时成为空悬指针，q也成为了空悬指针。
        */
    }
    cout << *p << endl;
    cout << *q << endl;
    return 0;
}
#endif

#if GET
int main() {
    
    shared_ptr<int> p(new int(1234));
    int *q = p.get(); //得到存储的指针，非管理的指针（new int(1234)代表的指针） 不知道是不是得到的是普通指针还是内置指针
    cout << "q type: " << typeid(p.get()).name() << endl;  //执行命令：./test | c++filt --types    其中test为生成的可执行程序
    // cout << "q type: " << typeid(new int(1234)).name() << endl;  //执行命令：./test | c++filt --types    其中test为生成的可执行程序
    {
        // shared_ptr<int> p1(shared_ptr<int>(q));
        shared_ptr<int> p3(q);
        // shared_ptr<int> p3 = shared_ptr<int>(q);
        cout << "p3 ref-count: "<< p3.use_count() << endl;
        cout << "p ref-count: "<< p.use_count() << endl;
    }
    return 0;
}
#endif 

#if NORM
void process(shared_ptr<int> ptr)
{
    cout << "inside the process function:" << ptr.use_count() << "\n";
}
int main() {
    
    shared_ptr<int> p(new int(1234));
    auto q = p.get();
    delete q;
    return 0;
}
#endif 

#if TEMPCONSTRUCT
void process(shared_ptr<int> ptr)
{
    cout << "inside the process function:" << ptr.use_count() << "\n";
    // shared_ptr<int> ptr2(ptr);
    // shared_ptr<int> ptr2(static_cast<shared_ptr<int>>(ptr)); //没问题
    // shared_ptr<int> ptr2(shared_ptr<int>(ptr)); //这会产生像是一个函数报警，所以编译器有可能这变成了一个函数
    // cout << ptr2.use_count() << endl; //由于上边的原因，这会产生错误。
    shared_ptr<int> ptr2 = shared_ptr<int>(ptr); 
    cout << ptr2.use_count() << endl; 
    shared_ptr<int> ptr3 = shared_ptr<int>(ptr2);
    cout << ptr3.use_count() << endl; 

}
int main() {
    
    shared_ptr<int> p(new int(1234));
    // process(p);
    process(shared_ptr<int>(p));
    return 0;
}
#endif 
