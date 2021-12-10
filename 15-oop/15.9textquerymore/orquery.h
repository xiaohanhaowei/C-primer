#include "binaryquery.h"

class OrQuery : public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query&l, const Query &r) : BinaryQuery(l, r, "|") {}
    QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &l, const Query &r) {
    return std::shared_ptr<Query_Base>(new OrQuery(l, r));
}