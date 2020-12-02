#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int key, height;
	Node* lchild, *rchild;
};

Node* newNode(int v) {//新建结点
	Node* node = new Node;
	node->key = v;
	node->height = 1;
	node->lchild = node->rchild = nullptr;
	return node;
}
int getHeight(Node* root) {//获取高度
	if (root == nullptr) return 0;
	return root->height;
}
int getBalance(Node* root) {//获取平衡因子
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void updateHeight(Node* root) {//更新高度
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void Left(Node* &root) {//左旋
	Node* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void Right(Node* &root) {//右旋
	Node* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void insert(Node *&root, int v) {
	if (root == nullptr) {
		root = newNode(v);
		return;
	}
	if (v < root->key) {//插入左子树
		insert(root->lchild, v);
		updateHeight(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->lchild) == 1)//LL
				Right(root);
			else if (getBalance(root->lchild) == -1) {//LR
				Left(root->lchild);
				Right(root);
			}
		}
	}
	else {//插入右子树
		insert(root->rchild, v);
		updateHeight(root);
		if (getBalance(root) == -2) {
			if (getBalance(root->rchild) == -1)//RR
				Left(root);
			else if (getBalance(root->rchild) == 1) {//RL
				Right(root->rchild);
				Left(root);
			}
		}
	}
}

int main()
{
	int N, v, i;
	Node* root = nullptr;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &v);
		insert(root, v);
	}
	if(root != nullptr)
		printf("%d", root->key);
	return 0;
}