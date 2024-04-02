/*
CMPSC 472 Spring 2024
Name: Mansib Syed Ahmed
Partner: Love Divine Onwulata
Lab: Read & Write Binary Files
This program writes data from a struct defined the .h file to a binary file.
Then, the program reads the data from binary file using the struct and displays it.
*/

#include <stdio.h>
#include <string.h>
#include "binaryFile.h"

void writeToBinary(struct Message *message) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(message->name, sizeof(message->name), 1, file);
    fwrite(message->sender, sizeof(message->sender), 1, file);
    fwrite(message->receiver, sizeof(message->receiver), 1, file);
    fwrite(&message->x, sizeof(int), 1, file);
    fwrite(&message->y, sizeof(int), 1, file); 
    fclose(file);
}

void readBinaryFile(char *filename) {
    FILE *file = fopen(filename, "rb");
    struct Message message;

    if (!file) {
        perror("Error opening file");
        return;
    }

    fread(message.name, sizeof(message.name), 1, file);
    fread(message.sender, sizeof(message.sender), 1, file);
    fread(message.receiver, sizeof(message.receiver), 1, file);
    fread(&message.x, sizeof(int), 1, file);
    fread(&message.y, sizeof(int), 1, file);

    fclose(file);

    printf("Displaying data in binary file %s\n", filename);
    printf("Message name: %s\n", message.name);
    printf("Message sender: %s\n", message.sender);
    printf("Message receiver: %s\n", message.receiver);
    printf("Messsage size: %d\n", message.x);
    printf("Message num: %d\n", message.y);
}

int main() {
    struct Message message;
    strcpy(message.name, "Hello Syed");
    strcpy(message.sender, "Love");
    strcpy(message.receiver, "Syed");
    message.x = 10;
    message.y = 5;
    writeToBinary(&message);
    readBinaryFile(FILENAME);
    return 0;
}