#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 30;
typedef struct node
{
	int data;
	node* lchild;
	node* rchild;
}Node;
int post[maxn], in[maxn], N;
Node * post_in_create_tree(int postL, int postR, int inL, int inR)
{
	if (postL > postR) return nullptr;
	Node *root = new Node;
	root->data = post[postR];
	root->lchild = root->rchild = nullptr;
	int i;
	for (i = inL; i <= inR; ++i)
	{
		if (in[i] == post[postR])
			break;
	}
	int numLeft = i - inL;//左子树的节点数
	root->lchild = post_in_create_tree(postL, postL + numLeft - 1, inL, i - 1);
	root->rchild = post_in_create_tree(postL + numLeft, postR - 1, i + 1, inR);
	return root;
}

void levelOrder(Node* root)
{
	queue<Node*> que;
	if (root) que.push(root);
	int i = 0;
	while (!que.empty())
	{
		auto top = que.front();
		if (i)
			printf(" ");
		printf("%d", top->data);
		++i;
		que.pop();
		if (top->lchild) que.push(top->lchild);
		if (top->rchild) que.push(top->rchild);
	}
}

int main()
{
	int ret = scanf("%d", &N);
	int i;
	for (i = 0; i < N; ++i){
		ret = scanf("%d", &post[i]);
	}
	for (i = 0; i < N; ++i){
		ret = scanf("%d", &in[i]);
	}
	Node* root = post_in_create_tree(0, N - 1, 0, N - 1);
	levelOrder(root);
	return 0;
}