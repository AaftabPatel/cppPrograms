//program for implementing max heap
#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right, *prev;
};

class heap{
    public:
        node *root;
        heap(){            //constructor
            root=NULL;
        }

        void insert(int num){           //function to add element in binary tree
            node *r, *temp, *p;
            r=new node;
            r->data=num;
            r->left=r->right=r->prev=NULL;
            if(root==NULL)
                root=r;
            else{
                temp=root;
                while (temp!=NULL)
                {
                    p=temp;
                    if(temp->data>num)
                        temp=temp->right;
                    else
                        temp=temp->left;
                }
                if(p->data<num){
                    p->left=r;
                    r->prev=p;
                    }
                else{
                    p->right=r;
                    r->prev=p;
                    }
                }
                check(r, p);                
            cout<<"Element inserted\n";
        }
        
        void check(node *r, node *p){
            while(r!=root){
               if(r->data>p->data){
                   int s=r->data;
                   r->data=p->data;
                   p->data=s;
               } 
               else{
                   p=p->prev;
                   r=r->prev;
               }
            }
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
                                       
        void del(){          //function to delete root element
            node *r;
            r = root;
            int t=0;
            if(root == NULL){
                cout << "\nThe tree is empty!!";
                return;
            }
            else{
                if(r->left!=NULL){
                    while(r->left!=NULL){
                        r=r->left;
                    }
                    t=1;
                }
                else{
                    while(r->right!=NULL){
                        r=r->right;
                    }
                    t=-1;
                }
                root->data=r->data;
            }
            if(t==1){
                r->prev->left=NULL;
            }
            else if(t==-1)
                r->prev->right=NULL;
            cout << "\nroot deleted";
        }

};

int main() {
   heap h;
   int ch;
   do {
        cout<<"\n1) Insert in heap"<<endl;
        cout<<"2) Preorder Traversal[P L R]"<<endl;
        cout<<"3) Postorder Traversal[L R P]"<<endl;
        cout<<"4) Inorder Traversal[L P R]"<<endl;
        cout<<"5) Delete root element"<<endl;
        cout<<"6) Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
         case 1: {
            int item;
            cout<<"Please enter the element to insert:";
            cin>>item;
            h.insert(item);
            break;
         }
         case 2: {
            node *r1;
            r1=h.root;
            if(r1==NULL)
                cout<<"Empty Tree!!";
            else{
                cout<<"Preorder Traversal is:\n";
                h.preorder(r1);
            }
            break;
         }
         case 3: {
            node *r2;
            r2=h.root;
            if(r2==NULL)
                cout<<"Empty Tree!!";
            else{
                cout<<"Postorder Traversal is:\n";
                h.postorder(r2);
            }
            break;
         }
         case 4: {
            node *r3;
            r3=h.root;
            if(r3==NULL)
                cout<<"Empty Tree!!";
            else{
                cout<<"Inorder Traversal is:\n";
                h.inorder(r3);
            }
            break;
         }
         case 5: {
            h.del();
            break;
         }
         case 6: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
        }
    }
   while(ch!=6);
   return 0;
}