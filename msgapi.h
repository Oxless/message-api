#ifndef SPO_SERVER_MSGAPI_H
#define SPO_SERVER_MSGAPI_H

#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "datatype.h"
#include <cstring>
#include <vector>
#include <sstream>

int openQueue(key_t token) {
    int qid = msgget(token, IPC_CREAT | PERM);
    if(qid < 0) {
        std::cout << "Queue error" << std::endl;
        return 1;
    }
    return qid;
}

void readMessage(int qid, Packet *packet) {
    int result = msgrcv(qid, packet, sizeof(struct Packet) - sizeof(long), packet->mtype, 0);
    if(result < 0) {
        std::cout << "Read error" << std::endl;
        return;
    }
}

void sendMessage(int qid, Packet *packet) {
    int result = msgsnd(qid, packet, sizeof(struct Packet) - sizeof(long), 0);
    if(result < 0) {
        std::cout << "Send error" << std::endl;
        return;
    }
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

#endif //SPO_SERVER_MSGAPI_H
