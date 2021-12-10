#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include "def.h"

#if MYDEF
class QueryResult;
class TextQuery {
friend class QueryResult;
public:
    TextQuery(std::ifstream& infile) {readfile(infile);}
    void readfile(std::ifstream& infile);
    QueryResult query(const std::string& s) const;
private:
    std::vector<std::string> data;
    std::map<std::string, std::vector<std::size_t> > wordline;

};

class QueryResult {
friend std::ostream print(const std::string&, QueryResult);
public:

private:

};
#endif

#if OFFICIAL
using namespace std;
class QueryResult;
ostream &print(ostream &out, QueryResult&);
class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
friend ostream &print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<set<line_no>> l, shared_ptr<vector<string>> f) : 
        sought(s), lines(l), file(f) { }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
}; 
#endif 