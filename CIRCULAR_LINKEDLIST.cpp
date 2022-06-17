#include<iostream>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node<T>* head, * next;
};

template <typename T>
class CirList {
private:
	Node<T>* head, * next;
public:

	CirList()
	{
		head = next = NULL;
	}

	void CreateList()
	{
		Node<T>* temp = NULL;
		int val;
		char choice;

		do
		{

			cout << "Enter the values in list" << endl;
			cin >> val;
			Node<T> * nn;
			nn = new Node<T>;
			nn->data = val;
			nn->next = NULL;

			if (head == NULL)
			{
				head = temp = nn;
			}

			else
			{
				temp->next = nn;
				temp = nn;
				temp->next = head;   //this statement is linking last node to the first node,that is circular linked list
			}
		//	temp->next = head;
			cout << "Press y for inserting another value,and n for exit" << endl;
			cin >> choice;
		} while (choice != 'n' && choice != 'N');

	}


	void insert()
	{
		Node<T>* temp = NULL, * nn;
		nn = new Node<T>;
		int v;
		cout << "insert value" << endl;
		cin >> v;
		nn->data = v;
		nn->next = NULL;

		if (head == NULL)
		{
			head = temp = nn;
		}

		else
		{
			temp = nn;
			temp->next = nn;
			temp->next = head;
		}

	}


	//************** Delete ***************/

	void delet_FromStart()
	{
		Node<T>* ptr, * temp;
		int v;

		cout << "Enter value " << endl;
		cin >> v;

		if (head == NULL)
		{
			cout << "null";
		}

		else if (head->next == head)
		{
			temp = head;
			head = NULL;
			delete temp;
		}

		//delete node from start
		else
		{
			ptr = head;
			temp = head;
			while (ptr->next != head)
				ptr = ptr->next;
			ptr->next = head->next;
			temp = head;

			delete temp;
			head = ptr->next;

		}

	}




	void delet_FromEnd()
	{

		Node<T>* ptr, * temp=NULL;
		int v;

		cout << "Enter value " << endl;
		cin >> v;

		if (head == NULL)
		{
			cout << "null";
		}

		else if (head->next == head)
		{
			temp = head;
			head = NULL;
			delete temp;
		}

		else
		{
			ptr = head;
			while (ptr->next != head)
			{
				temp = ptr;
				ptr = ptr->next;

			}
			temp->next = ptr->next;
			delete ptr;

		}

	}




	//*********************** search ******************//

	void search()
	{

		Node<T>* ptr=NULL;
		ptr = head;
		int v;
		cout << "Enter value " << endl;
		cin >> v;
		int i = 0, flag = 1;


		if (ptr == NULL)
		{
			cout << "empty";
		}

		else
		{
			if (head->data == v)
			{
				cout << "found at position " << i + 1;
				flag = 0;
			}

			else
			{
				while (ptr->next != head)
				{
					if (ptr->data == v)
					{
						cout << ptr->data << " found at position= " << i + 1 << endl;
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
					}
					i++;
					ptr = ptr->next;
				}
			}

			if (flag != 0)
			{
				cout << "Item not found" << endl;
			}
		}
	}





	//*********************  Display ****************//
	void display()
	{

		Node<T>* temp=NULL;
		cout << "list is mentioned below " << endl;
		if (head == NULL)
		{
			cout << "List is empty";
		}

		else
		{
			temp = head;
			while (temp->next != head)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
			//cout<<endl;
			cout << temp->data;
		}

	}



};




int main()
{
	CirList<int>l;
	int choice=1;


	while (choice != 7)
	{
		cout << "\nMain Menu\n";
		cout << "choose one option..\n";
		cout << "Press 1 to Create list" << endl;
		cout << "Press 2 to insert in list" << endl;
		cout << "Press 3 to search value in list" << endl;
		cout << "Press 4 to delete list from start" << endl;
		cout << "Press 5 to delete list from end" << endl;
		cout << "Press 6 to display list" << endl;
		cout << "Press 7 to exit";
		cout << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
			l.CreateList();
			break;
		case 2:
			l.insert();
			break;
		case 3:
			l.search();
			break;
		case 4:
			l.delet_FromStart();
			break;
		case 5:
			l.delet_FromEnd();
			break;
		case 6:
			l.display();
			break;
		case 7:
			exit(0);

		default:
			cout << "Enter valid number";
		}

	}

}