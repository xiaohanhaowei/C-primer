# include <iostream>
class Base {
public:
    static int statemem(int i=0) {return i;}
};

class Dev : Base {
public:
    void print(const Dev&);
};

void Dev::print(const Dev& der) {
    int a = Base::statemem();
    std::cout << "Base: " << a << std::endl;
    int b = Base::statemem(3);
    a = Base::statemem();
    std::cout << "Base-3: " << b << std::endl;
    std::cout << "Now Base: " << a << std::endl;
    int c = der.statemem();
    a = Base::statemem();
    std::cout << "dev-obj: " << c << std::endl;
    std::cout << "Now Base: " << a << std::endl;
    int d = statemem();
    std::cout << "this: " << d << std::endl;
}

int main() {
    Dev d;
    Dev d2;
    d.print(d2);
    return 0;
}