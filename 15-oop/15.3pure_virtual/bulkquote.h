#include <string>
#include "quote.h"
#include "discquote.h"
class Bulk_quote : public Disc_quote {
public:
    // Bulk_quote() = default;
    // Bulk_quote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;
    //15.6
    std::pair<std::size_t, double> dscount_policy() const { return {quantity, discount};}
    //15.7.4
    using Disc_quote::Disc_quote;
};