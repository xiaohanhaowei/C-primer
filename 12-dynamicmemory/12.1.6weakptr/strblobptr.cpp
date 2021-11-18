#include <stdexcept>
#include "strblobptr.h"

std::shared_ptr<std::vector<std::string> > StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr!");
    }
    if (i > ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curindex, "deref pas end");
    return (*p)[curindex];
}

StrBlobPtr& StrBlobPtr::incr() {
    auto p = check(curindex, "increment end of StrBlobPtr");
    ++curindex;
    return *this;
}

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

StrBlobPtr strBlob::begin() const 
{
    return StrBlobPtr(*this);
}
StrBlobPtr strBlob::end() const
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
//就缺这两个比较函数
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    // 若底层的 vector 是同一个
    if (l == r)
        // 若两个指针都是空，或者指向相同元素时，它们相等
        return (!r || lhs.curindex == rhs.curindex);
    else
        return false;       // 若指向不同 vector，则不可能相等
}

bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !eq(lhs, rhs);
}
