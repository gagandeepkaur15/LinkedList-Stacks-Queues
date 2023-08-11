#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertAtTail(Node* &cloneHead, Node* &cloneTail, int d){
       if(cloneTail==NULL){
           Node* node=new Node(d);
           cloneTail=node;
           cloneHead=node;
       } 
       else{
           Node* node=new Node(d);
           cloneTail->next=node;
           cloneTail=node;
       }
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp=temp->next;
        }

        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;

            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next; 
        }

        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random=temp->random->next;
                    temp=temp->next->next;
                }
            } else{
                temp->next=temp->random;
                temp=temp->next->next;
            }          
        }

        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;

            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};