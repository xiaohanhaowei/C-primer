#include "query_base.h"
#include "query.h"

class BinaryQuery : public Query_Base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), operat(s) {}
    std::string rep() const { return "(" + lhs.rep() + operat + rhs.rep() + ")";}
    Query lhs;
    Query rhs;
    std::string operat;
    
};