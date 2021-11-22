#include <string>
#include <set>
class Folder;
class Message {
friend void swap(Message& lhs, Message &rhs);
public:
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    std::set<Folder*> printallfolders(){ return folders; }
    std::string printcontents() { return contents; }

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_folders(const Message&);
    void remove_from_folders();
};
inline void swap(Message&lhs, Message &rhs);