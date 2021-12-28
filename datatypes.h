#ifndef SPO_SERVER_DATATYPE_H
#define SPO_SERVER_DATATYPE_H

#define PERM 0666
#define RESERVOIRS_AMOUNT 4

struct Packet {
    long mtype = 1L;
    char data[256];
};

#endif //SPO_SERVER_DATATYPE_H
