
#include <iostream>

using namespace std;

struct TreeNode{

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) : val(data){

		this->left = nullptr;
		this->right = nullptr;
	}
};

struct ReturnData{

	bool isB;
	int height;

	ReturnData(bool isB, int height){

		this->isB = isB;
		this->height = height;
	}
};

class IsBalancedTree{

public:
	bool isBalancedTree(TreeNode* pHead){

	}

private:
	ReturnData* process(TreeNode* x){

		
	}
};

int main(int* argc, char** argv){


	return 0;
}


