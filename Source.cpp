#include <iostream>

using namespace std;

typedef int DataType;
typedef struct Node* Po;
//int cnt = 0;
struct Node
{
	int data;
	Po left;
	Po right;
};
void Prefix(Po help) {
	
	if (help!=nullptr)
	{
		cout << help->data<<" ";
		Prefix(help->left);
		Prefix(help->right);
	}
}
void Postfix(Po help) {
	
	if (help != nullptr)
	{
		Postfix(help->left);
		Postfix(help->right);
		cout << help->data << " ";
	}
}
void Infix(Po help) {
	
	if (help != nullptr)
	{
		//cout << '(';
		Infix(help->left);
		
		cout << help->data << " ";

		Infix(help->right);
	//	cout << ")";
	}
}
Po IBD(int n) {
	Po darj;
	int x;
	if (n > 0) {
		
		cout << " kopie nomer - " << n << endl;
		int nl = n / 2 ;
		int nr = n - nl - 1;
		darj = new Node;
		cout << "vuvedi danna za vuzela: ";
		cin >> x;
		int temp = x; 
		cout << endl;
		
		darj->data = x;			
		darj->left = IBD(nl);
		darj->right = IBD(nr);

		return darj;
	}
	else
	{
		//duno
		return nullptr;
	}
}
void print2DUtil(Po root, int space)
{
	int COUNT=5;
	// Base case  
	if (root == NULL)
		return;

	
	space += COUNT;

	
	print2DUtil(root->right, space);
    cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << "\n";
	print2DUtil(root->left, space);
}
int main() {
	int n;
	Po root;

	cout << "vuvedi broi vuzli: ";
	cin >> n;
	cout << endl;
	root = IBD(n);
	print2DUtil(root, 2);
	cout << " prefix: " << endl;
	Prefix(root);
	cout << endl << " postfix: " << endl;
	Postfix(root);
	cout << endl << " infix: " << endl;
	Infix(root);
	return 0;
}