#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char *Name;
    int id;
    char *address;
    struct student *ptr;
};
struct student* createStudent(char *name, int id, char *address) {
    struct student *newStudent = (struct student *)malloc(sizeof(struct student));
    newStudent->Name = strdup(name);
    newStudent->id = id;
    newStudent->address = strdup(address);
    newStudent->ptr = NULL;
    return newStudent;
}
void printStudents(struct student *head)
{
    struct student *current = head;
    while (current != NULL)
    {
        printf("Name: %s, ID: %d, Address: %s\n", current->Name, current->id, current->address);
        current = current->ptr;
    }
}
void cutConnection(struct student *head, char *name1, char *name2)
{
    struct student *current = head;
    while (current != NULL && current->ptr != NULL)
    {
        if (strcmp(current->Name, name1) == 0 && strcmp(current->ptr->Name, name2) == 0)
        {
            current->ptr = current->ptr->ptr;
            break;
        }
        current = current->ptr;
    }
}
void insertStudent(struct student *head, struct student *newStudent, char *name1, char *name2)
{
    struct student *current = head;
    while (current != NULL)
    {
        if (strcmp(current->Name, name1) == 0 && current->ptr != NULL && strcmp(current->ptr->Name, name2) == 0)
        {
            newStudent->ptr = current->ptr;
            current->ptr = newStudent;
            break;
        }
        current = current->ptr;
    }
}
int main()
{
    struct student *head = createStudent("Pallavi", 1, "Address 1");
    head->ptr = createStudent("Darshini", 2, "Address 2");
    head->ptr->ptr = createStudent("Rahul", 3, "Address 3");
    head->ptr->ptr->ptr = createStudent("Sita", 4, "Address 4");
    head->ptr->ptr->ptr->ptr = createStudent("Amit", 5, "Address 5");
    head->ptr->ptr->ptr->ptr->ptr = createStudent("Neha", 6, "Address 6");
    head->ptr->ptr->ptr->ptr->ptr->ptr = createStudent("Varun", 7, "Address 7");
    printf("Original student chain:\n");
    printStudents(head);
    cutConnection(head, "Pallavi", "Darshini");
    printf("\nAfter cutting connection between Pallavi and Darshini:\n");
    printStudents(head);
    struct student *newStudent = createStudent("Varshini", 8, "Address 8");
    insertStudent(head, newStudent, "Pallavi", "Rahul");
    printf("\nAfter adding Varshini between Pallavi and Rahul:\n");
    printStudents(head);
    struct student *current = head;
    struct student *next;
    while (current != NULL)
    {
        next = current->ptr;
        free(current->Name);
        free(current->address);
        free(current);
        current = next;
    }

    return 0;
}
