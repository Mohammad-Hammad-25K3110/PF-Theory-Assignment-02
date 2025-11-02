#include <stdio.h>

void encodeMessage(char message[100], int messageSize){
    for (int i = 0; i < messageSize / 2; i++){
        char temp = message[i];
        message[i] = message[messageSize - 1 - i];
        message[messageSize - 1 - i] = temp;
    }
    for (int i = 0; i < messageSize; i++){
        message[i] ^= (1 << 1);
        message[i] ^= (1 << 4);
    }
}

void decodeMessage(char message[100], int messageSize){
    for (int i = 0; i < messageSize; i++){
        message[i] ^= (1 << 1);
        message[i] ^= (1 << 4);
    }
    for (int i = 0; i < messageSize / 2; i++){
        char temp = message[i];
        message[i] = message[messageSize - 1 - i];
        message[messageSize - 1 - i] = temp;
    }
}

int main() {
    char message[100];
    int input, messageSize;
    do {
        printf("\nEnter \"1\" to Encode Message\n");
        printf("Enter \"2\" to Decode Message\n");
        printf("Enter \"3\" to Exit\n");
        printf("Input : ");
    	scanf("%d", &input);
        if (input == 1 || input == 2) {
            printf("Enter your message : ");
            scanf(" %[^\n]", message);
            messageSize = 0;
            while(message[messageSize] != '\0') {
                messageSize++;
            }
            if (input == 1){
                encodeMessage(message, messageSize);
                printf("Encoded Message: ");
            } 
			else if (input == 2){
                decodeMessage(message, messageSize);
                printf("Decoded Message: ");
            }
            for (int i = 0; i < messageSize; i++){
                printf("%c", message[i]);
            }
            printf("\n");
        } 
		else if (input == 3){
			break;
        } 
		else{
            printf("INVALID INPUT!\n");
        }
    }
	while(input != 3);
    return 0;
}

