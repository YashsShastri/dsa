#include <iostream>
#include <iomanip>
#include <string.h>
#include <set>
#define SIZE 6

using namespace std;

class Graph
{
    private:
        string cities[SIZE];
        int adj_mat[SIZE][SIZE];
    
    public:
        Graph(){}

	void prims_shortest_path(int index)
	{
		if(index > SIZE)
            return;
        int count = 1, total_min = 0;
        int min, src_vertex, dest_vertex;
        bool visited[SIZE];
        set<int> vec_visited = set<int>();
        memset(visited, false, sizeof(visited)); // initializing visited to false
        
        //inserting 1st element;
        vec_visited.insert(index);
        visited[index] = true;
        
        while(count < SIZE)
        {
            min = 999;
            for(int i : vec_visited)
            {
                for(int j = 0; j < SIZE; ++j)
                {
                    if(i == j || visited[j]) continue;
                    if(adj_mat[i][j] < min)
                    {
                        min = adj_mat[i][j];
                        src_vertex = i;
                        dest_vertex = j;
                    }
                }
            }
            total_min += min;
            visited[dest_vertex] = true;
            vec_visited.insert(dest_vertex);
            cout << "Going From " << cities[src_vertex] << " - " << cities[dest_vertex] << endl;
            count++;     
        }
        cout << "Shortest_path = " << total_min << endl;
	} 

    void get_routes()
    {
        for(int i = 0; i < SIZE; ++i)
        {
            cout << "Enter city-"<< i+1 << " : ";
            cin >> cities[i];
        }
        
        cout << "\nIf no connectivity then Cost = '0'." << endl;
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = i + 1; j < SIZE; j++)
            {
                cout << cities[i] << "->" << cities[j] << " : ";
                cin >> adj_mat[i][j];
                if(adj_mat[i][j] == 0) adj_mat[i][j] = adj_mat[j][i] = adj_mat[i][i] = 999;
                else adj_mat[j][i] = adj_mat[i][j];
            }
        }
    }

    void show_chart()
    {
        cout << "\n--------------------------------------------------------\n";
        cout << setw(10) << "|";
        for(int i = 0; i < SIZE; ++i)
            cout << setw(cities[i].length()+2) << cities[i] << "|";
        cout << "\n--------------------------------------------------------";
        for(int i = 0; i < SIZE; ++i)
        {
            cout << "\n" << setw(9) << cities[i] << "|";
            for(int j = 0; j < SIZE; ++j)
                cout << setw(cities[j].length()+2) << adj_mat[i][j] << "|";
        }
        cout << endl;
    }
};

int main()
{
    Graph G1;
    G1.get_routes();
    G1.show_chart();
    G1.prims_shortest_path(0);
    cout << endl;
    return 0;
}

/*
Enter city-1 : Miami
Enter city-2 : Seattle
Enter city-3 : Buffalo
Enter city-4 : Manhattan
Enter city-5 : NewYork
Enter city-6 : Washington

If no connectivity then Cost = '0'.
Miami->Seattle : 12
Miami->Buffalo : 8
Miami->Manhattan : 0
Miami->NewYork : 0
Miami->Washington : 0
Seattle->Buffalo : 9
Seattle->Manhattan : 0
Seattle->NewYork : 22
Seattle->Washington : 11
Buffalo->Manhattan : 0
Buffalo->NewYork : 16
Buffalo->Washington : 14
Manhattan->NewYork : 15
Manhattan->Washington : 3
NewYork->Washington : 18

--------------------------------------------------------
         |  Miami|  Seattle|  Buffalo|  Manhattan|  NewYork|  Washington|
--------------------------------------------------------
    Miami|    999|       12|        8|        999|      999|         999|
  Seattle|     12|      999|        9|        999|       22|          11|
  Buffalo|      8|        9|      999|        999|       16|          14|
Manhattan|    999|      999|      999|        999|       15|           3|
  NewYork|    999|       22|       16|         15|      999|          18|
Washington|    999|       11|       14|          3|       18|        999|

Going From Miami - Buffalo
Going From Buffalo - Seattle
Going From Seattle - Washington
Going From Washington - Manhattan
Going From Manhattan - NewYork
Shortest_path = 46



*/
