#include "textquery.h"
class Query_Base {
public:
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_Base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};
