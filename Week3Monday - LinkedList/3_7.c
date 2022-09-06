#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

static struct MyStruct* initList();
static void releaseList(struct MyStruct*);
static void initSave();
static void save(struct MyStruct*);

struct MyStruct
{
	int val;
	struct MyStruct* next;
};

int main7()
{
	initSave();
	struct MyStruct* head = initList();
	save(head);
	releaseList(head);
	return 0;
}

struct MyStruct* initList() {
	FILE* f = fopen("uploadList.bin", "r");
	if(!f)
	{
		printf("file error");
		exit(1);
	}
	struct MyStruct* head = NULL, * curr = NULL, * prev = NULL, temp;
	while (fread(&temp, sizeof(struct MyStruct), 1, f))
	{
		curr = (struct MyStruct*)malloc(sizeof(struct MyStruct));
		*curr = temp;
		if (!curr)
		{
			printf("Allocation Error");
			exit(1);
		}
		if (!head)
		{
			head = curr;
		}
		else {
			prev->next = curr;
		}
		prev = curr;
		curr->next = NULL;
	}
	fclose(f);
	return head;
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

static void initSave()
{
	FILE* f = fopen("uploadList.bin", "w");
	if (!f)
	{
		printf("file error");
		exit(1);
	}
	struct MyStruct node;
	scanf("%d", &node.val);
	while (node.val != 100)
	{
		fwrite(&node, sizeof(struct MyStruct), 1, f);
		scanf("%d", &node.val);
	}
	fclose(f);
}

void save(struct MyStruct* head)
{
	FILE* f = fopen("LOAD.bin", "w");
	struct MyStruct* list = head;
	while (list)
	{
		fwrite(list, sizeof(struct MyStruct), 1, f);
		list = list->next;
	}
	fclose(f);
}