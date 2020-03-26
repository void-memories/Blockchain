#include <iostream>
#include <vector>
#include <map>
using namespace std;
class List
{

public:
	class Node
	{
	public:
		vector<string> data;
		Node *next;
	};

	void append(Node **head_ref, vector<string> new_data)
	{
		Node *new_node = new Node();
		Node *last = *head_ref;
		new_node->data = new_data;
		new_node->next = NULL;

		if (*head_ref == NULL)
		{
			*head_ref = new_node;
			return;
		}

		while (last->next != NULL)
			last = last->next;

		last->next = new_node;
		return;
	}

	void printList(Node *node)
	{
		while (node != NULL)
		{
			cout << "Name : " << node->data[0] << endl;
			cout << "DOB : " << node->data[1] << endl;
			cout << "M1 : " << node->data[2] << endl;
			cout << "M2 : " << node->data[3] << endl;
			cout << "M3 : " << node->data[4] << endl;
			cout << "M4 : " << node->data[5] << endl;
			cout << "M5 : " << node->data[6] << endl;
			node = node->next;
		}
	}

	int CreateBlockChain(vector<string> accepted_keys, map<string, int> db, vector<string> marks_card[])
	{
		Node *head = NULL;
		string curr_key;
		int req_index;

		for (int i = 0; i < accepted_keys.size(); i++)
		{

			curr_key = accepted_keys[i];
			req_index = db[curr_key];
			append(&head, marks_card[req_index]);
		}

		cout << endl
			 << "*********Block Chain Created*********" << endl;
		cout << "Hit ENTER to display" << endl;
		cin.ignore();
		printList(head);

		return 0;
	}
};
