#include <utility>
class Base {
public:
    Base(const Base& b);
    Base(Base&& b);
    Base& operator=(const Base& rhs) {
    }
    virtual int fcn();
    virtual ~Base();
};

class D1 : public Base {
public:
    //15.7定义拷贝控制成员
    D1(const D1& d) : Base(d) , /*D成员初始化*/{}
    D1(D1&& d) : Base(std::move(d)), /*D成员初始化*/{}
    D1& operator=(const D1& rhs) { 
        Base::operator=(rhs);
    }
    int fcn(int);
    virtual void f();
};

class D2 : public D1 {
public:
    int fcn(int);
    int fcn();
    void f();
}
