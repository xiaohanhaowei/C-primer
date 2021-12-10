#include <vector>
#include <set>
#include <iostream>
#include "bulkquote.h"
class Basket {
public:
    Basket();
    //处理指针版本
    // void add_item(const std::shared_ptr<Quote> &sale) {
    //     items.insert(sale);
    // }
    //处理对象版本
    void add_item(const Quote& sale) { items.insert(std::shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote && sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
    double total_recipe(std::ostream&) const;
    void push_back(Quote &&);
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};

};