#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;
//lecture_69(11/02/2023)
// binary search tree
 //construction
  class Node{
      public:
      int data;
      Node* left;
      Node* right;
      Node(int d){
          this->data =d;
          this->left=NULL;
          this->right=NULL;
      }
  };
    Node* insertIntoBST(Node* root,int d){
        //base case
        if(root == NULL){
             root = new Node(d);
             return root;
        }
        if(d>root ->data){
            //right part me insert karna h
            root->right = insertIntoBST(root->right,d);
        }       
      else {
          // left part me inset karna h
          root->left= insertIntoBST(root ->left,d);
      }
      return root;
    }
  void takeInput(Node* &root){
      int data; 
      cin>>data;
      while(data!=-1){
         root= insertIntoBST(root,data);
          cin>>data;
      }
  }
    void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp == NULL){
            //purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else {
            cout<< temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp -> right);
            }
        }
    }
}


      int main(){
          Node* root=NULL;
          cout<<"Enter data to create BST"<<endl;
          takeInput(root);
          cout<<"Printing the bst"<<endl;
          levelOrderTraversal(root);
          return 0;
      }

















