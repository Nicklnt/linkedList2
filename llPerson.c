#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// structure is created
struct Person
{
    char name[20];
    int age;
    struct Person *nextP;
    struct Person *prevP;
};

// two global variables
struct Person *firstP;
struct Person *lastP;

// prototips
void addP();
void addLastP();
void printPer();
void deleteP();
void sorting();

// main
int main(int argc, char **argv)
{
    firstP = malloc(sizeof(struct Person)); // creating the first element
    printf("Name of the person: \n");
    scanf("%s", firstP->name);

    printf("Age: \n");
    scanf("%d", &firstP->age);

    firstP->nextP = NULL;
    firstP->prevP = NULL;

    lastP = firstP;

    // variabels that control the switch
    char svar;
    bool exit = false;

    // switch
    do
    {

        printf("what do you want to do?\n1- Add a person\n2- Add a person in the end\n3- Print a person\n4- Deleted a person\n5- Sorting list\n6- exit\n");
        scanf(" %c", &svar);

        switch (svar)
        {
            case '1':
                addP();
                break;

            case '2':
                addLastP();
                break;

            case '3':
                printPer();
                break;

            case '4':
                deleteP();
                break;

            case '5':
                sorting(); // doesn't work
                break;
            case '6':
                exit = true;
                break;
            default:
                printf("You choose a wrong option. Try again");
        }

    } while (exit == false);

    return 0;
}

// create a new person
void addP()
{
    struct Person *newP = malloc(sizeof(struct Person));
    printf("Name of the person: \n");
    scanf("%s", newP->name);

    printf("Age: \n");
    scanf("%d", &newP->age);

    newP->nextP = firstP;
    newP->prevP = NULL;
    firstP->prevP = newP;
    firstP = newP;
}

// create a new person in the last position
void addLastP()
{
    struct Person *newLastP = malloc(sizeof(struct Person));
    printf("Name of the person: \n");
    scanf("%s", newLastP->name);
    printf("age: \n");
    scanf("%d", &newLastP->age);

    newLastP->nextP = NULL;
    newLastP->prevP = lastP;
    lastP->nextP = newLastP;
    lastP = newLastP;
}

// print the information of a person
void printPer()
{
    char name2[20];
    printf("skriv namn av the person\n");
    scanf("%s", name2);

    for (struct Person *p = firstP; p != NULL; p = p->nextP)
    {
        if (strcmp(p->name, name2) == 0)
        {
            printf("%s is %d years old\n", p->name, p->age);
        }
    }
}

// delete a person
void deleteP()
{
    char nameD[20];
    printf("name of the person to delete: \n");
    scanf("%s", nameD);

    for (struct Person *p = firstP; p != NULL; p = p->nextP)
    {
        if (strcmp(p->name, nameD) == 0)
        {
            struct Person *Prev = p->prevP;
            struct Person *Next = p->nextP;

            if (Prev != 0)
            {
                Prev->nextP = p->nextP;
            }

            if (Next != 0)
            {
                Next->prevP = p->prevP;
            }

            if (firstP == p)
            {
                firstP = Next;
            }
            if (lastP == p)
            {
                lastP = Prev;
            }

            free(p);
        }
    }
}

// organize the element. Doesn't work
void sorting()
{
    for (struct Person *p = firstP; p != NULL; p = p->nextP)
    {
        for (struct Person *q = firstP; q != NULL; q = q->nextP)
        {

            if (q->age > p->age)
            {
                struct Person *Prev = q->prevP;
                struct Person *Next = q->nextP;
                if (Next != 0)
                {
                    q->prevP = p->prevP;
                    q->nextP = p;
                    p->prevP = q;
                    p->nextP = Next;
                    Next->prevP = p;
                }
                else
                {
                    q->prevP = p->prevP;
                    q->nextP = p;
                    p->prevP = q;
                    p->nextP = Next;
                }
            }
        }
    }

    for (struct Person *p = firstP; p != 0; p = p->nextP)
    {
        printf("%s is %d years old\n", p->name, p->age);
    }
}