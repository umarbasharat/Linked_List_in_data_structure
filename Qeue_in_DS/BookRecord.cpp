#include<iostream>
using namespace std;

struct Book
{
	int isbn;
	int price;

	bool operator<(const Book& b)
	{
		return (isbn < b.isbn);
	}

	bool operator==(const Book& b)
	{
		return (isbn = b.isbn);
	}

	friend ostream& operator <<(ostream& out, const Book& b)
	{
		return out << "ISBN= " << b.isbn << ", Price= " << b.price;
		cout << endl;
	}

};


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




	void insert(const T& v)
	{

		Node<T>* temp=NULL, * nn;
		nn = new Node<T>;
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
			//temp = nn;
			temp->next = head;
		}

	}


	//************** Delete ***************/

	void delet_FromStart( T V)
	{
		Node<T>* ptr=NULL, * temp=NULL;
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
			temp = NULL;
		}

	}




	void delet_FromEnd( T V)
	{

		Node<T>* ptr=NULL, * temp=NULL;
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

	void search(const T& v)
	{

		Node<T>* ptr;
		ptr = head;

		int i = 0, flag = 1;


		if (ptr == NULL)
		{
			cout << "empty";
		}

		else
		{
			if (head->data == v)
			{
				cout << "book is in record" << endl;
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
	void display(const T& v)
	{

		Node<T>* temp;
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

	CirList<Book>l1;
	int choice=0;
	const int val = 2;
	int i = 0;
	Book b[val];


	while (choice != 5)
	{
		cout << "\nMain Menu\n";
		cout << "choose one option..\n";
		cout << "Press 1 to Create record" << endl;
		cout << "Press 2 to Find book  from record" << endl;
		cout << "Press 3 to delete book from record" << endl;
		cout << "Press 4 to display list" << endl;
		cout << "Press 5 to exit";
		cout << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\t Enter the BoOK record" << endl;
			for (i = 0;i < val;i++)
			{
				cout << "Enter ISBN of Book:\n";
				cin >> b[i].isbn;

				cout << "Enter price of Book:\n";
				cin >> b[i].price;
				l1.insert(b[i]);
			}
			break;
		}

		case 2:
			cout << "Enter ISBN of Book to search\n ";
			cin >> b[i].isbn;
			l1.search(b[i]);
			break;


		case 3:
			cout << "Enter ISBN of Book to delete\n ";
			cin >> b[i].isbn;
			l1.delet_FromEnd(b[i]);
			break;

		case 4:
			l1.display(b[i]);
			break;

		case 5:
			exit(0);

		default:
			cout << "Enter valid number";

		}
	}
}
