#include <string>
#include "bulkquote.h"
Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
    Disc_quote(book, p, qty,disc) { 

}

double Bulk_quote::net_price(size_t cnt) {
    if (cnt > min_qty) {
        return cnt * (1 - discount) * price;
    }
    else 
        return cnt * price;
}