#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class circularLinkedList {
private:
	Node* LAST;

public:
	circularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpety();
	bool delNode(int rollNo);
	void traverse();
};
void circularLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the mahasiswa: ";
	cin >> nim;
	cout << "\nEnter the roll name of the  name: ";
	cin >> nm;
	Node* newNode = new Node();     //step 1
	newNode -> noMhs = nim;			//step 2
	newNode->name = nm;				// step 2

	/*menambah sebuah node dalam circular linkedlist*/
	if (LAST == NULL || nim <= LAST->noMhs) {
		if (LAST != NULL && nim == LAST->noMhs) {
			cout << "\nDublicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST;		//step 3
		if (LAST != NULL)
			LAST->prev = newNode;	//step 4
		newNode->prev = NULL;		//step 5
		LAST = newNode;			//Step 6
		return;
	}
	/*menambah sebuah node  dalam list*/
	Node* Alfandi = LAST;				//Step 1.a
	Node* Alamshach = NULL;				//Step 1.b
	while (Alfandi->next != NULL && Alfandi->next->noMhs < nim) { //stepp 1.c

		Alamshach = Alfandi;	//1.d
		Alfandi = Alfandi->next;		//1.e
}

	if (Alfandi->next != NULL && nim == Alfandi->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
	newNode->next = Alfandi->next; //Step 4
	newNode->prev = Alfandi;	//Step 5
	if (Alfandi->next != NULL)
		Alfandi->next->prev = newNode;	//Step 6
	Alfandi->next = newNode;	//step 7
}
bool circularLinkedList::search(int rollNo, Node** Alamshach, Node** Alfandi) {
	*Alamshach = LAST->next;
	*Alfandi = LAST->next;

	while (*Alfandi != LAST) {
		if (rollNo == (*Alfandi)->rollNumber) {
			return true;
		}
		*Alamshach = *Alfandi;
		*Alfandi = (*Alfandi)->next;
	}
	if (rollNo == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool circularLinkedList::listEmpety() {
	return LAST = NULL;
}
bool circularLinkedList::delNode(int rollNo) {
	Node* Alamshach, * Alfandi;
	Alamshach = Alfandi = NULL;
	if (search(rollNo, &Alamshach, &Alfandi) == false)
		return false;
	if (Alfandi->next != NULL)
		Alfandi->next->prev = Alamshach;			 //step 2
	if (Alamshach != NULL)
		Alamshach->next = Alfandi->next;			//step 3
	else
		LAST = Alfandi->next;


	delete Alfandi; //step 4
	return true;
}

void circularLinkedList::traverse() {
	if (listEmpety())
		cout << "\List is empety\n";
	
	else {
		cout << "\nRecord in the list are:\n";
		Node* AlfandiNode = LAST->next;
		while (AlfandiNode != LAST) {
			cout << AlfandiNode->rollNumber << "  " << AlfandiNode->name << endl;
			AlfandiNode = AlfandiNode->next;
		}
		cout << LAST->rollNumber << "  " << LAST->name << endl;
	}
}

int main() {
	circularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. exit" << endl;
			cout << "\nEnter your choice (1-5):";

			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case'2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}