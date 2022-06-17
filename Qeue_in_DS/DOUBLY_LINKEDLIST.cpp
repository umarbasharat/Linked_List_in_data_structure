#include<iostream>
using namespace std;


template<typename T>

struct Node {
	T data;
	Node<T>* next, * prev;
};


template<typename T>

class SDlist {
private:
	Node<T>* next, * prev, * head, * tail;
public:
	//constructor
	SDlist()
	{
		head = tail = next = prev = NULL;
	}

	void CreateList()
	{

		Node<T>* nn;
		int val;
		char choice;

		do {
			//we will create list 3,1,5,2 
			cout << "Enter the values in list" << endl;
			cin >> val;                    //FIRST CASE WHEN WE ENTER FIRST ELEMENT INTO LIST, LET WE ENTER 3
			nn = new Node<T>;
			nn->data = val;
			nn->next = NULL;
			nn->prev = NULL;


			if (tail == NULL)
			{
				head = nn;
				tail = nn;
			}

			//let us enetr 1 into new node of doubly linked list
			else if (val < tail->data)
			{
				nn->next = tail;  //here newnode's next part contains address of the node that contain  value =3
				tail->prev = nn;  //here tail's prev part  conatains adress of the newnode that contains  value=1
				nn->prev = NULL;
				tail = nn; //now tail is pointing to newnode that contains  value=1
			}

			//ENTER 5  INTO NEW NODE
			else if (val > head->data)
			{
				head->next = nn;
				nn->prev = head;
				nn->next = NULL;
				head = nn;
			}


			//Enter 2 into new node
			else
			{
				if (val == head->data || val == tail->data) { cout << " Values can not be same,enter again"; }
				Node<T>* temp=NULL, * ptr=NULL;
				temp = tail;    //store address of tail into temparory pointer ,whereas tail contains address of value 1

				while (temp != NULL && val > temp->data)
				{
					ptr = temp;
					temp = temp->next;
				}

				if (temp == NULL)
				{
					head->next = nn;
					nn->next = NULL;
					nn->prev = head;
					head = nn;
				}

				else
				{
					ptr->next = nn;
					temp->prev = nn;
					nn->next = temp;
				}
			}

			cout << "Press Y to enter value,otherwise N" << endl;
			cin >> choice;
		} while (choice != 'n' && choice != 'N');
	}


	void insert()
	{
		int val;
		cout << "insert values in list" << endl;
		cin >> val;
		Node<T>* nn;
		char choice;


		nn = new Node<T>;
		nn->data = val;
		nn->next = NULL;
		nn->prev = NULL;

		//we will create 3,1,5,2
		if (tail == NULL)
		{
			head = nn;
			tail = nn;
		}

		//let us enetr 1 into new node of doubly linked list
		else if (val < tail->data)
		{
			nn->next = tail;  //here newnode's next part contains address of the node that contain  value =3
			tail->prev = nn;  //here tail's prev part  conatains adress of the newnode that contains  value=1
			nn->prev = NULL;
			tail = nn; //now tail is pointing to newnode that contains  value=1
		}

		//ENTER 5  INTO NEW NODE
		else if (val > head->data)
		{
			head->next = nn;
			nn->prev = head;
			nn->next = NULL;
			head = nn;
		}


		//Enter 2 into new node
		else
		{
			Node<T>* temp=NULL, * ptr=NULL;
			temp = tail;    //store address of tail into temparory pointer ,whereas tail contains address of value 1

			while (temp != NULL && val > temp->data)
			{
				ptr = temp;
				temp = temp->next;
			}

			if (temp == NULL)
			{
				head->next = nn;
				nn->next = NULL;
				nn->prev = head;
				head = nn;
			}

			else
			{
				ptr->next = nn;
				temp->prev = nn;
				nn->next = temp;
			}
		}

	}


	void Delet()
	{
		int data;
		int val;

		cout << "ENter value" << endl;
		cin >> val;


		//delete from front front,let us we delete node that contains value 1
		if (tail->data == val)
		{
			Node<T>* temp_ptr=NULL;
			temp_ptr = tail;
			tail = tail->next;
			delete temp_ptr;
			tail->prev = NULL;

		}

		//delete last node  let us delete value 5 
		else if (head->data == val)
		{
			Node<T>* temp_ptr=NULL;
			temp_ptr = head;
			head = head->next;
			delete temp_ptr;
			head->next = NULL;

		}

		//now delete node that contains value 2
		else
		{
			Node<T>* temp=NULL;
			temp = tail;
			while (temp != NULL)
			{
				if (temp->data == val)
				{
					temp->prev->next = temp->next;  //connecting the 1st node with 3rd node
					delete temp;    //node that contains value 2 is deleted 

				}
				temp = temp->next;
			}

		}

	}

	T Front()const
	{
		return tail->data;
	}

	T Back()const
	{
		return head->data;
	}

	void pop_frnt()const
	{
		Node<T>* temp;
		temp = tail;
		tail = tail->next;
		delete temp;
		tail->prev = NULL;
	}

	void pop_back()const
	{
		Node<T>* temp;
		temp = head;
		head = head->next;
		delete temp;
		head->next = NULL;
	}



	void Display() const {
		Node<T>* temp;
		temp = tail;
		cout << endl;
		cout << "Values in list are mentioned below: " << endl;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}




};
int main()
{
	SDlist<int> l;

	int choice=0;


	while (choice != 5)
	{
		cout << "\nMain Menu\n";
		cout << "choose one option..\n";
		cout << "Press 1 to Create list" << endl;
		cout << "Press 2 to insert in list" << endl;
		cout << "Press 3 to delete list" << endl;
		cout << "Press 4 to display list" << endl;
		cout << "Press 5 to exit";
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
			l.Delet();
			break;
		case 4:
			l.Display();
			break;

		case 5:
			exit(0);

		default:
			cout << "Enter valid number";
		}


	}
}


