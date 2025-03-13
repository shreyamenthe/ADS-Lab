#include<iostream>
using namespace std;
struct Node
{
	string word,meaning;
	Node* left;
	Node* right;
};
class TreeNode
{
    public:
	Node* root;
	
	TreeNode()
    {
        root=NULL;
    }

    void insertNode(string w,string m)
    {
        //root node
        Node* nn=new Node();
        nn->word=w;
        nn->meaning=m;
        if(root==NULL)
        {
            root=nn;
            nn->left=NULL;
            nn->right=NULL;
            return;
        }
        //left and right side
        Node* temp=root;
        do{
            if(nn->word < temp->word)
            {
               if(temp->left==NULL)
               {
                 temp->left=nn;
                 nn->right=NULL;
                 nn->left=NULL;
                 return;
               }
               temp=temp->left;
            }
            else //nn->num > temp->num
            {
                if(temp->right==NULL)
                {
                    temp->right=nn;
                    nn->right=NULL;
                    nn->left=NULL;
                    return;
                }
                temp=temp->right;
            }
        }while(temp!=NULL);
    }
    void inorder(Node* root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<"\t"<<root->word<<" : "<<root->meaning;
            inorder(root->right);
        }
    }
    void preorder(Node* root)
    {
    	if(root!=NULL)
        {
            cout<<"\t"<<root->word<<" : "<<root->meaning;
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(Node* root)
    {
    	if(root!=NULL)
        {
            
            postorder(root->left);
            postorder(root->right);
            cout<<"\t"<<root->word<<" : "<<root->meaning;
        }
    }
    void search(string w)
    {
    	if(root==NULL)
    	{
    		cout<<"\nEmpty tree..";
    		return;
    	}
    	Node* temp=root;
    	do{
    	if(w== temp->word)
    	{
    		cout<<"\nElement found..";
    		return;
    	}
    	else if(w < temp->word)
    		temp=temp->left;
    	else
    		temp=temp->right;
    	}while(temp!=NULL);
    	cout<<"\nElement not found..";
    }
    int height(Node* root)
    {
        if(root!=NULL)
        {
            int lheight=height(root->left);
            int rheight=height(root->right);
            if(lheight>rheight)
            return lheight+1;
            else
            return rheight+1;
            
        }
    }
    Node* clone(Node* root)
    {
        if(root==NULL)
        return root;
        Node* newNode = new Node;
        newNode->word=root->word;
        newNode->meaning=root->meaning;
        newNode->left = clone(root->left);
        newNode->right = clone(root->right);
        return newNode;
    }
    void deleteword(string w)
    {
        if(root==NULL)
        {
            cout<<"\nTree is empty..";
            return;
        }
        //Leaf node
        Node* temp=root;
        Node* temp1=root;
        while(temp)
        {
            if(w==temp->word)
            {
                if(temp->left==NULL && temp->right==NULL)
                {
                    delete temp;
                    if(temp->word>w)
                    {
                        temp1->left=NULL;
                    }
                    else
                    {
                        temp1->right=NULL;
                    }
                }
             
            }
            else if(temp->word > w)
            {
                temp1=temp;
                temp=temp->left;
            }
            else
            {
                temp1=temp;
                temp=temp->right;
            }
        }
    }
};
int main()
{
    TreeNode tn;
    string w,m;
    int num,ch;
    do
    {
        cout<<"\n\n1. Insert Node in tree";
        cout<<"\n2. Inorder Traversal";
        cout<<"\n3. Preorder Traversal";
        cout<<"\n4. Postorder Traversal";
        cout<<"\n5. Search element";
        cout<<"\n6. Delete specific word";
        cout<<"\n7. Clone";
        cout<<"\n8. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nEnter word: ";
            cin>>w;
            cout<<"\nEnter meaning: ";
            cin>>m;
            tn.insertNode(w,m);
            break;

            case 2:
            tn.inorder(tn.root);
            break;
            
            case 3:
            tn.preorder(tn.root);
            break;
            
            case 4:
            tn.postorder(tn.root);
            break;
            
            case 5:
            cout<<"\nEnter word to search: ";
            cin>>w;
            tn.search(w);
            break;

            case 6:
            cout<<"\nEnter word to delete: ";
            cin>>w;
            tn.deleteword(w);
            break;

            case 7:
            tn.clone(tn.root);
            break;

            case 8:
            break;

        }
    }while(ch!=8);
}