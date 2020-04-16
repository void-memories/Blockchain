#include <iostream>
#include <vector>
#include <map>
#include "../headers/verification.h"
using namespace std;

class List : public Verification
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

	void deleteNode(struct Node **head_ref, int key)
	{

		struct Node *temp = *head_ref, *prev;

		if (temp != NULL)
		{
			*head_ref = temp->next; // Changed head
			free(temp);				// free old head
			return;
		}

		while (temp != NULL)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
			return;

		prev->next = temp->next;

		free(temp); // Free memory
	}

	void deleteList(Node **head_ref)
	{

		Node *current = *head_ref;
		Node *next;

		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}

		*head_ref = NULL;
	}

	void push(Node **head_ref, int new_data)
	{
		Node *new_node = new Node();

		new_node->next = (*head_ref);
	}

	void deleteNode2(struct Node **head_ref, int position)
	{

		if (*head_ref == NULL)
			return;

		struct Node *temp = *head_ref;

		if (position == 0)
		{
			*head_ref = temp->next; // Change head
			free(temp);				// free old head
			return;
		}

		for (int i = 0; temp != NULL && i < position - 1; i++)
			temp = temp->next;

		if (temp == NULL || temp->next == NULL)
			return;

		struct Node *next = temp->next->next;

		free(temp->next); // Free memory

		temp->next = next; // Unlink the deleted node from list
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
