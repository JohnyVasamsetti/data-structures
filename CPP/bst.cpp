// Binary Search Tree implementation using linked list

#include <iostream>
#include<queue>
using namespace std;

// structure
struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};

// getting a node in heap
BstNode* GetNewNode(int data){
	BstNode* temp = new BstNode();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// inserting a node
BstNode* Insert(BstNode* root, int data){
	if (root == NULL){
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data){
		root->left = Insert(root->left,data);
	}
	else{
		root->right = Insert(root->right,data);
	}
	return root;
}

// searching a node
bool Search(BstNode* root,int data){
	if (root == NULL){
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(root->data >= data){
		return Search(root->left,data);
	}
	else{
		return Search(root->right,data);
	}
}
// finding the node for a value
BstNode* Find(BstNode* root,int data){
	if (root == NULL){
		return NULL;
	}
	else if(root->data == data){
		return root;
	}
	else if(root->data >= data){
		return Find(root->left,data);
	}
	else{
		return Find(root->right,data);
	}
}

// finding the min of a tree
BstNode* FindMin(BstNode* root){
	if (root == NULL){
		return NULL;
	}
	else if (root->left == NULL){
		return root;
	}
	else{
		return FindMin(root->left);
	}
}

// finding the max of a tree
BstNode* FindMax(BstNode* root){
	if (root == NULL){
		return NULL;
	}
	else if (root->right == NULL){
		return root;
	}
	else{
		return FindMax(root->right);
	}
}

// finding the Height of a tree
int FindHeight(BstNode* root){
	if (root == NULL){
		return -1;
	}
	return max(FindHeight(root->left),FindHeight(root->right)) + 1;
}

// Printing the BFS of a tree (level order traversal)
void LevelOrder(BstNode * root){
	if (root == NULL) return;
	else{
		queue<BstNode*> Q;
		Q.push(root);
		while(!Q.empty()){
			BstNode* current = Q.front();
			cout << current->data << " ";
			if(current->left) Q.push(current->left);
			if(current->right) Q.push(current->right);
			Q.pop();
		}
	}
	cout << endl;
}

// Printing the DFS(3 types) of a tree (level order traversal)
// 1.Preorder Traversal
void preorder(BstNode* root){
	if (root == NULL){
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

// 2.Inorder Traversal
void inorder(BstNode* root){
	if (root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
// 3.Postorder Traversal
void postorder(BstNode* root){
	if (root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
// Finding if a tree is Binary tree or not
bool IsSubtreeLesser(BstNode* root,int data){
	if (root == NULL) return true;
	if (root->data <= data && IsSubtreeLesser(root->left,data) && IsSubtreeLesser(root->right,data)){
		return true;
	}
	return false;
}

bool IsSubtreeGreater(BstNode* root,int data){
	if (root == NULL) return true;
	if (root->data > data && IsSubtreeGreater(root->left,data) && IsSubtreeGreater(root->right,data)){
		return true;
	}
	return false;
}

bool IsBinarySubtree(BstNode* root){
	if (root == NULL) return true;
	if ( IsSubtreeLesser(root->left,root->data) && IsSubtreeGreater(root->right,root->data) && IsBinarySubtree(root->left) && IsBinarySubtree(root->right)){
		return true;
	}
	return false;
}

bool IsBinarySubtree2(BstNode* root){
	if (root == NULL) return true;
	if ( (FindMax(root->left)->data < root->data) && FindMin(root->right)->data > root->data && IsBinarySubtree2(root->left) && IsBinarySubtree2(root->right) ){
		return true;
	}
	return false;
}
bool IsBstUtil(BstNode* root,int min,int max){
	if (root == NULL) return true;
	if (root->data > min && root->data < max && IsBstUtil(root->left,min,root->data) && IsBstUtil(root->right,root->data,max)){
		return true;
	}
	return false;
}

bool IsBinarySubtree3(BstNode* root){
	return IsBstUtil(root,INT8_MIN,INT8_MAX);
}
// Another way is if we perform a inorder traversal for a tree then it returns a sorted list.

// end

// delete a node
BstNode* Delete(BstNode * root,int value){
	if (root == NULL) return root;
	else if (value < root->data ){
		root->left = Delete(root->left,value);
	}
	else if(value > root->data){
		root->right = Delete(root->right , value);
	}
	else{
		if (root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if (root->left == NULL){
			struct BstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL){
			struct BstNode* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			struct BstNode* temp = FindMax(root->left);
			root->data = temp->data;
			root->left = Delete(root->left,temp->data); // we need to delete the duplicate node in left sub tree.It will again search for temp->value in LST and delete it.
		}
		return root;
	}
	return root;
}

// successor , The next high value , Min(right) because already left and current nodes are visited.
BstNode* Successor(BstNode* root,int value){
	struct BstNode* current = Find(root,value);
	if (current == NULL){
		return NULL;
	}
	else if(current->right != NULL){
		return FindMin(current->right);
	}
	else{
		struct BstNode* ancestor = root;
		struct BstNode* successor = NULL;
		while(ancestor != current){
			if (current->data < ancestor->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}
int main()
{
	BstNode* root = NULL;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	// int number;
	// cout << "Enter to be searched: " ;
	// cin >> number;
	// if ( Search(root,number) ){
	// 	cout << "Found\n" ;
	// }
	// else{
	// 	cout << "Not Found\n";
	// }
	// if (Find(root,number)){
	// 	cout << "Found\n";
	// }
	// else{
	// 	cout << "Not Found\n";
	// }
	// cout << endl;


	// cout << "Min: " << FindMin(root)->data << endl;
	// cout << "Max: " << FindMax(root)->data << endl;
	// cout << "Height Of a Tree " << FindHeight(root) << "\n" ;
	// cout << endl;

	// cout << "BFT:" <<  endl;
	// cout << "\tLevel Order: ";LevelOrder(root);
	// cout << "DFS:" << endl;
	// cout << "\t1.preorder : ";preorder(root); cout << endl;
	// cout << "\t2.inorder : " ;inorder(root) ;  cout << endl;
	cout << "\t1.postorder : ";postorder(root);  cout << endl;
	// cout << endl;


	// cout << "IBST: " << IsBinarySubtree(root) << endl;
	cout << "IBST: " << IsBinarySubtree2(root) << endl;
	// cout << "IBST: " << IsBinarySubtree3(root) << endl;
	// cout << endl;

	// root = Delete(root,10);
	// cout << "After Delete: ";inorder(root);
	// cout << endl;

	// cout << "Successor(20): " << Successor(root,20)->data;
	// cout << endl;

	return 0;
}