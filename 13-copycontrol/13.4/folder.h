#include <set>
class Message;
class Folder {
public:
    Folder()=default;
    Folder(const Folder& f) : ct_message(f.ct_message) {} 
    Folder& operator=(const Folder&);
    void addmsg(Message*);
    void rmmsg(Message*);
    std::set<Message*> printms();
    ~Folder()=default;
private:
    std::set<Message*> ct_message;
};