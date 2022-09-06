#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

void Q1();
struct MyStruct
{
	int val;
	struct MyStruct* next;
};

int main2()
{
	Q1();
	return 0;
}

void Q1() {
	int num;
	struct MyStruct* head = NULL, *curr, *prev = NULL;
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
	while (prev)
	{
		printf("The value is: %d\n", prev->val);
		prev = prev->next;
	}
	prev = head;
	while (head)
	{
		prev = head;
		head = head->next;
		free(prev);
	}
}