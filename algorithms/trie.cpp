// BOJ 14425

#include<iostream>
#include<cstring>

using namespace std;
const int ALPHABETS = 26;
const int MAXLEN = 501;

int toNum(char c) {
	return c - 'a';
}

class TrieNode {
	TrieNode* children[ALPHABETS];
	bool terminal;
	
	public:
	TrieNode(): terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for(int i=0; i<ALPHABETS; i++)
			if(children[i]) delete children[i];
	}
	void insert(char* key) {
		if(*key == 0)
			terminal = true;
		else {
			int next = toNum(*key);
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next] -> insert(key + 1);
		}
	}
	TrieNode* find(char* key) {
		if(*key == 0)
			return this;
		int next = toNum(*key);
		if(children[next] == NULL)
			return NULL;
		return children[next] -> find(key + 1);
	}
	bool count(char *key) {
		TrieNode* node = find(key);
		if(node == NULL) return false;
		else return node -> terminal;
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	
	TrieNode Trie;
	for(int i=0; i<N; i++) {
		char str[MAXLEN];
		cin >> str;
		Trie.insert(str);
	}
	
	int ans = 0;
	for(int i=0; i<M; i++) {
		char str[MAXLEN];
		cin >> str;
		if(Trie.count(str)) ans++;
	}
	
	cout << ans;
}