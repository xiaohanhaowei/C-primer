#include <string>
#include <iostream>
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() {
        return bookNo;
    }
    virtual double net_price(std::size_t n) const {return  n * price;}
private:
    std::string bookNo;
protected:
    double price = 0.;
};

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "total due" << ret << std::endl;
}