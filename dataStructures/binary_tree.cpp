//program for binary search tree
#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

class btree{
    public:
        node *root;
        btree(){            //constructor
            root=NULL;
        }

        void insert(int num){           //function to add element in binary tree
            node *r, *temp, *prev;
            r=new node;
            r->data=num;
            r->left=r->right=NULL;
            if(root==NULL)
                root=r;
            else{
                temp=root;
                while (temp!=NULL)
                {
                    prev=temp;
                    if(temp->data>num)
                        temp=temp->right;
                    else
                        temp=temp->left;
                }
                if(prev->data>num)
                    prev->left=r;
                else
                    prev->right=r;
                }                
            cout<<"Element inserted\n";
        }
        
        void preorder(node *t){           //function to do preorder traversal
            if(t!=NULL){
                cout<<" "<<t->data;
                preorder(t->left);
                preorder(t->right);
            }
        }

        void inorder(node *t){          //function to do inorder traversal
            if(t!=NULL){
                inorder(t->left);
                cout<<" "<<t->data;
                inorder(t->right);
            }
        }

        void postorder(node *t){        //function to do postorder traversal
            if(t!=NULL){
                postorder(t->left);
                postorder(t->right);
                cout<<" "<<t->data;
            }
        }  
                                       
        void del(int num){          //function to delete an element
            node *r,*temp,*prev;
            r = root;
            if(root == NULL){
                cout << "\nThe tree is empty!!";
                return;
            }
            
            else{
                int t=0;
                while(r!=NULL){
                    if(r->data == num){
                        while(r->right!=NULL || r->left!=NULL){
                            if(r->left!=NULL){
                                r->data=r->left->data;
                                r=r->left;
                            }
                            else if(r->right!=NULL){
                                r->data=r->right->data;
                                r=r->right;
                            }
                        }
                        delete r;
                        return;                    
                    }
                    else if(r->data>num){ 
                        prev = r;
                        r = r->right;
                    }
                    else{ 
                        prev = r;
                        r = r->left;
                    }
                }
            }
            cout << "\n\nElement deleted";
        }
        void duplicate(int value){
            node *r;
            r=root;
            trav(r,value);
            if(r!=NULL){
                r=r->left;
                duplicate(value);
                r=r->right; 
                duplicate(value); 
            }
        }

        void trav(node *r,int value)
        {
            if(r==NULL)
                return ;
            else if(value < r->data)
            {
                trav(r->left,value);
            }
            else if(value > r->data)
            {
                trav(r->right,value);
            }
            else if(value==r->data){
                cout<<"duplicate found",value;
                return;
            }
            else
                cout<<"NO duplicates";
        }

};

int main() {
   btree bt;
   int ch;
   do {
        cout<<"\n1) Insert in binary tree"<<endl;
        cout<<"2) Preorder Traversal[P L R]"<<endl;
        cout<<"3) Postorder Traversal[L R P]"<<endl;
        cout<<"4) Inorder Traversal[L P R]"<<endl;
        cout<<"5) Delete an element"<<endl;
        cout<<"6) Remove duplicates"<<endl;
        cout<<"7) Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
         case 1: {
            int item;
            cout<<"Please enter the element to insert:";
            cin>>item;
            bt.insert(item);
            break;
         }
         case 2: {
            node *r1;
            r1=bt.root;
            if(r1==NULL)
                cout<<"Empty Tree!!";
            else{
                cout<<"Preorder Traversal is:\n";
                bt.preorder(r1);
            }
            break;
         }
         case 3: {
            node *r2;
            r2=bt.root;
            if(r2==NULL)
                cout<<"Empty Tree!!";
            else{
                cout<<"Postorder Traversal is:\n";
                bt.postorder(r2);
            }
            break;
         }
         case 4: {
            node *r3;
            r3=bt.root;
            if(r3==NULL)
                cout<<"Empty Tree!!";
            else{
                cout<<"Inorder Traversal is:\n";
                bt.inorder(r3);
            }
            break;
         }
         case 5: {
            int d;
            cout<<"Enter the element to delete:";
            cin>>d;
            bt.del(d);
            break;
         }
         case 6:{
            node *r4;
            bt.duplicate(r4->data);
            break;
         }
         case 7: {
            cout<<"Exit"<<endl;
            break;
         }
        
         default: {
            cout<<"Invalid Choice"<<endl;
         }
        }
    }
   while(ch!=7);
   return 0;
}