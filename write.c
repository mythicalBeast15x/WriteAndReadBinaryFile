/*
CMPSC 472 Spring 2024
Name: Mansib Syed Ahmed
Partner: Love Divine Onwulata
Lab: Write Binary Files (Written by Love)
This program writes data from a struct defined the .h file to a binary file.
*/

#include <stdio.h>
#include <string.h>
#include "binaryFile.h"

void writeToBinary(struct Message *message)
{
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
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

int main()
{
    struct Message message;
    strcpy(message.name, "Hello World!!!");
    strcpy(message.sender, "Love");
    strcpy(message.receiver, "Syed");
    message.x = 10;
    message.y = 5;
    writeToBinary(&message);
    return 0;
}