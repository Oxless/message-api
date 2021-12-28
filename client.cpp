#include <iostream>
#include "msgapi.h"

int main() {
    key_t token = ftok("server", 1);
    int qid = openQueue(token);
    Packet packet;
    strcpy(packet.data, "test message");
    sendMessage(qid, &packet);
    Packet response;
    readMessage(qid, &response);
    std::cout << response.data << std::endl;
}
