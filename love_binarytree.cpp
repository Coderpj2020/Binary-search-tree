#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;
//lacture 62 :- date(29/01/2023)
//binary tree (tree is non-linear data structre whose node have <=2 child)
/*
  //imp terms
  *Node
  *root (top node is called root)
  *children ()
  *parent
  *siblings (nodes whose parent are same)
  *ancestor (upper nodes of a given node )
  *descendant (lower nodes of given node)
  *leaf ( node whose child is not exist)
*/
//creation of binary tree(diff traversal method,creation from level order traversal)
/*class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this ->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node *root){
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data); 
    cout<<"enter data for inserting in left"<<endl;
    root->left = buildTree(root->left);
    cout<< "Enter data for inserting in left"<<endl;



    root -> right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
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

void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    cout<< root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<" ";
}
// creating tree from levelordertraversal
 node* buildFromLevelOrder(node* root){
    queue<node*>q;
    cout<< "enter data for root" << endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter left node for:"<<root->data << endl;
        int leftData;
        cin>> leftData;
        if(leftData != -1){
            temp -> left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right node for:"<<root->data << endl;
        int rightData;
        cin>> rightData;
        if(rightData != -1){
            temp -> right=new node(rightData);
            q.push(temp->right);
        }

    }
}
int main(){
    node* root=NULL;
    root = buildTree(root);
// creating a tree
    return 0;
}
*/
//reverse level order traversal(homework)
//inorder(LNR)/preorder(NLR)/postorder(LRN) traversal(using iteration homework)

// count leaf nodes
  /* void inorder(BinaryTreeNode<int> * root, int &count){
       // base case
       if(root == NULL){
           return;
       }
       inorder(root->left,count);
       //leaf node
       if(root->left == NULL && root->right==NULL){
           count++:
       }
       inorder(root->right,count);
   }
 int countleafnode(BinaryTreeNode<int> *root){
     int cnt = 0;
     // we can use any traversal so we use inorder traversal
     inorder(root,cnt);
     return cnt;
 }
*/
// lecture 63 (30/01/2023)
//height of binary tree(height :- longest path b/w root node and leaf node)
/*class Solution{
    public:
    int height(struct Node* node){
        //base case
        if(node == NULL){
            return 0;
        }
        int left = height(node -> left);
        int right = height(node ->right);
        int ans = max(left,right)+1;
        return ans;
    }
};*/
// diameter of a binary tree(practice again)
/* // this is o(n^2) tc
 class Solution{
     public:
     int diameter(Node* root){
     //base case
     if(root == NULL){
         return 0;
     }
     int op1 = diameter(root->left);
     int op2 = diameter(root->right);
     int op3 = height(root->left) * height(root->right)+1;
     int ans = max(op1,max(op2,op3));
     return ans;
    }

 };
 //O(n) solution
class Solution{
    public:
    pair<int,int> diameterFast(Node* root){
        // base case
        if(root == NULL){
           pair<int, int> p =make_pair(0,0);
           return p;
        }
        pair<int,int> left = diameterFAst(root->left);
        pair<int,int> right= diameterFast(root->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second +right.second +1;
        pair<int,int>ans;
        ans.first = max(op1,max(op2,op3));
        ans.second= max(left.second,right.second) +1;
        return ans;
    }
    int diameter(Node* root){
        return diameterFast(root).first;
    }
};
*/

//check for balanced tree(balanced tree means height of left and right subtree not differ by one)
/* // O(n^2) solution
class Solution{
    private:
     int height(struct Node* node){
        //base case
        if(node == NULL){
            return 0;
        }
        int left = height(node -> left);
        int right = height(node ->right);
        int ans = max(left,right)+1;
        return ans;
    }
    public:
bool isBalanced(Node* root){
    // base case
     if(root==NULL)
     return true;
      
      bool left = isBalanced(root->left);
      bool right = isBalanced(root->right);
      bool diff = abs(height(root->left) - height(root->right))<=1;
      if(left && right && diff){
          return 1;
      }
      else {
          return false;
      }
}
};
//O(n) tc solution
class Solution{
    public:
    pair<bool,int> isBalancedFast(Node* root){
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
    }
    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);
    
    bool leftAns=left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second)<=1;
    pair<bool,int>ans;
    ans.second = max(left.second,right.second) + 1;
    if(leftAns && rightAns && diff){
        ans.first =1;
    }
    else{
         ans.first=false;
    }
    return ans;
}

bool isBalanced(Node* root){
    return isBalancedFast(root).first;
}
};
 */

// determine if two trees are identical 
/* class Solution{
    pubilc:
    bool isIdentical(Node *r1,Node* r2){
       //base case
       if(r1==NULL && r2==NULL) return true;
       if(r1==NULL && r2!=NULL) return false;
       if(r1!=NULL && r2==NULL) return false;
    }
    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdentical(r1->right,r2->right);
    bool value = r1->data == r2->data;
    if(left && right && value){
        return true;
    }
    else{ return false;}
};*/

