/**********
          This is c program which implemets phonebook using double linked list
********/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char name[30];
  char number[10];
  char email[50];
  struct node *left;
  struct node *right;
};
typedef struct node *NODE;

struct head
{
  int length;
  struct node *addr;
};
typedef struct head *HEAD;

NODE create_node(NODE temp)
{

}

NODE insert_node(NODE start,char name[],char number[],char email[])
{

}

NODE search_node(NODE start,int type,char id[])
{

}

void display_contacts(NODE start)
{

}

NODE delete_node(NODE start,char name[])
{

}

void contacts_length(NODE start)
{

}



int main()
{
  int choice;
  HEAD head;
  head->addr=NULL;
  head->length=0;

  while(1)
  {
    printf(" Welcome to phonebook: \n");
    printf(" Enter your choice: ");
    printf(" 1.Add new contact\n 2.Search for a contact\n 3.Display contact from phonebook\n");
    printf(" 4.Delete contact\n 5.Total contacts \n 6.End ");
    scanf("%d",choice);
    switch (choice)
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      default:printf(" Wrong Choice");
    }

  }

  return 0;
}
