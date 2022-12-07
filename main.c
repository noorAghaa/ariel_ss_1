#include "my_mat.h"

int main() {
	int i,j;
	char input = '\0';
	int Neighborhood_matrix [10][10];

	while(1)
	{

		system("clear");
		printf("A - Perform function #1\n");
		printf("B - Perform function #2\n");
		printf("C - perform function #3\n");
		printf("D - Exit the program\n");
		
		fflush(stdin);
		scanf("%c",&input);
		

		switch (input)
		{
		    case 'A':
		    	fflush(stdin);
		      	take_values(Neighborhood_matrix);
		      	printf("\nValues entered successfully\n");
		      	clean_stdin();
		      	sleep(2);
		      break;
		
		    case 'B':
		    	fflush(stdin);
		    	printf("\nEnter the i & j value of cell(i,j)\n");
		    	printf("\nEnter value of i: ");
		    	scanf("%d",&i);
		    	printf("\nEnter value of j: ");
		    	scanf("%d",&j);
		      	if (Route_exist(Neighborhood_matrix, i, j) == 1)
		      		printf("\nTrue\n");
		      	else
		      		printf("\nFalse\n");
		      	
				printf("\nPress any key to continue\n");
				clean_stdin();
				getchar();
		      break;
		    
			case 'C':
				fflush(stdin);
				printf("\nEnter the i & j value of cell(i,j)\n");
		    	printf("\nEnter value of i: ");
		    	scanf("%d",&i);
		    	printf("\nEnter value of j: ");
		    	scanf("%d",&j);
		      	calculate_shortest_path(Neighborhood_matrix, i, j);
			printf("\nPress any key to continue\n");
				clean_stdin();
				getchar();
		  	  break;
			
			case 'D':
		  	  Exit();
		    
			default:				
		      printf("Please enter appropriate input\n");
		      sleep(1);
		      break;
		}
	}
	
	return 0;
}
