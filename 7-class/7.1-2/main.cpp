#include "sale_data.h"

int main(){
    
    std::cout << "input：" << std::endl;
    // SaleData s = SaleData(std::cin);
    SaleData s = SaleData("123456");
    s.combine(static_cast<SaleData>("654321"));
    print(std::cout, s);
    return 0;
}