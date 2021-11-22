/*行为像指针的类，要有引用计数*/
#include <string>

class HasPtrRef {
//13.3swap操作
friend void swap(HasPtrRef&, HasPtrRef&);  //这条语句的声明不用必须在这个文件里。
public:
    HasPtrRef(const std::string &s = std::string()) :
        ps(new std::string(s)), val(0), use(new std::size_t(1)) { }
    HasPtrRef(const HasPtrRef& hpr) : ps(hpr.ps), val(hpr.val), use(hpr.use) {++ *use;} //测试最终use的值
    //copy and swap
    HasPtrRef& operator=(HasPtrRef rhs);
    // copy operator=
    HasPtrRef& operator=(const HasPtrRef&);
    std::size_t printref() { return *use; }
    std::string printstring() { return *ps; }
    ~HasPtrRef();
private:
    std::string *ps;
    int val;
    std::size_t *use;
};

inline void swap(HasPtrRef&, HasPtrRef&);