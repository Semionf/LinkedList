#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

void q1();
void q2();
void q3();

struct Person {
	int age;
	int id;
	int height;
	struct Person* next;
};

struct Students
{
	int age;
	int phone;
	int id;
};


int main1()
{
	q1();
	//q2();
	q3();
	return 0;
}

void q1()
{
	int numOfPerson;
	FILE* f = fopen("Q1.bin", "w");
	struct Person* personList, * currentPerson;
	printf("Please enter number of person: ");
	scanf("%d", &numOfPerson);
	personList = (struct Person*)malloc(sizeof(struct Person) * numOfPerson);
	if (!personList)
	{
		printf("Error");
		exit(1);
	}
	currentPerson = personList;
	for (int i = 0; i < numOfPerson; i++)
	{
		printf("Please enter age: ");
		scanf("%d", &currentPerson->age);
		printf("Please enter height: ");
		scanf("%d", &currentPerson->height);
		printf("Please enter ID: ");
		scanf("%d", &currentPerson->id);
		currentPerson++;
	}
	fwrite(personList, sizeof(struct Person), numOfPerson, f);
	fclose(f);
	free(personList);
}

void q2()
{
	int count = 0;
	struct Students stud;
	FILE* f = fopen("LinkedList.bin", "r");
	if (!f)
	{
		printf("Error");
		exit(1);
	}
	while (fread(&stud, sizeof(struct Students), 1, f))
	{
		count += stud.id;
	}
	printf("The total id is: %d", count);
}

void q3()
{
	FILE* f = fopen("Q1.bin", "r");
	if (!f)
	{
		printf("File error");
	}
	struct Person* head, *prev = NULL, *currentPerson;
	struct Person temp;
	head = NULL;
	while (fread(&temp, sizeof(struct Person), 1, f))
	{
		currentPerson = (struct Person*)malloc(sizeof(struct Person));
		if (!currentPerson)
		{
			printf("Malloc error");
		}
		currentPerson->age = temp.age;
		currentPerson->id = temp.id;
		currentPerson->height = temp.height;
		if (!head)
		{
			head = currentPerson;
		}
		else {
			prev->next = currentPerson;
		}
		currentPerson->next = NULL;
		prev = currentPerson;
	}
	prev = head;
	while(prev)
	{
		printf("Age is: %d ID is: %d Height is: %d\n", prev->age, prev->id, prev->height);
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