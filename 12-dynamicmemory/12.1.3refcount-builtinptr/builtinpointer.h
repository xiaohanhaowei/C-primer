
class BuiltinPointer {
public:
    BuiltinPointer(int *p =0, int i = 0) : ptr(p), val(i) {};
    ~BuiltinPointer();
    int* get_ptr() const {return ptr;}
    void set_ptr(int *p);

    int get_val() const {return val;}
    void set_val(int i);

    int get_ptr_val() const {return *ptr;}
    void set_ptr_val(int i);
private:
    int *ptr;
    int val;
};