#include "binaryquery.h"

class AndQuery :public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query&l, const fQuery &r) : BinaryQuery(l, r, "&") {}
    QueryResult eval(const TextQuery &t) const ;
};

inline Qurey operator&(const Query &l, const Query&r) {
    return std::shared_ptr<Query_Base>(new AndQuery(l, r));
}
