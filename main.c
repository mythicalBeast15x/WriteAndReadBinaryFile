#include <stdio.h>
#include <string.h>
#include "binaryFile.h"
void writeToBinary(struct Message *message){
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(message->name, sizeof(message->name), 1, file);
    fwrite(message->sender, sizeof(message->sender), 1, file);
    fwrite(message->receiver, sizeof(message->receiver), 1, file);
    fclose(file);

}
int main() {
    struct Message message;
    strcpy(message.name, "Hello Syed");
    strcpy(message.sender, "Love");
    strcpy(message.receiver, "Syed");
    writeToBinary(&message);
    return 0;
}
