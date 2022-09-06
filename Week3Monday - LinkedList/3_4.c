#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

struct MyStruct* initList();
void printList(struct MyStruct*);
void releaseList(struct MyStruct*);

struct MyStruct
{
	int val;
	struct MyStruct* next;
};

int main4()
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
	while (curr)
	{
		printf("%d ", curr->val);
		curr = curr->next;
	}
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