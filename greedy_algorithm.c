#include <iostream>
#include <list>
using namespace std;

class GraphColoring
{
    int VertexNumber;    // No. of vertices
    list<int> *Adjacent;    // A dynamic array of adjacency lists
public:
    GraphColoring(int VertexNumber)   { this->VertexNumber = VertexNumber; Adjacent = new list<int>[VertexNumber]; }
    ~GraphColoring()       { delete [] Adjacent; }

    void addEdge(int v, int w);

    void greedyColoring();
};

void GraphColoring::addEdge(int v, int w)
{
    Adjacent[v].push_back(w);
    Adjacent[w].push_back(v);  // Note: the graph is undirected
}

// Assigns colors (starting from 0) to all vertices and prints

void GraphColoring::greedyColoring()
{
    int result[VertexNumber];

    // Assign the first color to first vertex
    result[0]  = 0;

    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < VertexNumber; u++)
        result[u] = -1;  // no color is assigned to u

    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[VertexNumber];
    for (int VertexColor = 0; VertexColor < VertexNumber; VertexColor++)
        available[VertexColor] = false;

    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < VertexNumber; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        list<int>::iterator i;
        for (i = Adjacent[u].begin(); i != Adjacent[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        // Find the first available color
        int VertexColor;
        for (VertexColor = 0; VertexColor < VertexNumber; VertexColor++)
            if (available[VertexColor] == false)
                break;

        result[u] = VertexColor; // Assign the found color

        // Reset the values back to false for the next iteration
        for (i = Adjacent[u].begin(); i != Adjacent[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }

    // print the result
    for (int u = 0; u < VertexNumber; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}

// Driver program to test above function
int main()
{
    GraphColoring g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    cout << "Coloring of graph 1 \n";
    g1.greedyColoring();

    return 0;
}
