# include "basket.h"
double Basket::total_recipe(std::ostream& os) const {
    double sum = 0.;
    for (auto iter = items.cbegin(); 
              iter != items.cend();
              iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "total sale: " << sum << std::endl;
    return sum;
}