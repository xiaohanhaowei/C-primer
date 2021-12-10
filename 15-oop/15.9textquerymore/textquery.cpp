#include "textquery.h"
#if MYDEF
void TextQuery::readfile(std::ifstream &infile) {
    std::string s;
    while (getline(infile, s)) {
        data.push_back(s);
    }
}

std::map<std::string, std::vector<std::size_t> > TextQuery::findword(const std::string word) {
    for (auto piece : data) {
        auto pos = piece.find(word);
        if (pos != std::string::npos) {
            wordline[word].push_back(pos);
        }
    }
}
#endif
#if OFFICIAL
TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while (getline(is, text))
    {
        file->push_back(text);
        int n = file->size() -1;
        istringstream line(text);
        string word;
        while(line >> word) {
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}


QueryResult TextQuery::query(const string &s) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end()) {
        return QueryResult(s, nodata, file);
    }
    else
        return QueryResult(s, loc->second, file);
}
# endif
ostream &print(ostream &out, const QueryResult &qr) {  //没带const会报错： candidate function not viable: expects an l-value
    out << qr.sought << "occours" << qr.lines->size() << " times" << endl;
    for (auto num : *(qr.lines))
        out << "\t(line" << num + 1 << ")" << *(qr.file->begin() + num) << endl;
    return out;
}