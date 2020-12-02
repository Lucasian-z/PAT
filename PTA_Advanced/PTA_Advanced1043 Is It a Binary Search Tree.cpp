#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
struct node {
	int key;
	node* lchild;
	node* rchild;
};

void insert(node*& root, int x) {
	if (root == nullptr) {
		root = new node;
		root->key = x;
		root->lchild = root->rchild = nullptr;
		return;
	}
	if (x < root->key)
		insert(root->lchild, x);
	else insert(root->rchild, x);
}

void preOrder(node* BST, vector<int> &vi) {
	if (BST == nullptr) return;
	vi.push_back(BST->key);
	preOrder(BST->lchild, vi);
	preOrder(BST->rchild, vi);
}

void mirrorPreOrder(node* BST, vector<int>& vi) {
	if (BST == nullptr) return;
	vi.push_back(BST->key);
	mirrorPreOrder(BST->rchild, vi);
	mirrorPreOrder(BST->lchild, vi);
}

void postOrder(node* BST, vector<int>& vi) {
	if (BST == nullptr) return;
	postOrder(BST->lchild, vi);
	postOrder(BST->rchild, vi);
	vi.push_back(BST->key);
}

void mirrorPostOrder(node* BST, vector<int>& vi) {
	if (BST == nullptr) return;
	mirrorPostOrder(BST->rchild, vi);
	mirrorPostOrder(BST->lchild, vi);
	vi.push_back(BST->key);
}

int main()
{
	int N = 0;
	int ret = scanf("%d", &N);
	vector<int> origin;
	int num;
	node* tree = nullptr;
	for (int i = 0; i < N; ++i) {
		ret = scanf("%d", &num);
		origin.push_back(num);//原始序列
		insert(tree, num);
	}
	vector<int> ivec[4];//分别存储前序，镜像前序，后序，镜像后序
	preOrder(tree, ivec[0]);
	mirrorPreOrder(tree, ivec[1]);
	postOrder(tree, ivec[2]);
	mirrorPostOrder(tree, ivec[3]);
	if (ivec[0] == origin) {
		printf("YES\n");
		for (int i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", ivec[2][i]);
		}
	}
	else if (ivec[1] == origin) {
			printf("YES\n");
			for (int i = 0; i < N; ++i) {
				if (i) printf(" ");
				printf("%d", ivec[3][i]);
		}
	}
	else printf("NO");
	return 0;
}