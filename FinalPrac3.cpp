#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
	int flag;
	char title[30];
	Node* down;
	Node* next;
	
	Node()
	{
		flag = 0;
		strcpy(title, "");
		down = nullptr;
		next = nullptr;
	}
	
	Node(char titl[])
	{
		flag = 0;
		strcpy(title, titl);
		down = nullptr;
		next = nullptr;
	}
};

class GeneralizedLinkedList
{
	private:
		Node *root;
		
	public:
		GeneralizedLinkedList(char titl[30])
		{
			root = new Node(titl);
		}
		char* getTitle()
		{
			return root->title;
		}
		Node* getSection(char titl[30])
		{
			Node *temp = root->down;
			while(temp != NULL)
			{
				if(strcmp(temp->title, titl) == 0)
					return temp;
				temp = temp->next;
			}
			return NULL;
		}
		Node* create_node(string title)
		{
			char titl[30];
			cout << "Enter " << title << " Title: ";
			cin.getline(titl, 30);
			Node *newnode = new Node(titl);
			return newnode;
		}
		
		void add_section(Node *section_root = NULL)
		{
			string titlee;
			if(section_root == NULL && root == NULL)
			{
				cout << "Not Found";
				return;
			}
			section_root = (section_root == NULL) ? root : section_root;
			titlee = (section_root == root) ? "Section" : "SubSection";
			Node *sect = create_node(titlee);
			if(section_root->flag == 0) {
				section_root->down = sect;
				section_root->flag = 1;
			}
			else {
				Node *temp = section_root->down;
				while(temp->next != nullptr)
					temp = temp->next;
				temp->next = sect;
			}
			cout << "Successfully Added." << endl;
		}
		
		void display()
		{
			Node *temp = root;
			Node *subsection;
			Node *section;
			cout << "\n";
			cout << "Title = " << temp->title <<endl;
			section = temp->down;
			while(section != NULL)
			{
				cout << "\t";
				cout << "Section = " << section->title << endl;
				subsection = section->down; 
				while(subsection != NULL)
				{
					cout << "\t\t";
					cout << "Subsection = " << subsection->title << endl;
					subsection = subsection->next;
				}				
				section = section->next;
			}	
		}
	
};

int main()
{
	GeneralizedLinkedList *gl[10] = {nullptr};
	GeneralizedLinkedList *gll;
	char bookname[30];
	char section_name[30];
	int ch = 0;
	int index = 0;
	Node *temp;
	do
	{
		cout << "\n\n1. Create Book" << endl;
		cout << "2. Create Section" << endl;
		cout << "3. Create Subsection" << endl;
		cout << "4. Display Book" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter Your Choice : ";
		cin >> ch;
		cin.ignore();
		switch(ch)
		{
			case 1: cout << "Enter Book Title : ";
					cin.getline(bookname, 30);
					gll = new GeneralizedLinkedList(bookname);
					gl[index] = gll;
					index++;
					cout << "Book Created." << endl;
					break;
			case 2: cout << "Enter Book Name in which to be added : ";
					cin.getline(bookname, 30);
					for(int i = 0; i < 5; ++i)
					{
						if(gl[i] == nullptr)
						{
							cout << "Unable to find Book" << endl;
							break;
						}	
						if(strcmp(gl[i]->getTitle(), bookname) == 0)
						{
							gl[i]->add_section();
							break;
						}
					}
					break;
			case 3: cout << "Enter Book Name in which to be added : ";
					cin.getline(bookname, 30);
					cout << "Enter Section Title : ";
					cin.getline(section_name, 30);
					for(int i = 0; i < 5; ++i)
					{
						if(gl[i] == nullptr)
						{
							cout << "Unable to find Book";
							break;
						}	
						if(strcmp(gl[i]->getTitle(), bookname) == 0)
						{
							temp = gl[i]->getSection(section_name);
							if(temp != NULL)
							{
								gl[i]->add_section(temp);
								break;
							}
							cout << "No Found";
							break;
						}
					}
					break;
			case 4: for(int i = 0; i < index; ++i)
						gl[i]->display();
					break;
			case 0: exit(0);
					break;
			default:cout << "Invalid Input" << endl;
		}
	}while(ch != 0);
	return 0;
}

/*
1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 1
Enter Book Title : Harry Potter
Book Created.


1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 2
Enter Book Name in which to be added : Harry Potter
Enter Section Title: Phase-1
Successfully Added.


1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 2
Enter Book Name in which to be added : Harry Potter
Enter Section Title: Phase-2
Successfully Added.


1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 3
Enter Book Name in which to be added : Harry Potter
Enter Section Title : Phase-1
Enter SubSection Title: Introduction
Successfully Added.


1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 1
Enter Book Title : Jungle Book
Book Created.


1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 2
Enter Book Name in which to be added : Jungle Book
Enter Section Title: Mowgli
Successfully Added.


1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 4

Title = Harry Potter
        Section = Phase-1
                Subsection = Introduction
        Section = Phase-2

Title = Jungle Book
        Section = Mowgli


1. Create Book
2. Create Section
3. Create Subsection
4. Display Book
0. Exit
Enter Your Choice : 0
*/