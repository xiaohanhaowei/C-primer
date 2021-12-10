class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base
{
    int f() { return prot_mem;}

    // char g() {return priv_mem;}  //成员 "Base::priv_mem" (已声明 所在行数:7) 不可访问
};

struct Priv_Derv :private Base
{
public:
    using Base::pub_mem;
protected:
    using Base::prot_mem;
    int f1() const {return prot_mem;}
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() {return prot_mem;}  //没问题
};

struct Derived_from_public : public Priv_Derv {
    // int use_base() {return prot_mem;} //成员 "Base::prot_mem" (已声明 所在行数:5) 不可访问
};
