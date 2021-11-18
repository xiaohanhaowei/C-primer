#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <initializer_list>
// #include "strblob.h"
class StrBlobPtr;
class strBlob {
friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    strBlob() : data(std::make_shared<std::vector<std::string>>()) {
        std::cout << "construct with a empty content's shared pointer" << std::endl;
    }
    strBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { 
        std::cout << "construct with a " << data->size() << " elements" << std::endl;
    }
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const std::string &t) const {return data->push_back(t);}
    void pop_back();
    std::string& front();
    std::string& back();
    std::string& front() const;
    std::string& back() const;
    int ref_count() const {return data.use_count();};
    // StrBlobPtr begin() {return StrBlobPtr(*this);}
    // StrBlobPtr end() 
    // {
    //     auto ret = StrBlobPtr(*this, data->size());
    //     return ret;
    // }
    //有一个问题，这个能治定义一次么？就是直接定义只有const的。而像如下的形式不定义？
    /*
    StrBlobPtr begin();
    StrBlobPtr end();
    */
   
    StrBlobPtr begin() const;
    StrBlobPtr end() const;

private:
    std::shared_ptr<std::vector<std::string> > data;
    void check(size_type ix, const std::string &msg) const;
};

class StrBlobPtr {
friend bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
    StrBlobPtr() : curindex(0){ }
    StrBlobPtr(std::shared_ptr<std::vector<std::string> > sptr) : wptr(sptr), curindex(0) { }
    StrBlobPtr(strBlob &a, std::size_t sz = 0) : wptr(a.data), curindex(sz) { }
    //12.22解决方案
    //这可以不用重新定义
    StrBlobPtr(const strBlob&a, std::size_t sz = 0) : wptr(a.data), curindex(sz) { }
    
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string> > check (std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string> > wptr;
    //12.22先前的解决方案
    // std::weak_ptr<const std::vector<std::string> > cwptr;
    std::size_t curindex;
};
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
