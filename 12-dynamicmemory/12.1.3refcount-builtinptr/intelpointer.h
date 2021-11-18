#include "refcount.h"
class IntelPointer {
public:
    IntelPointer(int *p =0, int i = 0);
    //拷贝构造函数
    IntelPointer(const IntelPointer&);
    IntelPointer& operator=(const IntelPointer&);

    ~IntelPointer();
    int* get_ptr() const;
    void set_ptr(int *p);

    int get_val() const;
    void set_val(int i);

    int get_ptr_val() const;
    void set_ptr_val(int i);
private:
    RefCount *m_ref;
    int val;
};