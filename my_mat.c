#include"my_mat.h"

#define size 10

void take_values(int Neighborhood_matrix[size][size])
{
	for(int i=0;i<size;i++)
		
		for(int j=0;j<size;j++)
		{
			printf("\nEnter Value Of Cell (%d , %d): ",i,j);
			scanf("%d",&Neighborhood_matrix[i][j]);
		}
				
	return;
}

bool Route_exist(int Neighborhood_matrix[size][size], int src, int dest)
{
	
	int distance[size];
        bool Visited[size]; 
	int min_index=0;
    
    cleaning_matrix(distance, Visited, src);
    
	apply_dijkstra(distance, Visited, Neighborhood_matrix);
   	
	for (int i = 0; i < size; i++)
    	
		if (i == dest)
        	
			if (distance[i] != 0 && distance[i]!= INT_MAX)
			return 1;
			else
			return 0;	
	
}


int Cal_minDistance(bool Visited[], int distance[], int min_index, int min)
{
 
	for (int i = 0; i < size; i++)
        
		if (distance[i] <= min && Visited[i] == false)
		{
            min = distance[i];
			min_index = i;	   
		}
    
    Visited[min_index] = true;
    return min_index;
}

void cleaning_matrix(int distance[], bool Visited[], int src)
{
	for (int i = 0; i < size; i++)
    {
        Visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[src] = 0;
	return;
}
 

void apply_dijkstra(int distance[], bool Visited[], int Neighborhood_matrix[size][size])
{
	for (int n = 0; n < size - 1; n++) 
	{
       
	    int min_index = Cal_minDistance(Visited, distance, 0, INT_MAX);
        
		for (int i = 0; i < size; i++)
            if (!Visited[i] && Neighborhood_matrix[min_index][i] && distance[min_index] 
			!= INT_MAX && distance[min_index] + Neighborhood_matrix[min_index][i] < distance[i])
			   distance[i] = (distance[min_index] + Neighborhood_matrix[min_index][i]);
    }
    return;
}


void calculate_shortest_path(int Neighborhood_matrix[size][size], int src, int dest)
{
	int distance[size];
    bool Visited[size]; 
	int min_index=0;
    
    cleaning_matrix(distance, Visited, src);
    
	apply_dijkstra(distance, Visited, Neighborhood_matrix);
   	
	for (int i = 0; i < size; i++)
    	
		if (i == dest)
        	
			if (distance[i] != 0 && distance[i]!= INT_MAX)
				printf("%d --> %d : %d\n", src, dest, distance[i]);
			else
				printf("%d -x-> %d : %d\n", src, dest, -1);	
    
	return;    
}


void Exit()
{
	exit(0);
}

void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
