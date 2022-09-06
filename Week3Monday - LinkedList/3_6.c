#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

static struct MyStruct* initList();
static void printList(struct MyStruct*);
static void releaseList(struct MyStruct*);
void findId(struct MyStruct*, int id);

struct MyStruct
{
	int val;
	int id;
	struct MyStruct* next;
};

int main6()
{
	int id = 10;
	struct MyStruct* head = initList();
	printList(head);
	findId(head, id);
	releaseList(head);
	return 0;
}

struct MyStruct* initList() {
	int num, id;
	struct MyStruct* head = NULL, * curr, * prev = NULL;
	printf("Please enter a number (or 100 to exit) and ID: ");
	scanf("%d %d", &num, &id);
	while (num != 100)
	{
		curr = (struct MyStruct*)malloc(sizeof(struct MyStruct));
		while (!curr)
		{
			printf("Allocation Error");
			exit(1);
		}
		if (!head)
		{
			curr->val = num;
			head = curr;
		}
		else {
			prev->next = curr;
		}
		curr->val = num;
		curr->id = id;
		prev = curr;
		printf("Please enter a number (or 100 to exit) and ID: ");
		scanf("%d %d", &num, &id);
		curr->next = NULL;
	}
	prev = head;
	return head;
}

void printList(struct MyStruct* head)
{
	struct MyStruct* curr = head;
	int count = 0;
	while (curr)
	{
		if (curr->val == 44)
		{
			count++;
		}
		curr = curr->next;
	}
	printf("There are %d 44 inside the Linked List\n", count);
}

void releaseList(struct MyStruct* head)
{
	struct MyStruct* curr = head;
	while (head)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}

void findId(struct MyStruct* head, int id)
{
	struct MyStruct* curr = head;
	int place = 1;
	while (curr)
	{
		if (curr->id == id)
		{
			printf("The id is in the %d element\n", place);
		}
		curr = curr->next;
		place++;
	}

}