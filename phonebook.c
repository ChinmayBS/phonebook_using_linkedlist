/**********
          This is c program which implemets phonebook using double linked list
********/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char name[30];
  char number[15];
  char email[50];
  struct node *left;
  struct node *right;
};
typedef struct node *NODE;


NODE create_node(char name[],char number[],char email[])
{
  NODE temp;
  temp=(NODE) malloc(sizeof(struct node));
  strcpy(temp->name,name);
  strcpy(temp->number,number);
  strcpy(temp->email,email);
  temp->left=NULL;
  temp->right=NULL;
  return temp;

}

NODE insert_node(NODE start,char name[],char number[],char email[])
{

  NODE new,cur=NULL,prev=NULL;
  new=create_node(name,number,email);

  if(start==NULL)
  {
    return new;
  }

  else
  {
    cur=start;
    while(cur!=NULL)
    {
      prev=cur;
      if(strcmp(cur->number,number)==0 || strcmp(cur->name,name)==0 || strcmp(cur->email,email)==0 )
      {
      if(strcmp(cur->number,number)==0)
        printf(" contact with given number already present \n");
      else if( strcmp(cur->email,email)==0)
        printf(" contact with given email id already present \n");
      else
        printf(" contact with given name already present \n");

        return start;
      }

      cur=cur->right;

    }
    prev->right=new;
    new->left=prev;

    return start;
  }


}

void search_node(NODE start,char unique[])
{
  NODE cur;
  if(start==NULL)
  {
    printf("\n Contact with name %s is not present\n",unique);
    return;
  }

  else
  {
    cur=start;
    while(cur!=NULL)
    {
      if(strcmp(cur->name,unique)==0)
      {
        printf("\n Contact with %s is present",cur->name);
        printf("\n Mobile number: %s",cur->number);
        printf("\n email id: %s",cur->email);
        return;
      }
      cur=cur->right;
    }
    printf("\n Contact with name %s is not present\n",unique);
    return;
  }
}


void display_contacts(NODE start)
{
  NODE cur;

  if(start==NULL)
  {
   printf("\n No contacts present\n");
   return;
  }

   cur=start;
   while(cur!=NULL)
   {
     printf(" Name: %s\n",cur->name);
     printf(" Mobile number: %s\n",cur->number);
     printf(" Email id: %s\n",cur->email);
     cur=cur->right;
   }


}

NODE delete_node(NODE start,char name[])
{
  NODE cur,prev,temp=NULL;
  if(start==NULL)
  {
    printf(" Contact with name %s not found\n",name);
    return start;
  }
  else if (strcmp(start->name,name)==0)
  {
      cur=start;
      start=start->right;
      free(cur);
      printf(" Contact with name %s is deleted\n",name);
      return start;
  }


  else
  {
    cur=start;
    while(cur!=NULL )
    {
      if(strcmp(cur->name,name)==0)
      {
        temp=cur;
        (temp->left)->right=temp->right;
        free(temp);
        printf(" Contact with name %s is deleted\n",name);
        return start;
      }
      cur=cur->right;
    }
    printf(" Contact with name %s not found\n",name);
    return start;
    }
  }


void contacts_length(NODE start)
{
  int n=0;
  NODE cur=NULL;
  if(start==NULL)
  n=0;
  else
  {
    cur=start;
    while(cur!=NULL)
    {
      cur=cur->right;
      n+=1;
    }
  }
  printf(" There are %d contacts in your phonebook\n",n);
}



int main()
{
  int choice;
  NODE start=NULL;
  char name[20],number[15],email[25],unique[30];
  while(1)
  {
    printf("           ------Welcome to phonebook------ \n");
    printf(" Enter your choice:\n");
    printf(" 1.Add new contact\n 2.Search for a contact\n 3.Display contact from phonebook\n");
    printf(" 4.Delete contact\n 5.Total contacts \n 6.End ");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
      {
        printf(" Enter conatct deatails:\n");
        printf(" 1.name: ");
        scanf("%s",name);
        printf(" 2.number: ");
        scanf("%s",number);
        printf(" 3.email: ");
        scanf("%s",email);
        start=insert_node(start,name,number,email);
      }
      break;

      case 2:
      {
        printf("\n Enter contact's name: ");
        scanf("%s",unique);
        search_node(start,unique);
      }
      break;


      case 3:
      {
        printf("\n Contacts present in your phonebook are: \n");
        display_contacts(start);
      }
      break;
      case 4:
      {
        printf("\n Enter contact's name: ");
        scanf("%s",unique);
        start=delete_node(start,unique);
      }
      break;

      case 5:
      {
        contacts_length(start);
      }
      break;

      case 6:exit(0);

      default:printf(" Wrong Choice\n");
    }

  }

  return 0;
}
