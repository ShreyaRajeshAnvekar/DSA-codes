#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE create_node();
NODE insert_end(NODE head);
void display_node(NODE head);
void display_rev(NODE head);
NODE insert_front(NODE head);
NODE delete_end(NODE head);
NODE delete_front(NODE head);
int count_nodes(NODE head);
NODE insert_position(NODE head);
NODE delete_position(NODE head);

int main()
{
    int ch,count;
    NODE head=NULL;
    while(1)
    {
       printf("Linked List\n");
        printf("1:Insert_end 2:Insert_front 3:Delete_end 4:Delete_front 5:Display 6:insert_position 7:Delete_position 8:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1:head=insert_end(head);
                 break;
          case 2:head=insert_front(head);
                 break;
          case 3:head=delete_end(head);
                 break;
          case 4:head=delete_front(head);
                 break;
          case 5: display_node(head);
                 break;
          case 6:head=insert_position(head);
                break;
          case 7:head=delete_position(head);
                break;
          case 8: exit(0);
                 break;
          default:printf("Invalid choice\n");
                  break;
        }
    }

}

NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter details\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

NODE insert_end(NODE head)
{
    NODE cur,newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;
}

void display_node(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else
    {
        while(cur !=NULL)
        {
            printf("%d-> ",cur->data);
            cur=cur->link;
        }
    }
    printf("\n");

}

NODE insert_front(NODE head)
{
   NODE newnode;
   newnode=create_node();
   if(head==NULL)
   {
       head=newnode;
   }
   else
   {
       newnode->link=head;
       head=newnode;
   }
   return head;
}





NODE delete_end(NODE head)
{
    NODE cur,prev;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur-cur->link;
        }
        prev->link=NULL;
        printf("Deleted %d \n",cur->data);
        free(cur);
    }
    return head;

}

NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted note %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        printf("Deleted node %d\n",head->data);
        cur->link=NULL;
        free(cur);
    }
    return head;
}

int count_nodes(NODE head)
{
    int count =0;
    NODE cur;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
    }
    return count;
}

NODE insert_position(NODE head)
{
	NODE prev, cur,newnode;
	newnode=create_node();
	int pos,i;
	int count=count_nodes(head);
	printf("Enter position:\t");
	scanf("%d",&pos);
	if(pos==1&&head==NULL)
	{
		head=newnode;
	}
	else if(pos==1)
	{
		newnode->link=head;
		head=newnode;
	}
	else if(pos==count+1)
	{
		cur=head;
		while(cur->link!=NULL)
		{
			cur=cur->link;
		}
		cur->link=newnode;
	}
	else if(pos>1 &&pos<=count)
	{
		prev=NULL;
		cur=head;
		for(i=0;i<pos;i++)
		{
			prev=cur;
			cur=cur->link;
		}
		prev->link=newnode;
		newnode->link=cur;
	}
	else
	{
		printf("Invalid position\n");
	}
	return head;
}

NODE delete_position(NODE head)
{
    int pos,i;
    NODE cur,prev;
    int count=count_nodes(head);
    printf("Enter the position to delete\n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(pos==1&&head->link==NULL)
    {
        printf("Deleted %d \n",head->data);
        free(head);
        head=NULL;
    }
    else if(pos==1)
    {
        cur=head;
        head=head->link;
        cur->link=NULL;
        printf("Deleted %d \n",cur->data);
        free(cur);
    }
    else if(pos==count)
    {
        head=delete_end(head);
    }
    else if(pos>1&&pos<count)
    {
        prev=NULL;
        cur=head;
        for(i=0;i<pos;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    else
    {
        printf("Invalid position\n");
    }
    return head;
}

void display_rev(NODE head)
{
   NODE cur;

}
