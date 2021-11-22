#include"folder.h"
#include "message.h"
void Folder::addmsg(Message* ms) {
    ct_message.insert(ms);
}

void Folder::rmmsg(Message* ms) {
    ct_message.erase(ms);
}

Folder& Folder::operator=(const Folder& f) {
    for (auto ms : f.ct_message) {
        ct_message.insert(ms);
    }
    return *this;
}

std::set<Message*> Folder::printms() {
    return ct_message;
}