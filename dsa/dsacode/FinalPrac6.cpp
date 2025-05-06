#include <iostream>
#include <iomanip>
#include <stack>
#include <string.h>
#include <queue>
#define SIZE 8

using namespace std;

class Graph
{
    private:
        string cities[SIZE]= {"A","B","C","D","E","F","G","H"};
        int adj_mat[SIZE][SIZE] = {{0,1,0,1,0,0,0,0},{0,0,1,0,0,1,0,0},{0,0,0,0,1,0,1,1},{0,0,0,0,0,1,0,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,1},{1,0,0,0,0,0,0,0}};
    
    public:
        Graph(){}

        void depth_first(int index)
        {
            stack<int> stck;
            bool visited[SIZE] = {false};
            memset(visited, false, sizeof(visited));

            stck.push(index);
            //visited[index] = true;
            while(!stck.empty())
            {
                int i = stck.top();
                stck.pop();
                cout << cities[i] << " ";
                visited[i] = true;
                for(int j = 0; j < SIZE; ++j)
                {
                    if(adj_mat[i][j] == 1 && !visited[j])
                    {
                        stck.push(j);
                        visited[j] = true;
                    }
                }
            }
        }

        void breadth_first(int index)
        {
            queue<int> que;
            bool visited[SIZE];
            memset(visited, false, sizeof(visited));

            que.push(index);
            while(!que.empty())
            {
                index = que.front();
                que.pop();
                cout << cities[index] << " ";
                visited[index] = true;
                for(int j = 0; j < SIZE; j++)
                    if(adj_mat[index][j] == 1 && !visited[j])
                    {
                        que.push(j);
                        visited[j] = true;
                    }
            }
        }

        void get_routes()
        {
            for(int i = 0; i < SIZE; ++i)
            {
                cout << "Enter city-"<< i+1 << " : ";
                cin >> cities[i];
            }
            
            cout << "If no flight then '0'." << endl;
            for(int i = 0; i < SIZE; i++)
            {
                for(int j = i + 1; j < SIZE; j++)
                {
                    cout << cities[i] << "->" << cities[j] << " : ";
                    cin >> adj_mat[i][j];
                    adj_mat[j][i] = adj_mat[i][j];
                }
            }
        }

        void show_chart()
        {
            // string cities[5] = {"Nashik", "Pune", "Mumbai", "Kolhapur", "Udaipur"};
            // int adj_mat[5][5] = {{1,2,3,4,5},{2,3,4,5,1},{1,0,3,1,2},{1,3,6,7,4},{2,6,4,1,0}};  
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

struct Node
{
    string city;
    int time;
    Node* next = nullptr;
    
    Node() { city = ""; }
    Node(string cityy, int timee) { city = cityy; time = timee;}
};
class ListGraph
{
    private:
        Node* cities[SIZE];
    
    public:
        ListGraph()  
        {
            for(int i = 0; i < SIZE; i++)
                cities[i] = nullptr;
        }

        void get_routes()
        {
            int timee;
            string cityy;
            for(int i = 0; i < SIZE; ++i)
            {
                cout << "Enter city-"<< i+1 << " : ";
                cin >> cityy;
                cities[i] = new Node(cityy, 0);
            }
            
            cout << "\nIf no flight then '0'." << endl;
            for(int i = 0; i < SIZE; i++)
            {
                for(int j = i + 1; j < SIZE; j++)
                {
                    cout << cities[i]->city << "->" << cities[j]->city << " : ";
                    cin >> timee;
                    if(timee <= 0) 
                        continue;
                    insert(i, new Node(cities[j]->city, timee));
                    insert(j, new Node(cities[i]->city, timee));
                }
            }
        }

        void insert(int index, Node* node)
        {
            Node *temp = cities[index];
            while(temp->next != nullptr)
                temp = temp->next;
            temp->next = node;
        }

        void show_chart()
        {
            Node *temp;
            cout << "\n\n\n";
            for(int i = 0; i < SIZE; i++)
            {
                temp = cities[i];
                while(temp != NULL)
                {
                    cout << temp->city << "->";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main()
{
    // ListGraph G2;
    // G2.get_routes();
    // G2.show_chart();
    Graph G1;
    G1.show_chart();
    G1.depth_first(7);
    cout << endl;
    G1.breadth_first(7);
    return 0;
}

/*
Enter city-1 : Nashik
Enter city-2 : Pune
Enter city-3 : Mumbai
Enter city-4 : Bangalore
Enter city-5 : Delhi

If no flight then '0'.
Nashik->Pune : 1
Nashik->Mumbai : 2
Nashik->Bangalore : 0
Nashik->Delhi : 0
Pune->Mumbai : 4
Pune->Bangalore : 3
Pune->Delhi : 0
Mumbai->Bangalore : 8
Mumbai->Delhi : 0
Bangalore->Delhi : 2


Nashik->Pune->Mumbai->

Pune->Nashik->Mumbai->Bangalore->

Mumbai->Nashik->Pune->Bangalore->

Bangalore->Pune->Mumbai->Delhi->

Delhi->Bangalore->

*/