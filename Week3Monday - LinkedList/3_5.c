#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

static struct MyStruct* initList();
static void printList(struct MyStruct*);
static void releaseList(struct MyStruct*);

struct MyStruct
{
	int val;
	struct MyStruct* next;
};

int main5()
{
	struct MyStruct* head = initList();
	printList(head);
	releaseList(head);
	return 0;
}

struct MyStruct* initList() {
	int num;
	struct MyStruct* head = NULL, * curr, * prev = NULL;
	printf("Please enter a number (or 100 to exit): ");
	scanf("%d", &num);
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
		prev = curr;
		printf("Please enter a number (or 100 to exit): ");
		scanf("%d", &num);
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
	printf("There are %d 44 inside the Linked List", count);
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