#include<stdio.h>
#include<stdbool.h>

// Number of vertices in the graph
#define Vertex 4

void printSolution(int VertexColor[]);

//check if the VertexColored graph is safe or not
bool isSafe (bool graph[Vertex][Vertex], int VertexColor[])
{
	// Check coloring safety.
	for (int i = 0; i < Vertex; i++)
		for (int j = i + 1; j < Vertex; j++)
		if (graph[i][j] && VertexColor[j] == VertexColor[i])
			return false;
	return true;
}


/* This function solves the m Coloring problem using recursion. It returns
false if the m colors cannot be assigned, otherwise return true and
prints assignments of colors to all vertices. Please note that there
may be more than one solutions, this function prints one of the
feasible solutions.*/
bool graphColoring(bool graph[Vertex][Vertex], int m, int i, int VertexColor[Vertex])
{
	//if current index reached end
	if(i==Vertex)
	{
		//if coloring is safe
		if(isSafe(graph,VertexColor))
		{
			// Print the solution
			printSolution(VertexColor);
			return true;
		}
		return false;
	}

	//assign each color from 1 to m
	for(int j=1; j<=m; j++)
	{
		VertexColor[i]=j;

		//recur of the rest vertices
		if(graphColoring(graph,m,i+1,VertexColor))
			return true;

		VertexColor[i]=0;
	}

	return false;
}

/* A utility function to print solution */
void printSolution(int VertexColor[])
{
	printf("Solution Exists:"
			" Following are the assigned colors \n");
	for (int i = 0; i < Vertex; i++)
	printf(" %d ", VertexColor[i]);
	printf("\n");
}

// driver program to test above function
int main()
{
	/* Create following graph and test whether it is 3 colorable
	(3)---(2)
	| /    |
	| /    |
	| /    |
	(0)---(1)
	*/
	bool graph[Vertex][Vertex] = {
	    //G1
	    {0 , 1 , 2 , 2},
	    //G2
		{0 , 1, 2 ,0},
		//G3
		{0 , 1, 1, 2 },
		//G4
		{0 , 1, 1, 0}
	};
	int m = 3; // Number of colors

	// Initialize all color values as 0. This initialization is needed
	// correct functioning of isSafe()
	int VertexColor[Vertex];
	for (int i = 0; i < Vertex; i++)
	VertexColor[i] = 0;

	if(!graphColoring (graph, m, 0, VertexColor))
		printf("Solution does not exist");

	return 0;
}
