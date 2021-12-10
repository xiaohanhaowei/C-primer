#include <string>
#include <iostream>
#include "textquery.h"
#include "query_base.h"
class Query {
friend Query operator~(const Query &);
friend Query operator|(const Query &, const Query &);
friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string &);
    QueryResult eval(const TextQuery& t) const {return q->eval(t); }
    std::string rep() const {return q->rep();}
private:
    Query(std::shared_ptr<Query_Base> query) : q(query) {}
    std::shared_ptr<Query_Base> q;
};

