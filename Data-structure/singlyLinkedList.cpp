#include <bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node *next;
};

class LinkedList
{
private:
    node *head, *tail;
    int length;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void insertAtEnd(int data)
    {
        node *newNode=new node;
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            newNode=NULL;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        length++;
    }

    void insertAtAnyPosition(int data, int position){
        node *newNode=new node;
        newNode->data=data;
        newNode->next=NULL;
        if(position == 0){
            newNode->next = head;
            head = newNode;
        }else {
            node *current=new node;
            current = head;
            int cnt = 1;
            while(cnt < position && cnt< length){
                current = current->next;
                cnt++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        length++;
    }

    void deleteAtAnyPosition(int position){
        if(position>length || length==0){
            printf("Invalid position");
            return;
        }
        node *current=new node;
        current = head;
        node *previous;
        previous = NULL;

        if(position ==0){
            head = head->next;
            delete current;
        }else {
            for(int i=0;i<length;i++){
                if(i==position){
                    previous->next = current->next;
                    delete current;
                    break;
                }

                previous = current;
                current = current->next;
            }
        }
    }

    bool searchByValue(int value){
        node *current=new node;
        current = head;

        while(current!=NULL){
            if(current->data == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printList()
    {
        node *current = new node;
        current = this->head;
        while(current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
};
int main()
{
    LinkedList li=LinkedList();
    li.insertAtEnd(50);
    li.insertAtEnd(55);
    li.insertAtEnd(51);
    li.printList();
    li.insertAtAnyPosition(69, 2);//0 based index
    li.printList();
    li.deleteAtAnyPosition(1);
    li.printList();
    printf("%d\n", li.searchByValue(69));
}
