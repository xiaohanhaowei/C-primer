#include "sale_data.h"

SaleData::SaleData(std::istream &is) {
    read(is, *this);
}
// SaleData::SaleData(const std::string &s, unsigned cnt, double price) {
//     bookNo = s;
//     units_sold = cnt;
//     revenue = cnt * price;
// }
SaleData& SaleData::combine(const SaleData& rhs) { 
    //FIXME：
        /*我之前在sale_data.h定义的时候: SaleData& SaleData::combine(const &SaleData)
        我发现这个“&SaleData”由于没有指定具体类型，编译器自动分配了一个int类型。
        */
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is, SaleData &item) {  //如何定义istream的变量
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price; 
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const SaleData &item) { //如何定义ostream的变量
    os << item.isbn() << " " << item.units_sold << " " 
    << item.revenue << item.avg_price();
    return os;
}

SaleData add(const SaleData &lhs, const SaleData &rhs) {
    SaleData sum = lhs;
    sum.combine(rhs);
    return sum;
}
