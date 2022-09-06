
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

void GenerateList();
void GenerateXList(int);
static void printList();
struct Item* FindVal(int);
void freeList();
struct Item* ChangeVal(int, int);
void ResetList();
struct Item* InsertNewItem(int);
void sortList();

typedef struct Item{
	int val;
	struct Item* Next;
	struct Item* Prev;
}Item;

Item* head = NULL, *tail = NULL;

int main()
{
	int oldVal, newVal = 10;
	printf("List 1:\n");
	InsertNewItem(2);
	InsertNewItem(4);
	InsertNewItem(4);
	InsertNewItem(7);
	InsertNewItem(8);
	printList();
	printf("Please enter value to change: ");
	scanf("%d", &oldVal);
	ChangeVal(oldVal, newVal);
	printList();
	ResetList();
	printf("List 2:\n");
	GenerateXList(15);
	sortList();
	printList();
	ResetList();
}

void GenerateList()
{
	time_t t = time();
	Item* temp = NULL, * curr = NULL;
	srand(t);
	for (int i = 0; i < 10; i++)
	{
		temp = (Item*)malloc(sizeof(Item));
		if (!temp)
		{
			printf("Allocation Error");
		}
		temp->val = rand() % 10;
		if (!head)
		{
			head = temp;//3 1
			tail = temp;
			temp->Next = NULL;
			temp->Prev = NULL;
		}
		else
		{
			tail = temp;
			temp->Next = NULL;
			temp->Prev = curr;
			curr->Next = temp;
		}
		curr = temp;
	}
}

void printList()
{
	Item* curr = head;
	while (curr)
	{
		printf("%d\n", curr->val);
		curr = curr->Next;
	}
}

void GenerateXList(int num)
{
	time_t t = time();
	int j = 1;
	Item* temp = NULL, * curr = NULL;
	srand(t);
	for (int i = 0; i < num; i++)
	{
		temp = (Item*)malloc(sizeof(Item));
		if (!temp)
		{
			printf("Allocation Error");
		}
		temp->val = rand() % 100;
		if (!head)
		{
			head = temp;//3 1
			tail = temp;
			temp->Next = NULL;
			temp->Prev = NULL;
		}
		else
		{
			tail = temp;
			temp->Next = NULL;
			temp->Prev = curr;
			curr->Next = temp;
		}
		curr = temp;
	}
}

void freeList()
{
	Item* curr = head;
	while (head)
	{
		curr = head;
		head = head->Next;
		free(curr);
	}
	head = tail = NULL;
}

struct Item* FindVal(int val) {
	Item* curr = head;
	while (curr)
	{
		if (curr->val == val)
		{
			return curr;
		}
		curr = curr->Next;
	}
	return NULL;
}

struct Item* ChangeVal(int oldVal, int newVal)
{
	Item* ret = FindVal(oldVal);
	if (ret)
	{
		ret->val = newVal;
		return head;
	}
	return NULL;
}

void ResetList()
{
	if (head)
	{
		freeList();
	}
}

struct Item* InsertNewItem(int val)
{
	Item* node = (Item*)malloc(sizeof(Item));
	Item* curr = head;
	node->val = val;
	node->Next = node->Prev = NULL;
	if (!head)
	{
		head = node;
		tail = node;
		return head;
	}
	else
	{
			if (node->val < head->val)
			{
				node->Prev = NULL;
				head->Prev = node;
				node->Next = head;
				head = node;
				return head;
			}
			else if(node->val > tail->val) {
				node->Next = NULL;
				tail->Next = node;
				node->Prev = tail;
				tail = node;
				return head;
			}
	}
	curr = head;
	while (curr->val < node->val)
	{
		curr = curr->Next;
	}
	node->Prev = curr->Prev;
	node->Next = curr;
	curr->Prev->Next = node;
	curr->Prev = node;
	return head;
}

void sortList()
{
	Item* previous = head, *curr = head->Next; 
	int temp;
	while (curr)
	{
		while (curr) 
		{
			if (previous->val > curr->val)
			{
				temp = previous->val;
				previous->val = curr->val;
				curr->val = temp;
			}
			curr = curr->Next; 
		}
		previous = previous->Next;
		curr = previous->Next;
	}
}