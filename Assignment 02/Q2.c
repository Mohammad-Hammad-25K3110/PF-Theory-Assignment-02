#include <stdio.h>

void askCustomerInfo(char customerName[50], int *customerCNIC){
	int CNIC;
	char name[50];
	printf("\nEnter Name : ");
	scanf(" %[^\n]", customerName);
	printf("Enter CNIC : ");
	scanf("%d", customerCNIC);
}

void displayInventory(char productCode[4][3], int quantity[4], int pricePerProduct[4]){
	printf("\nPRODUCT CODE  ||  QUANTITY IN STOCK  ||  PRICE PER PRODUCT\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			printf("%c", productCode[i][j]);
		}
		printf("               %d                     %d\n", quantity[i], pricePerProduct[i]); 
	}
}

int updateInventory(char productCode[4][3], int quantity[4], char code[3], int num){
	for(int i = 0; i < 4; i++){
		int match = 1;
		for(int j = 0; j < 3; j++){
		    if(code[j] != productCode[i][j]){
		        match = 0;
		        break;
		    }
		}
		if(match){
		    quantity[i] -= num;
		    return i;
		}
	}
	return -1;
}

void addItem(char productCode[4][3], int quantity[4], int pricePerProduct[4], int *cartTotal) {
    char code[3];
	int num, index;
	printf("\nEnter Product Code of Purchased Product : ");
	for(int i = 0; i < 3; i++){
		scanf(" %c", &code[i]);
	}
	printf("Enter Quantity of Purchased Product : ");
	scanf("%d", &num);
    index = updateInventory(productCode, quantity, code, num);
	if (index != -1){
        *cartTotal += num * pricePerProduct[index];
        printf("Item added successfully!\n");
    } 
	else{
        printf("Invalid product code.\n");
	}
}

void displayTotal(int cartTotal) {
    char promo[20];
    float discount;
    int match = 1;
    printf("Your total bill without discount : %d\n", cartTotal);
    printf("Do you have a promocode? (Enter code or 'no') : ");
    scanf("%s", promo);
    char correctCode[8] = {'E','i','d','2','0','2','5','\0'};
    for (int i = 0; i < 8; i++) {
        if (promo[i] != correctCode[i]) {
            match = 0;
            break;
        }
        if (promo[i] == '\0' && correctCode[i] != '\0') {
            match = 0;
            break;
        }
    }

    if (match) {
        discount = cartTotal * 0.75; 
        printf("Promocode applied successfully!\n");
        printf("Total Bill with discount : %.2f\n", discount);
    } else {
        printf("No valid promocode applied.\n");
        printf("Final Total Bill: %d\n", cartTotal);
    }
}

void showInvoice(char customerName[50], int customerCNIC, int cartTotal) {
    printf("Customer Name : %s\n", customerName);
    printf("Customer CNIC : %d\n", customerCNIC);
    displayTotal(cartTotal);
}	

int main(){
	char customerName[50], productCode[4][3] = {"001", "002", "003", "004"};
	int input, customerCNIC, quantity[4] = {50, 10, 20, 80}, pricePerProduct[4] = {100, 200, 300, 150}, cartTotal = 0;
	do{
		printf("\nEnter \"1\" to Ask Customer Info\n");
	    printf("Enter \"2\" to Display Inventory\n");
	    printf("Enter \"3\" to Update inventory\n");
	    printf("Enter \"4\" to Add item to cart\n");
	    printf("Enter \"5\" to Display total bill\n");
	    printf("Enter \"6\" to Show invoice\n");
	    printf("Enter \"7\" to Exit\n");
	    printf("INPUT : ");
	    scanf("%d", &input);
	    switch(input){
	        case 1: 
	            askCustomerInfo(customerName, &customerCNIC);
	            break;
	        case 2: 
				displayInventory(productCode, quantity, pricePerProduct);
	        	break;
			case 3:{
				char code[3];
			    int num, index;
			    printf("Enter Product Code to update : ");
			    for (int i = 0; i < 3; i++) {
			        scanf(" %c", &code[i]);
			    }
			    printf("Enter Quantity : ");
			    scanf("%d", &num);
			    index = updateInventory(productCode, quantity, code, num); 
			    if (index != -1) {
			        printf("Inventory updated successfully!\n");
			    } else {
			        printf("Invalid product code.\n");
			    }
				break;
			}
			case 4:
				addItem(productCode, quantity, pricePerProduct, &cartTotal);
				break;
			case 5:
				displayTotal(cartTotal);
				break;
			case 6:
				showInvoice(customerName, customerCNIC, cartTotal);
    			break;
    		case 7:
    			break;
	        default:
	            printf("INVALID INPUT!\n");
	    }
	}
	while(input != 7);
    return 0;
}
