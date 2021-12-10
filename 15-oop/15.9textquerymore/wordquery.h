
# include "query_base.h"
#include "query.h"
class WordQuery : public Query_Base {
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) {}
    QueryResult eval(const TextQuery& t) const {return t.query(query_word);}
    std::string rep() const {return query_word;}
    std::string query_word;
};