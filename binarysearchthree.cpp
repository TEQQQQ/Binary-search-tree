#include <iostream>
using namespace std;

class Treenode{
	public:
		int data;
		Treenode*left;
		Treenode*right;
		Treenode(int x){
			data = x;
			left = NULL;
			right = NULL;
		}
};

enum MOD{PREORDER,INORDER,POSTORDER};

class binarytree{
	Treenode * root;
	
	public:
		binarytree(Treenode*root = NULL){
			root = NULL;
		}
		
		bool bosmu();
		
		Treenode*getroot()const{return root;}
		
		Treenode*find(Treenode*start,int data){
			if(start){
				if(data<start->data){
					return find(start->left,data);
					
				} else if(start->data < data){
					return find(start->right,data);
					
				}
			}
			return start;
		}
		
		Treenode*find(int data){
			return find(root,data);
		}
		
		Treenode * insert(Treenode * start,int data){
			if(start){
				if(data < start->data){
					start->left = insert(start->left,data);
				} else {
					start->right = insert(start->right,data);
				}
			} else {
				return new Treenode(data);
			}
			return start;
		}
		
		Treenode * getMin(Treenode*start){
			while(start && start->left){
				start = start->left;
			}
			return start;
		}
		
		Treenode * getMin(){
			return getMin(root);
		}
		
		Treenode * getmax(Treenode*start){
			while(start && start->right){
				start = start->right;
			} 
			return start;
		}
		
		Treenode * getmax(){
			return getmax(root);
		}
		
		Treenode * remove(Treenode * start, Treenode * deleted){
			if(start){
				if(deleted->data < start->data){
					start->left = remove(start->left,deleted);
				} else if(start->data < deleted->data) {
					start->right = remove(start->right,deleted);
				
				} else if(start == deleted) {
					Treenode * temp =NULL;
					if(start->left && start->right){
						temp = getMin(start->right);
						remove(start,temp);
						temp->left = start->left;
						temp->right = start->right;
					} else if(start->left) {
						temp = start->left;
					
					} else if(start->right){
						temp = start->right;
						
					}
					return temp;
				
				} else {
					start->right = remove(start->right,deleted);
				}
				
			}
			return start;
		}
		
		void remove(Treenode*node){
			if(node){
				root = remove(root,node);
				delete node;
			}
		}
		
		void remove(int data){
			remove(find(data));
		}
		
		void insert(int x);
		
		void preorder(Treenode*start);
		
		void inorder(Treenode * start);
		
		void postorder(Treenode * start);
		
		void print(MOD mod);
		
		int height(Treenode * node);
		
		int depth(Treenode * start, Treenode * finish);
		
		
			
		
};

void binarytree::insert(int x){
	root = insert(root,x);
	
}

bool binarytree::bosmu(){
	if(root==NULL){
		return true;
	} else {
		return false;
	}
}

int binarytree::height(Treenode*node){
	
	if(node){
		int left = height(node->left);
		int right = height(node->right);
		return 1+max(left,right);
	} else {
		return -1;
	}
	
}

int binarytree::depth(Treenode * start,Treenode*finish){
	if(start){
		if(start==finish){
			return 0;
			
		} else {
			int left = depth(start->left,finish);
			int right= depth(start->right,finish);
			return 1 + max(left,right);
		}
	} else {
		return INT_MIN;
	}
}


void binarytree::preorder(Treenode*start){
	if(start){
		cout<<start->data<<" ";
		preorder(start->left);
		preorder(start->right);
	}
}

void binarytree::inorder(Treenode*start){
	if(start){
		inorder(start->left);
		cout<<start->data<<" ";
		inorder(start->right);
	}
}

void binarytree::postorder(Treenode*start){
	if(start){
		postorder(start->left);
		postorder(start->right);
		cout<<start->data<<" ";
	}
}

void binarytree::print(MOD mod){
	switch(mod){
		case PREORDER:
			preorder(root);
			break;
		case INORDER:
			inorder(root);
			break;
		case POSTORDER:
			postorder(root);
			break;
	}
}


int main(){
	binarytree s1;
	s1.insert(30);
	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(50);
	s1.insert(70);
	s1.insert(60);
	cout<<s1.bosmu()<<endl;
	cout<<"PREORDER:"<<endl;
	s1.print(PREORDER);
	cout<<"INORDER:"<<endl;
	s1.print(INORDER);
	cout<<"POSTORDER"<<endl;
	s1.print(POSTORDER);
	cout<<s1.find(302)<<endl;
	
	cout<<s1.getMin()->data<<endl;
	cout<<s1.getmax()->data<<endl;
	
	s1.remove(70);
	s1.print(POSTORDER);
	
	
}
