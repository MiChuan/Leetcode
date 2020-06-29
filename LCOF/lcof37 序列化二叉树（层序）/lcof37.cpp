#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	Codec();

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == NULL) return "null";
		string tree;
		queue<TreeNode*> treeQueue;
		TreeNode* curNode = root;
		treeQueue.push(root);//根节点入队
		tree.append(to_string(root->val));//根节点序列化
		while (!treeQueue.empty()) {
			curNode = treeQueue.front();//队首元素
			if (curNode->left != NULL) {
				tree.append(" ");
				tree.append(to_string(curNode->left->val));
				treeQueue.push(curNode->left);
			}
			else {
				tree.append(" null");
			}
			if (curNode->right != NULL) {
				tree.append(" ");
				tree.append(to_string(curNode->right->val));
				treeQueue.push(curNode->right);
			}
			else {
				tree.append(" null");
			}
			treeQueue.pop();//队首元素出队
		}
		return tree;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream input(data);
		string val;
		vector <TreeNode*> tree;
		while (input >> val) {
			if (val == "null") {
				tree.push_back(NULL);
			}
			else {
				tree.push_back(new TreeNode(stoi(val)));
			}
		}
		int j = 1;
		for (int i = 0; j < tree.size(); i++) {
			if (tree[i] == NULL) continue;
			if (j < tree.size()) tree[i]->left = tree[j++];
			if (j < tree.size()) tree[i]->right = tree[j++];
		}
		return tree[0];
	}
};

Codec::Codec(void){}

int main() {
	Codec treeString;
	TreeNode* treeRoot = new TreeNode(1);
	treeRoot->left = new TreeNode(2);
	treeRoot->right = new TreeNode(3);
	treeRoot->right->left = new TreeNode(4);
	treeRoot->right->right = new TreeNode(5);
	string codeString = treeString.serialize(treeRoot);
	string encodeString = treeString.serialize(treeString.deserialize(treeString.serialize(treeRoot)));
	cout << codeString << endl;
	cout << encodeString << endl;
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));