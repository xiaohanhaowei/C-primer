#include <stdexcept>
#include "strblob.h"

void strBlob::check(size_type index, const std::string &msg) const {
    if (index >= data->size()) {
        throw std::out_of_range(msg);
    }
}

std::string& strBlob::front() {
    check(0, "front on strBlob");
    return data->front();
}
//const version of front back function
std::string& strBlob::front() const {
    check(0, "front on strBlob");
    return data->front();
}

std::string& strBlob::back() const {
    check(0, "front on strBlob");
    return data->back();
}

std::string& strBlob::back() {
    check(0, "front on strBlob");
    return data->back();
}

void strBlob::pop_back() {
    check(0, "pop_back on empty strBlob");
    data->pop_back();
}
#ifdef 0
int main() {
    // strBlob sblob({std::string("whw"), std::string("hi")});

    //测试const成员函数
    // const strBlob sblob({std::string("whw"), std::string("hi")});
    // std::cout << "test const member function, " << sblob.front() << std::endl;

    //12.1
    strBlob b1;
    {
        strBlob b2 = {"a", "an", "the"};
        b1 = b2; //引用计数
        b2.push_back("about");
        auto cb2 = b2.ref_count(); //这时类的一个方法，返回data的引用计数（data为shared_ptr）
        auto cb1 = b1.ref_count();
        std::cout << "b1 local env reference count: " << cb1 << std::endl;  //cb1 = 2
        std::cout << "b2 reference count: " << cb2 << std::endl; // cb2 = 2
    } //这出来后，会影响b1的引用计数，只会影响b2的。
    auto cb1 = b1.ref_count();
    std::cout << "b1 reference count: " << cb1 << std::endl; // cb1 = 1

    /*没跑代码时我的理解：
        b1 成为了空悬指针
        b2直接释放掉了
    */

   /* 跑了代码后：
        考虑引用计数
        无论如何，b2由于出了局部作用域，所以b2将释放掉
        局部作用域中，当b1 = b2操作后，b1的引用计数变成了2？同时b2的引用计数也变成了2
        但是出了局部作用域，b1的引用计数变成了1
        https://blog.csdn.net/hj605635529/article/details/76984839
   */
   std::cout << b1.size() << std::endl;
//    std::cout << b2.empty() << std::endl;
    return 0;
}
#endif