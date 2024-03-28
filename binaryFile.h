
#ifndef WRITEBINARYFILE_BINARYFILE_H
#define WRITEBINARYFILE_BINARYFILE_H
#define MAX_NAME_LENGTH 50
typedef struct{
    char name[MAX_NAME_LENGTH];
    char sender[MAX_NAME_LENGTH];
    char receiver[MAX_NAME_LENGTH];

} Message;
#endif //WRITEBINARYFILE_BINARYFILE_H
