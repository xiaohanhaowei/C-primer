#include <memory>
#include <string>
#include <utility>
class StrVec {

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    //13.6移动构造函数与移动赋值运算符
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();
    // void push_back(const std::string&);
    //接受左值和右值的成员函数：push_back
    void push_back(const std::string&);
    void push_back(std::string&&);
    std::size_t size() const;
    std::size_t capacity() const;
    std::string* begin() const {return elements;}
    std::string* end() const {return first_free;}

private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    static std::allocator<std::string> alloc;  //静态成员没有编译通过，但是产生可执行文件时出错：Undefined symbols for architecture x86_64: StrVec::alloc", referenced from ... 
    // std::allocator<std::string> alloc;
    void chk_n_alloc();
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
};