struct Base
{
    Base(): mem(0){}
protected:
    int mem;
};

struct Deriv : Base 
{
    Deriv(int i) : mem(i) {}
    int get_mem() {return mem;}
protected:
    int mem;  //覆盖Base中的mem
};

