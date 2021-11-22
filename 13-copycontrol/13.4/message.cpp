#include "message.h"
#include "folder.h"
void Message::save(Folder& f) {
    folders.insert(&f);
    f.addmsg(this);
}

void Message::remove(Folder& f) {
    folders.erase(&f);
    f.rmmsg(this);
}

Message::Message(const Message& ms) : contents(ms.contents), folders(ms.folders) {
    add_to_folders(ms);
}

void Message::add_to_folders(const Message& ms) {
    for (auto f : ms.folders) {
        f->addmsg(this);
    }
}

void Message::remove_from_folders() {
    for (auto f : folders) {
        f->rmmsg(this);
    }
}

Message::~Message() {
    remove_from_folders();
    //剩下的就是编译器自动调用string和set的析构函数
}

Message& Message::operator=(const Message& ms) {
    //先清空等号左侧的folders
    remove_from_folders();
    contents = ms.contents;
    folders = ms.folders;
    //再添加到folders中
    add_to_folders(ms);
    return *this;
}

void swap(Message& lhs, Message& rhs) {
    using std::swap;
    for (auto f : lhs.folders) {
        f->rmmsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->rmmsg(&rhs);
    }
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    // lhs.add_to_folders(rhs);
    // rhs.add_to_folders(lhs);
    for (auto f : lhs.folders) {
        f->addmsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->addmsg(&rhs);
    }
}