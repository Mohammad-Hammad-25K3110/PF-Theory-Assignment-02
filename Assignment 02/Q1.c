#include <stdio.h>

void addBook(int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *numBooks){
    char title[50];
    int isbn, quantity, duplicate = 0;
    float price;
    if (*numBooks >= 100) {
        printf("\nInventory is full!\n");
        return;
    }
    printf("\nEnter Book ISBN : ");
    scanf("%d", &isbn);
    printf("Enter Book Title : ");
    scanf(" %[^\n]", title);
    printf("Enter Book Price : ");
    scanf("%f", &price);
    printf("Enter Book Quantity : ");
    scanf("%d", &quantity);
    for(int i = 0; i < *numBooks; i++){
        if(isbns[i] == isbn){
            duplicate = 1;
            break;
        }
    }
    if(duplicate){
        printf("The book is already added (Duplicate ISBN)!\n\n");
        return;
    }
    int j = 0;
    while (title[j] != '\0' && j < 49) {
        titles[*numBooks][j] = title[j];
        j++;
    }
    titles[*numBooks][j] = '\0';
    isbns[*numBooks] = isbn;
    prices[*numBooks] = price;
    quantities[*numBooks] = quantity;
    (*numBooks)++;
    printf("Book added successfully!\n\n");
}

void processSale(int isbns[100], int quantities[100], int *numBooks){
    int isbn, quantity, found = 0;
    printf("\nEnter ISBN of Book sold : ");
    scanf("%d", &isbn);
    printf("Enter Quantity of Book sold : ");
    scanf("%d", &quantity);
    for(int i = 0; i < *numBooks; i++){
    	if(isbns[i] == isbn){
    		if(quantities[i] >= quantity){
    			quantities[i] -= quantity;
    			printf("SUCCESSFUL SALE!\n\n");
			}
			else{
				printf("OUT OF STOCK!\n\n");
			}
    		found = 1;
    		break;
		}
	}
	if(!found)printf("Book Not Found!\n\n");
}

void genLowstockReport(int isbns[100], char titles[100][50], float prices[100], int quantities[100], int *numBooks){
    printf("\n------Low-Stock Report------\n");
	for(int i = 0; i < *numBooks; i++){
    	if(quantities[i] < 5){
    		printf("BOOK %d\n", i+1);
    		printf("Book ISBN : %d\n", isbns[i]);
    		printf("Book Title : ");
    		int j = 0;
    		while(titles[i][j] != '\0'){
    			printf("%c", titles[i][j]);
    			j++;
			}
    		printf("\nBook Price : %f\n", prices[i]);
    		printf("Book Quantity : %d\n\n", quantities[i]);
		}
	}
}

int main(){
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int numBooks = 0; 
    int input;
    do{
	    printf("Enter \"1\" to Add New Book\n");
	    printf("Enter \"2\" to Process a Sale\n");
	    printf("Enter \"3\" to Generate Low-Stock Report\n");
	    printf("Enter \"4\" to Exit\n");
	    printf("INPUT : ");
	    scanf("%d", &input);
	    switch(input){
	        case 1: 
	            addBook(isbns, titles, prices, quantities, &numBooks);
	            break;
	        case 2: 
				processSale(isbns, quantities, &numBooks);
	        	break;
			case 3:
				genLowstockReport(isbns, titles, prices, quantities, &numBooks);
				break;
			case 4:
				break;
	        default:
	            printf("INVALID INPUT!\n");
	    }
	}
	while(input != 4);
    return 0;
}

