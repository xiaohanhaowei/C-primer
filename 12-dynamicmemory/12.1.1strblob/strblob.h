#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <initializer_list>
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
    void push_back(const std::string &t) {return data->push_back(t);}
    void pop_back();
    void test();
    std::string& front();
    std::string& back();
    std::string& front() const;
    std::string& back() const;
    int ref_count() const {return data.use_count();};
    StrBlobPtr begin() {return StrBlobPtr(*this);}
    StrBlobPtr end() 
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

private:
    std::shared_ptr<std::vector<std::string> > data;
    void check(size_type ix, const std::string &msg) const;
};