// BOJ 12899

#include<iostream>
#include<utility>

using namespace std;

class treap {
	class treapNode {
		typedef pair<treapNode*, treapNode*> pNode;
		
		int key;
		int priority;
		int size;
		treapNode *left, *right;
		
		void calcSize() {
			size = 1;
			if(left) size += left->size;
			if(right) size += right->size;
		}
		void setLeft(treapNode *newLeft) {
			left = newLeft;
			calcSize();
		}
		void setRight(treapNode *newRight) {
			right = newRight;
			calcSize();
		}
		
		pNode split(treapNode *root, int key) {
			if(root == NULL) return pNode(NULL, NULL);
			if(root->key > key) {
				pNode leftSub = split(root->left, key);
				root->setLeft(leftSub.second);
				return pNode(leftSub.first, root);
			}
			else {
				pNode rightSub = split(root->right, key);
				root->setRight(rightSub.first);
				return pNode(root, rightSub.second);
			}
		}
		treapNode* insert(treapNode *root, treapNode *node) {
			if(root == NULL) return node;
			if(node->priority > root->priority) {
				pNode sub = split(root, node->key);
				node->setLeft(sub.first);
				node->setRight(sub.second);
				return node;
			}
			if(root->key > node->key) root->setLeft(insert(root->left, node));
			else root->setRight(insert(root->right, node));
			return root;
		}
		
		treapNode* merge(treapNode *a, treapNode *b) {
			if(a == NULL) return b;
			if(b == NULL) return a;
			if(a->priority > b->priority) {
				a->setRight(merge(a->right, b));
				return a;
			}
			else {
				b->setLeft(merge(a, b->left));
				return b;
			}
		}
		treapNode* erase(treapNode *root, int key) {
			if(root == NULL) return root;
			if(root->key == key) {
				treapNode* ret = merge(root->left, root->right);
				delete root;
				return ret;
			}
			if(root->key > key) root->setLeft(erase(root->left, key));
			else root->setRight(erase(root->right, key));
			return root;
		}
			
		treapNode* kth(treapNode *root, int k) {
			int leftSize = 0;
			if(root->left) leftSize = root->left->size;
			if(leftSize == k) return root;
			else if(k < leftSize) return kth(root->left, k);
			else return kth(root->right, k - leftSize - 1);
		}
		
		public:
		treapNode(int key_): key(key_), priority(rand()), size(1), left(NULL), right(NULL) { }
		treapNode* insert(int key) {
			return insert(this, new treapNode(key));
		}
		treapNode* erase(int key) {
			return erase(this, key);
		}
		int kth(int k) {
			return kth(this, k) -> key;
		}
	};
	
	treapNode* root;
	
	public:
	treap(): root(NULL) { }
	void insert(const int &key) { root = root->insert(key); }
	void erase(const int &key) { root = root->erase(key); }
	const int operator[](int index) { return root->kth(index); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	treap t;
	
	for(int i=0; i<N; i++) {
		int T, X;
		cin >> T >> X;
		if(T == 1) {
			t.insert(X);
		}
		if(T == 2) {
			int ans = t[X-1];
			t.erase(ans);
			cout << ans << '\n';
		}
	}
}