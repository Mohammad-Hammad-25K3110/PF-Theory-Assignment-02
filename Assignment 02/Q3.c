#include <stdio.h>

void updateSector(int r, int c, int grid[r][c], int row, int col, int flag, int set) {
    if(set){
        grid[row][col] |= (1 << flag);
    } 
	else{
        grid[row][col] &= ~(1 << flag);
    }
}

void querySector(int r, int c, int grid[r][c], int row, int col){
    int status = grid[row][col];
    printf("\n\nSector (%d, %d) Status:\n", row, col);
    printf("Power: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload Warning: %s\n", (status & 2) ? "Yes" : "No");
    printf("Maintenance Required: %s\n", (status & 4) ? "Yes" : "No");
}

void runDiagnostic(int r, int c, int grid[r][c]){
    int overloaded = 0;
    int maintenance = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] & 2) overloaded++;
            if(grid[i][j] & 4) maintenance++;
        }
    }
    printf("\nTotal sectors overloaded: %d\n", overloaded);
    printf("Total sectors that require maintenance: %d\n", maintenance);
}

int main(){
    int r = 3, c = 3;
    int grid[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            grid[i][j] = 0;
		}
	}
    int input, row, col, flag, set;
    printf("GRID IS 3x3\n");
	do{
        printf("\nEnter \"1\" to Update Sector Status\n");
        printf("Enter \"2\" to Query Sector Status\n");
        printf("Enter \"3\" to Run System Diagnostic\n");
        printf("Enter \"4\" to Exit\n");
        printf("Input: ");
        scanf("%d", &input);
        switch(input){
            case 1:{
                printf("\nEnter sector row : ");
                scanf("%d", &row);
                printf("Enter sector column : ");
                scanf("%d", &col);
                if(row < 0 || row >= r || col < 0 || col >= c){
                    printf("Invalid coordinates!\n");
                    break;
                }
                printf("Enter flag to update [0=Power, 1=Overload, 2=Maintenance]: ");
                scanf("%d", &flag);
                if(flag < 0 || flag > 2){
                    printf("Invalid flag!\n");
                    break;
                }
                printf("Set or Clear? [1=Set, 0=Clear] : ");
                scanf("%d", &set);
                updateSector(r, c, grid, row, col, flag, set);
                printf("Sector updated successfully.\n");
                break;
			}
            case 2:{
                printf("\nEnter sector row : ");
                scanf("%d", &row);
                printf("Enter sector column : ");
                scanf("%d", &col);
                if(row < 0 || row >= r || col < 0 || col >= c){
                    printf("Invalid coordinates!\n");
                    break;
                }
                querySector(r, c, grid, row, col);
                break;
			}
            case 3:{
                runDiagnostic(r, c, grid);
                break;
			}
            case 4:{
                break;
			}
            default:
                printf("INVALID INPUT!\n");
        }
    }while(input != 4);
    return 0;
}


