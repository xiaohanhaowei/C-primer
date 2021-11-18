#include <string>
#include <iostream>
// struct SaleData {
class SaleData {

friend SaleData add(const SaleData&, const SaleData&);
friend std::istream &read(std::istream&, SaleData&);
friend std::ostream &print(std::ostream&, const SaleData&);
public:
    SaleData() = default;
    SaleData(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    // SaleData(): SaleData("", 0, 0) {}
    // SaleData(const std::string &s) : SaleData(s, 0, 0){}
    explicit SaleData(const std::string &s) : bookNo(s){ }
    SaleData(std::istream &);
    std::string isbn() const {return bookNo;};
    SaleData& combine(const SaleData&);
    double avg_price() const { return units_sold? revenue/units_sold : 0;}
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.;    
};

SaleData add(const SaleData&, const SaleData&);
std::ostream &print(std::ostream&, const SaleData&);
std::istream &read(std::istream&, SaleData&);