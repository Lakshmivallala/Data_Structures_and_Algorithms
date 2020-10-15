#include <iostream>
using namespace std;
#define VERTICES 9

int minVerticeLength(int DistanceArray[], bool TruthValueArray[])
{
    int Minimum = __INT_MAX__, min_index;
    for (int CurrentVertice = 0; CurrentVertice < VERTICES; CurrentVertice++)
    {
        if (TruthValueArray[CurrentVertice] == false && DistanceArray[CurrentVertice] <= Minimum)
        {
            Minimum = DistanceArray[CurrentVertice], min_index = CurrentVertice;
        }
    }
    return min_index;
}

int printSolution(int DistanceArray[])
{
    std::cout << "Vertex \t\t DistanceArrayance from source" << std::endl;
    for (int i = 0; i < VERTICES; i++)
    {
        std::cout << i << " \t\t " << DistanceArray[i] << std::endl;
    }
    return 0;
}

int dijkstraAlgorithm(int Graph[VERTICES][VERTICES], int SourceNode)
{
    int DistanceArray[VERTICES];
    bool TruthValueArray[VERTICES];
    for (int i = 0; i < VERTICES; i++)
    {
        DistanceArray[i] = __INT_MAX__, TruthValueArray[i] = false;
    }
    DistanceArray[SourceNode] = 0;
    for (int count = 0; count < VERTICES - 1; count++)
    {
        int LOC1 = minVerticeLength(DistanceArray, TruthValueArray);
        TruthValueArray[LOC1] = true;
        for (int LOC2 = 0; LOC2 < VERTICES; LOC2++)
        {
            if (!TruthValueArray[LOC2] && Graph[LOC1][LOC2] && DistanceArray[LOC1] != __INT_MAX__ && DistanceArray[LOC1] + Graph[LOC1][LOC2] < DistanceArray[LOC2])
            {
                DistanceArray[LOC2] = DistanceArray[LOC1] + Graph[LOC1][LOC2];
            }
        }
    }
    printSolution(DistanceArray);
    return 0;
}

int main()
{
    int Graph[VERTICES][VERTICES] = {{1, 7, 0, 2, 0, 0, 0, 0, 0},
                                     {4, 0, 8, 0, 0, 0, 0, 1, 0},
                                     {0, 8, 0, 0, 6, 5, 0, 9, 2},
                                     {0, 0, 13, 0, 9, 2, 0, 6, 0},
                                     {0, 0, 2, 9, 0, 10, 0, 0, 0},
                                     {0, 7, 0, 4, 10, 0, 2, 0, 0},
                                     {4, 9, 0, 0, 0, 23, 0, 1, 6},
                                     {2, 1, 0, 0, 0, 2, 1, 0, 7},
                                     {0, 0, 3, 0, 0, 5, 0, 7, 0}};

    dijkstraAlgorithm(Graph, 0);
    return 0;
}
