#include<stdio.h>
#include<stdlib.h>
struct node
  {
    int data;
    struct node *link;
  } 
 *head=NULL,*ptr,*ptr1,*ptr2,*temp;
void insertion() 
  {
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
        printf("Overflow Error \n");
    else if(head==NULL) 
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&temp->data);
        temp->link=NULL;
        head=temp;
    }
    else
     {
        int position;
        printf("Choose where to insert new element:\n  1. Insert at front\t 2. Insert at end\t 3. Insert at random position\t");
        scanf("%d",&position);
        if(position==1) 
        {
            printf("Enter the element to be inserted: ");
            scanf("%d", &temp->data);
            temp->link=head;
            head=temp;
        }
        else if(position==2) 
        {
            ptr=head;
            while(ptr->link!=NULL) 
            ptr=ptr->link;
            ptr->link=temp;
            printf("Enter the element to be inserted: ");
            scanf("%d",&temp->data);
            temp->link=NULL;
        }
        else if(position==3) 
        {
            int key;
            printf("Enter the element after which new node is to be inserted: ");
            scanf("%d",&key);
            ptr1=head;
            ptr2=ptr1->link;
            while((ptr1->data != key) && (ptr2->link != NULL)) 
            {
              ptr1 = ptr2;
              ptr2 = ptr2->link;
            }
            if(ptr1->data==key) 
            {
                printf("Enter the element to be inserted: ");
                scanf("%d", &temp->data);
                temp->link=ptr2;
                ptr1->link=temp;
            }
            else
                printf("Element not found in linked list! \n");
        }
        else
            printf("Invalid Input! \n");
       }
      }
    void deletion() 
    {
    if(head==NULL)
        printf("Underflow Error! \n");
    else if(head->link==NULL) 
    {
        ptr=head;
        printf("Deleted element is %d \n", ptr->data);
        head=NULL;
        free(ptr);
    }
    else 
    {
        int position;
        printf("Choose from where to delete element:\n  1. Delete from front\t 2. Delete from end\t 3. Delete from any position\t");
        scanf("%d",&position);
        if(position==1) 
        {
            ptr=head;
            printf("Deleted element is %d \n", ptr->data);
            head=ptr->link;
            free(ptr);
        }
        else if(position==2) 
        {
            ptr1=head;
            ptr2=ptr1->link;
            while(ptr2->link!=NULL) 
            {
                ptr1=ptr2;
                ptr2=ptr2->link;
            }
            printf("Deleted element is %d \n", ptr2->data);
            ptr1->link=NULL;
            free(ptr2);
        }
        else if(position==3) 
        {
            int key;
            printf("Enter the element whose node is to be deleted: ");
            scanf("%d",&key);
            ptr1=head;
            ptr2=ptr1->link;
            while((ptr2->data!=key)&&(ptr2->link!=NULL))
            {
                ptr1 = ptr2;
                ptr2 = ptr2->link;
            }
            if (ptr2->data==key) 
            {
                printf("Deleted element is %d \n", ptr2->data);
                ptr1->link = ptr2->link;
                free(ptr2);
            }
            else
                printf("Element not found! \n");
        }
        else
            printf("Invalid Input! \n");
   } 
}
void display() 
   {
    if(head==NULL)
      printf("Linked List Empty! \n");
    else{
        printf("Given linked list is: \n");
        ptr=head;
        while(ptr!=NULL) 
        {
            printf("%d \t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
         } 
   }
void main() 
{
    int choice;
    while(choice!=4)
     {
        printf("\nEnter operation to be performed:\n   1.Insertion\t 2. Deletion\t 3. Display\t 4.Exit\t");
        scanf("%d",&choice);
        switch(choice) 
        {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Code successfully executed");
                break;
            default:
                printf("Invalid Input! \n");
                break;
       }
    } 
}