//is tree is sum tree
/*
class Solution{
    public:
    pair<bool,int> isSumTreeFast(Node* root){
        //base case
        if(root == NULL){
            pair<bool,int> p= make_pair(true,0);
            return p;
        }
        if(root->left == NULL && root->right == NULL){
            pair<bool,int>p = make_pair(true,root->data);
            return p;
          }
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        bool condn = root->data ==leftAns.second + rightAns.second;
        pair<bool,int> ans;
        if(isLeftSumTree && isRightSumTree && condn){
            ans.first=true; 
            ans.second = root->data + leftAns.second+rightAns.second;
          //or ans.second =2*root->data;
        }
        else{
            ans.first = false;
         }
         return ans;
    }
    bool isSumTree(Node* root){
        return isSumTreeFast(root).first;
    }
};
*/
// lecture_64(01/02/2023)
// Zig-zag traversal
 /* class Solution{
     public:
     vector<int> zifZagTraversal(Node* root){
         vector<int> result;
         if(root == NULL)
         return result;
         queue<Node*>q;
         q.push(root);
         bool leftToRight=true;
         while(!q.empty()){
             int size = q.size();
             vector<int> ans(size);
             //Level process  
              
             for(int i=0;i<size;i++){
             Node* frontNode = q.front();
             q.pop();
             //normal insert or reverse insert
             int index = leftToRight ? i:size -i-1;
             ans[index] = frontNode ->data;
             if(frontNode ->left)
             q.push(frontNode ->left);
             if(frontNode ->right)
             q.push(frontNode ->right);
             }
             //direction change karni he
             leftToRight = !leftToRight;
             for(auto i :ans){
                 result.push_back(i);
             }
             }
             return result;
     }
 };
 */
//boundary traversal(leftpart ,leafnode,rightpart(in reverse order)
 /* class Solution{
    public:
    void  traverseLeft(Node* root,vector<int> &ans){
            //base case
            if((root == NULL) || (root->left == NULL && root->right ==NULL))
                   return ;
                   ans.push_back(root->data);
                  if(root->left)
                  traverseLeft(root->left,ans);
                  else 
                  traverseLeft(root->right,ans);
      }
    
      void traverseLeaf(Node* root,vector<int> &ans){
         //base case
         if(root ==NULL) return;
         if(root-left == NULL && root->right == NULL){
             ans.push_back(root->data);
             return;
         }
         traverseLeaf(root->left,ans);
         traverseLeaf(root->right,ans);
       }
     
      void  traverseRight(Node* root,vector<int> &ans){
            //base case
            if((root == NULL) || (root->left == NULL && root->right ==NULL))
                   return ;
             if(root->right)
             traverseLeft(root->right,ans);
             else
             traverseLeft(root->left,ans);
             //push on reversing time
             ans.push_back(root->data);
        }

vector<int> boundary(Node* root){
    vector<int>ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);

    //left part print 
    traverseLeft(root->left,ans);
    //traverse leaf Nodes
     // * left subtree
     traverseLeaf(root-left,ans);
     // * right subtree
     traverseLeaf(root->right,ans);
    //traverse right part
    traverseRight(root->right,ans);
    return ans;
}
};
*/
//vertical traversal of binary tree
  /*class Solution{
      public:
      vector<int> verticalOrder(Node* root){
          map<int,map<int,vector<int>>> nodes;
          queue<pair<Node*,pair<int,int>>>q;
          vector<int>ans;
        if(root == NULL) return ans;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int>>temp=q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            nodes[hd][lvl].push_back(frontNode->data);
            if(frontNode->left)
            q.push(make_pair(frontNode->left,make_pair(hd+1,lvl-1)));
            if(frontNode->right)
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
       }
       for(auto i:nodes){
           for(auto j:i.second){
               for(auto k:j.second)
               {
                   ans.push_back(k);
               }
           }
       }
         return ans;
      }
  };
  */
 // top view
 /*class Solution{
     vector<int> topView(Node* root){
         vector<int> ans;
         if(root == NULL) return ans;
         map<int,int> topNode;
         queue<pair<Node*,int>q;
         q.push(make_pair(root,0));
         while(!q.empty()){
             pair<Node*,int> temp =q.front();
             Node* frontNode =temp.first;
             int hd = temp.second;
             // if one value is present for a HD ,then do nothing
             if(topNode.find(hd)==topNode.end())
              topNode[hd]=frontNode->date;
              if(frontNode->left)
              q.push(make_pair(frontNode->left,hd-1))
              if(frontNode->right)
              q.push(make_pair(frontNode->right,hd+1))
              
         }
         for(auto i:topNode){
             ans.push_back(i.second);
         }
         return ans;
     }
 }; */
//bottome ,left,right view (try ones);

//practice
// creation of binary tree
class node {
    public:
     int data;
     node* left;
     node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
   node* buildTree(node* root){
        cout<<"enter the data:"<<endl;
        int data;
        cin>>data;
        root = new node(data);
         //base case
       if(data==NULL)return root;
      cout<<"enter data for left node"<<endl;
       root->left=buildTree(root->left);
       //similarly
       cout<<"enter data for right node"<<endl;
       root->right=buildTree(root->right);
       return root;
    }
// traversal 
// level order traversal
void levelOrdertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
       node* temp=q.front();
       q.pop();
       if(temp== NULL){
           cout<<endl;
           if(!q.empty()){q.push(NULL);}
       }
       else{
           cout<<temp->data<<" ";
           if(temp->left){
               q.push(temp->left);
           }
           if(temp->right){
               q.push(temp->right);
           }
       }
    }
}
 
int main(){
    node* root=NULL;
    root=buildTree( root);
    levelOrdertraversal(root);
   return 0;
   
} 













































































