//amjeshtri21
#include <stdio.h>
#include <stdlib.h>

struct nOperation
{
    int num;
    struct nOperation *link;
};

typedef struct nOperation NODE;
typedef struct nOperation *nodePtr;
//nodePtr First;
void createList(int n,nodePtr *First);
void addNodeEnd(NODE nd,nodePtr *First);
void addNodeFront(NODE nd,nodePtr *First);
void addNodeSorted(nodePtr *First,int n,NODE nd);
void addNodePos(int pos,NODE nd,nodePtr *First);
void deleteEnd(nodePtr *First);
void deleteFront(nodePtr *First);
void deleteNodeVal(nodePtr *First,NODE nd);
void deleteNodeAtPos(int pos,NODE nd,nodePtr *First);
int count(nodePtr First);
void display(nodePtr First);
int main()
{
    int n;
    nodePtr First=NULL;
    printf("Enter the number of Nodes: ");
    scanf("%d",&n);
    createList(n,&First);
    NODE nd;
    while(1)
    {
        system("cls");
        printf("\n*********************************\n");
        printf("*\tList Of Operations\t*\n");
        printf("*\t\t\t\t*\n");
        printf("* 1.Insert to the END\t\t*\n");
        printf("* 2.Insert to the FRONT\t\t*\n");
        printf("* 3.Insert Sorted \t\t*\n");
        printf("* 4.InsertNodeAtPos\t\t*\n");
        printf("* 5.deleteEnd \t\t\t*\n");
        printf("* 6.deleteFront\t\t\t*\n");
        printf("* 7.deleteNodeVal\t\t*\n");
        printf("* 8.deleteNodeAtPos\t\t*\n");
        printf("* 9.Display\t\t\t*\n");
        printf("* 10.Size\t\t\t*\n");
        printf("* 11.Exit\t\t\t*\n");
        printf("*\t\t\t\t*\n");
        printf("*********************************");

        int choice;
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice<1)
        {
            printf("Enter an integer: ");
            exit(0);
        }
        else
        {
            switch(choice)
            {
                case 1:
                {
                    printf("Enter the number to insert:");
                    scanf("%d",&nd.num);
                    addNodeEnd(nd,&First);
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");//makes the system wait for a key press
                    break;
                }
                case 2:
                {
                     printf("Enter the number to insert:");
                     scanf("%d",&nd.num);
                     addNodeFront(nd,&First);
                     printf("Elements in the list are:\n");
                     display(First);
                     system("pause");
                     break;
                }
                case 3:
                {
                    printf("Enter the number to insert:");
                    scanf("%d",&nd.num);
                    addNodeSorted(&First,n,nd);
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");
                    break;
                }
                case 4:
                {
                    int pos;
                    printf("Enter the position to insert:");
                    scanf("%d",&pos);
                    printf("Enter the number to insert:");
                    scanf("%d",&nd.num);
                    addNodePos(pos,nd,&First);
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");
                    break;
                }
                case 5:
                {
                    deleteEnd(&First);
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");
                    break;
                }
                case 6:
                {
                    deleteFront(&First);
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");
                    break;
                }
                case 7:
                {
                    printf("Enter the number to delete:");
                    scanf("%d",&nd.num);
                    deleteNodeVal(&First,nd);
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");
                    break;
                }
                case 8:
                {
                    int pos;
                    printf("Enter the input position:");
                    scanf("%d",&pos);
                    deleteNodeAtPos(pos,nd,&First);
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");
                    break;
                }
            case 9:
                {
                    printf("Elements in the list are:\n");
                    display(First);
                    system("pause");
                    break;
                }
                 case 10:
                {
                    printf("The size of the list is: %d\n",count(First));
                    system("pause");
                    break;
                }
            case 11:
                {
                    return 0;
                }
            default:
                printf("Invalid option:\n");
            }
        }
    }
    return 0;
}
void createList(int n,nodePtr *First)
{
    nodePtr Last,newNode;
    *First=Last=NULL;
    for(int i=0;i<n;i++)
    {
        newNode=(nodePtr)malloc(sizeof(NODE));
        printf("\n\nThe address of the %d node: %d\n",i+1,newNode);
        printf("Enter the data of the %d node:\n",i+1);
        printf("Enter the num:");
        scanf("%d",&newNode->num);
        newNode->link=NULL;
        if(*First==NULL)
        {
            *First=newNode;
            Last=newNode;
        }
        else
        {
            newNode->link=NULL;
            Last->link=newNode;
            Last=newNode;
        }
    }
}
void addNodeEnd(NODE nd,nodePtr *First)
{
    nodePtr temp,newNode;
    temp=*First;
    newNode=(nodePtr)malloc(sizeof(NODE));
    newNode->num=nd.num;
    while(temp->link!=NULL)
    {
        temp=temp->link;
        //printf("First is: %d\n",temp);
    }
    newNode->link=NULL;
    temp->link=newNode;
}
void addNodeFront(NODE nd,nodePtr *First)
{
    nodePtr newNode;
    newNode=(nodePtr)malloc(sizeof(NODE));
    newNode->num=nd.num;
    newNode->link=*First;
    *First=newNode;
}
void addNodeSorted(nodePtr *First, int n, NODE nd)
{

    nodePtr prevNode,temp,newNode;
    newNode=(nodePtr)malloc(sizeof(NODE));
    newNode->num=nd.num;
    newNode->link=NULL;
    if(*First==NULL)
    {
        *First=newNode;
        return;
    }
    temp=*First;
    if(newNode->num > temp->num)
    {
        newNode->link=temp;
        *First=newNode;
    }
    else
    {
        while((temp!=NULL) && (newNode->num < temp->num))
        {
            prevNode=temp;
            temp=temp->link;
        }
        if(temp==NULL)
        {
            temp->link=newNode;
            //newNode->link=NULL;
        }
        else
        {
            prevNode->link=newNode;
            newNode->link=temp;
        }
    }
}
void addNodePos(int pos,NODE nd,nodePtr *First)
{
    nodePtr temp,newNode,prev;
    temp=*First;
    newNode=(nodePtr)malloc(sizeof(NODE));
    newNode->num=nd.num;
    for(int i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->link;
    }
    newNode->link=temp;
    prev->link=newNode;
}
void deleteEnd(nodePtr *First)
{
    nodePtr temp=*First,prev;
    while(temp->link!=NULL)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
}
void deleteFront(nodePtr *First)
{
    //nodePtr temp=*First;
    //temp=temp->link;or
    *First=(*First)->link;
}
void deleteNodeVal(nodePtr *First,NODE nd)
{
    nodePtr temp,prev;
    temp=*First;
    if(nd.num==(*First)->num)//Delete the value in the beginning
    {
        *First=(*First)->link;
        free(temp);
    }
    while((temp!=NULL)&&(temp->num!=nd.num))//iterate until you find the value required (if this value exists in the list)
    {
        prev=temp;//save the previous node and move to the next one
        temp=temp->link;
    }
    if(temp==NULL)
    {
        printf("No match found: Deletation failed!\n");//show the message on the screen if the value is not found in the list
    }
    else if(temp->num==nd.num)
    {
        prev->link=temp->link;
        free(temp);
    }
}
void deleteNodeAtPos(int pos,NODE nd,nodePtr *First)
{
    nodePtr temp=*First,prev;
    for(int i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=temp->link;
}
int count(nodePtr First)
{
    int counter=0;
    while(First!=NULL)
    {
        counter++;
        First=First->link;
    }
    return counter;
}
void display(nodePtr First)
{

    while(First!=NULL)
    {
        printf("%d %d\n",First->num,First->link);
        First=First->link;
    }
}
