#include "query_base.h"
#include "query.h"

class NotQuery : public Query_Base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {}
    QueryResult eval(const TextQuery& t) const;
    std::string rep() const {return "~(" + query.rep() + ")";}
    Query query;
};
inline Query operator~(const Query &q) {
    return std::shared_ptr<Query_Base>(new NotQuery(q));
}