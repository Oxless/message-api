#include <iostream>
#include "msgapi.h"

int main() {
    key_t token = ftok("server", 1);
    int qid = openQueue(token);
    Packet packet;
    readMessage(qid, &packet);
    std::cout << "Received: " << response.data << std::endl;
    Packet answer;
    strcpy(answer.data, "server answer");
    sendMessage(qid, &answer);
}
