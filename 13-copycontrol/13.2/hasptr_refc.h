/*行为像指针的类，要有引用计数*/
#include <string>

class HasPtrRef {
public:
    HasPtrRef(const std::string &s = std::string()) :
        ps(new std::string(s)), val(0), use(new std::size_t(1)) { }
    HasPtrRef(const HasPtrRef& hpr) : ps(hpr.ps), val(hpr.val), use(hpr.use) {++ *use;} //测试最终use的值
    HasPtrRef& operator=(const HasPtrRef&);
    std::size_t printref() { return *use; }
    ~HasPtrRef();
private:
    std::string *ps;
    int val;
    std::size_t *use;
};