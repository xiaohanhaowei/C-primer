#include "query.h"
#include "wordquery.h"

std::ostream& operator<<(std::ostream &s, const Query& query) {
    return s << query.rep(); 
}

inline Query::Query(const std::string& s ) : q(new WordQuery(s)){

}