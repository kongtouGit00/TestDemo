#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <limits>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

class SpiralOrderMatrix{

public:
    void spiralOrderMatrix(vector< vector<int> >& matrix){
        if(matrix.empty() || matrix.size() <= 0 || matrix[0].empty() || matrix[0].size() <= 0)
            return;
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while(tR <= dR && tC <= dC){
            printEdge(matrix, tR++, tC++, dR--, dC--);
        }
    }

private:
    void printEdge(vector< vector<int> >& matrix, int tR, int tC, int dR, int dC){
        if(tR == dR){
            for(int i = tC; i <= dC; ++i)
                cout << matrix[tR][i];
        }else if(tC == dC){
            for(int i = tR; i <= dR; ++i){
                cout << matrix[i][tC];
            }
        }else{
            int curRow = tR;
            int curCol = tC;
            while(curCol != dC){
                cout << matrix[tR][curCol++] << " ";
            }
            while(curRow != dR){
                cout << matrix[curRow++][dC] << " ";
            }
            while(curCol != tC){
                cout << matrix[dR][curCol--] << " ";
            }
            while(curRow != tR){
                cout << matrix[curRow--][tC] << " ";
            }
        }
    }
};

class RotateMatrix{

public:
    void rotateMatrix(vector< vector<int> >& matrix){
        if(matrix.empty() || matrix[0].empty() || matrix.size() < 0 || matrix[0].size() < 0)
            return;
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while(tR < dR){
            rotateEdge(matrix, tR++, tC++, dR--, dC--);
        }
    }

private:
    void rotateEdge(vector< vector<int> >& matrix, int tR, int tC, int dR, int dC){
        int times = dR - tR;
        for(int i = 0; i != times; ++i){
            int tmp = matrix[tR][tC + i];
            matrix[tR][tC + i] = matrix[dR - i][tC];
            matrix[dR - i][tC] = matrix[dR][dC - i];
            matrix[dR][dC - i] = matrix[tR + i][dC];
            matrix[tR + i][dC] = tmp;
        }
    }
};

class ZigZagMatrix{

public:
    void zigZagMatrix(vector< vector<int> >& matrix){
        if(matrix.empty() || matrix[0].empty() || matrix.size() < 0 || matrix[0].size() < 0)
            return;
        int aR = 0;
        int aC = 0;
        int bR = 0;
        int bC = 0;
        int endR = matrix.size() - 1;
        int endC = matrix[0].size() - 1;
        bool fromUp = false;
        while(aR != endR + 1){
            zigZagEdge(matrix, aR, aC, bR, bC, fromUp);
            aR = aC == endC ? aR + 1 : aR;
            aC = aC == endC ? aC : aC + 1;
            bR = bR == endR ? bR : bR + 1;
            bC = bR == endR ? bC + 1 : bC;
            fromUp = !fromUp;
        }
    }

private:
    void zigZagEdge(vector< vector<int> >& matrix, int tR, int tC, int dR, int dC, bool fromUp){
        if(fromUp){
            while(tR != dR + 1){
                cout << matrix[tR++][tC--] << " ";
            }
        }else{
            while(dR != tR - 1){
                cout << matrix[dR--][dC++] << " ";
            }
        }
    }
};

class FindNumInSortMatrix{

public:
    bool findNumInSortedMatrix(vector< vector<int> >& matrix, int aim){
        if(matrix.empty() || matrix[0].empty() || matrix.size() < 0 || matrix[0].size() < 0)
            return false;
        int row = 0;
        int col = matrix[0].size() - 1;
        while(row < matrix.size() && col >= 0){
            if(matrix[row][col] == aim){
                return true;
            }else if(matrix[row][col] < aim){
                ++row;
            }else{
                --col;
            }
        }
        return false;
    }
};

struct Node{

    int val;
    Node* next;

    Node(int data) : val(data){
        this->next = nullptr;
    }
};

struct DoubleNode{

    int val;
    DoubleNode* last;
    DoubleNode* next
    ;

    DoubleNode(int data) : val(data){
        this->last = nullptr;
        this->next = nullptr;
    }
};

class ReverseList{

public:
    Node* reverseList(Node* head){
        if(head == nullptr || head->next == nullptr)
            return head;
        Node* pre = nullptr;
        Node* next = nullptr;
        while(head != nullptr){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    DoubleNode* reverseList(DoubleNode* head){
        if(head == nullptr || head->next == nullptr)
            return head;
        DoubleNode* pre = nullptr;
        DoubleNode* next = nullptr;
        while(head != nullptr){
            next = head->next;
            head->next = pre;
            head->last = next;
            pre = head;
            head = next;
        }
    }
};

class IsPalindromeList{

public:
    bool isPalindrome1(Node* head){
        if(head == nullptr || head->next == nullptr)
            return true;
        stack<Node*> myStack;
        Node* cur = head;
        while(cur != nullptr){
            myStack.push(cur);
            cur = cur->next;
        }
        while(head != nullptr){
            if(head->val != myStack.top()->val)
                return false;
            myStack.pop();
            head = head->next;
        }
        return true;
    }
    //need n/2 extra space
    bool isPalindrome2(Node* head){
        if(head == nullptr || head->next == nullptr)
            return true;
        stack<Node*> myStack;
        Node* right = head->next;
        Node* cur = head;
        while(cur->next != nullptr && cur->next->next != nullptr){
            cur = cur->next->next;
            right = right->next;
        }
        while(right != nullptr){
            myStack.push(right);
            right = right->next;
        }
        while(!myStack.empty()){
            if(head->val != myStack.top()->val)
                return false;
            myStack.pop();
            head = head->next;
        }
        return true;
    }

    bool isPalindrome3(Node* head){
        if(head == nullptr || head->next == nullptr)
            return true;
        Node* n1 = head;
        Node* n2 = head;
        while(n2->next != nullptr && n2->next->next != nullptr){
            n1 = n1->next;
            n2 = n2->next->next;
        }
        n2 = n1->next;//n2 pointer first right part
        n1->next = nullptr;
        Node* n3 = nullptr;
        while(n2 != nullptr){
            n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        n3 = n1;
        n2 = head;
        bool res = true;
        while(n1 != nullptr && n2 != nullptr){
            if(n1->val != n2->val){
                res = false;
                break;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        n1 = n3->next;
        n3->next = nullptr;
        while(n1 != nullptr){
            n2 = n1->next;
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
        return res;
    }
};

class PrintCommonPart{

public:
    void printCommonPart(Node* head1, Node* head2){
        if(head1 == nullptr || head2 == nullptr)
            return;
        while(head1 != nullptr && head2 != nullptr){
            if(head1->val < head2->val){
                head1 = head1->next;
            }else if(head2->val < head1->val){
                head2 = head2->next;
            }else{
                cout << head1->val << " ";
                head1 = head1->next;
                head2 = head2->next;
            }
        }
    }
};

class SmallerEqualBigger{

public:
    Node* listPartition1(Node* head, int pivot){
        if(head == nullptr || head->next == nullptr)
            return head;
        int i = 0;
        Node* cur = head;
        while(cur != nullptr){
            ++i;
            cur = cur->next;
        }
        vector<Node*> nodeArr(i, nullptr);
        cur = head;
        for(int i = 0; i < nodeArr.size(); ++i){
            nodeArr[i] = cur;
            cur = cur->next;
        }
        //parttion
        arrPartition(nodeArr, pivot);
        for(int i = 1; i < nodeArr.size(); ++i){
            nodeArr[i - 1]->next = nodeArr[i];
        }
        nodeArr[i - 1]->next = nullptr;
        return nodeArr[0];
    }

    Node* listPartition2(Node* head, int pivot){
        if(head == nullptr || head->next == nullptr)
            return head;
        Node* sH = nullptr;
        Node* sT = nullptr;
        Node* eH = nullptr;
        Node* eT = nullptr;
        Node* bH = nullptr;
        Node* bT = nullptr;
        while(head != nullptr){
            if(head->val < pivot){
                if(sH == nullptr){
                    sH = head;
                    sT = head;
                }else{
                    sT->next = head;
                    sT = head;
                }
            }else if(head->val == pivot){
                if(eH == nullptr){
                    eH = head;
                    eT = head;
                }else{
                    eT->next = head;
                    eT = head;
                }
            }else{
                if(bH == nullptr){
                    bH = head;
                    bT = head;
                }else{
                    bT->next = head;
                    bT = head;
                }
            }
            head = head->next;
        }

        if(sT != nullptr){
            sT->next = eH;
            eT = eT == nullptr ? sT : eT;
        }
        if(eT != nullptr){
            eT->next = bH;
        }

        return sH != nullptr ? sH : (eH != nullptr ? eH : bH);
    }

private:
    void arrPartition(vector<Node*>& arr, int pivot){
        int less = -1;
        int more = arr.size();
        int index = 0;
        while(index < more){
            if(arr[index]->val < pivot){
                Swap(arr, index++, ++less);
            }else if(arr[index]->val > pivot){
                Swap(arr, index, --more);
            }else{
                index++;
            }
        }
    }

    void Swap(vector<Node*>& arr, int i, int j){
        Node* tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

struct RandomNode{

    int val;
    RandomNode* next;
    RandomNode* random;

    RandomNode(int data) : val(data){
        this->next = nullptr;
        this->random = nullptr;
    }
};

class CopyListWithRandom{

public:
    RandomNode* copyListWithRandom1(RandomNode* head){
        if(head == nullptr || head->next == nullptr)
            return head;
        unordered_map<RandomNode*, RandomNode*> myMap;
        RandomNode* cur = head;
        while(cur != nullptr){
            myMap.insert(make_pair(cur, new RandomNode(cur->val)));
            cur = cur->next;
        }
        cur = head;
        while(cur != nullptr){
            myMap[cur]->next = myMap[cur->next];
            myMap[cur]->random = myMap[cur->random];
            cur = cur->next;
        }
        return myMap[head];
    }

    RandomNode* copyListWithRandom2(RandomNode* head){
        if(head == nullptr || head->next == nullptr)
            return head;
        RandomNode* cur = head;
        RandomNode* next = nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = new RandomNode(cur->val);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        RandomNode* curCopy = nullptr;
        while(cur != nullptr){
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->random = cur->random != nullptr ? cur->random->next : nullptr;
            cur = next;
        }
        //split
        RandomNode* res = head->next;
        cur = head;
        while(cur != nullptr){
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->next = next != nullptr ? next->next : nullptr;
            cur->next = next;
            cur = next;
        }
        return res;
    }
};

class FindFirstIntersectNode{

public:
    Node* getIntersectNode(Node* head1, Node* head2){
        if(head1 == nullptr || head2 == nullptr)
            return nullptr;
        Node* loop1 = getLoop(head1);
        Node* loop2 = getLoop(head2);
        if(loop1 == nullptr && loop2 == nullptr){
            return noLoop(head1, head2);
        }
        if(loop1 != nullptr && loop2 != nullptr){
            return bothLoop(head1, loop1, head2, loop2);
        }
        return nullptr;
    }

private:
    Node* getLoop(Node* head){
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return nullptr;
        Node* n1 = head->next;
        Node* n2 = head->next->next;
        while(n1 != nullptr && n2 != nullptr){
            if(n2->next == nullptr && n2->next->next == nullptr)
                return nullptr;
            n1 = n1->next;
            n2 = n2->next->next;
        }
        n2 = head;
        while(n1 != n2){
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }

    //确定是两个无环链表的相交问题
    Node* noLoop(Node* head1, Node* head2){
        Node* cur1 = head1;
        Node* cur2 = head2;
        int n = 0;
        while(cur1->next != nullptr){
            ++n;
            cur1 = cur1->next;
        }
        while(cur2->next != nullptr){
            --n;
            cur2 = cur2->next;
        }
        if(cur1 != cur2)//两个无环链表不相交
            return nullptr;
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while(n != 0){
            --n;
            cur1 = cur1->next;
        }
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }

    Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2){
        Node* cur1 = nullptr;
        Node* cur2 = nullptr;
        if(loop1 == loop2){
            int n = 0;
            cur1 = head1;
            while(cur1 != nullptr){
                ++n;
                cur1 = cur1->next;
            }
            cur2 = head2;
            while(cur2 != nullptr){
                --n;
                cur2 = cur2->next;
            }
            cur1 = n > 0 ? head1 : head2;
            cur2 = cur1 == head1 ? head2 : head1;
            n = abs(n);
            while(n != 0){
                --n;
                cur1 = cur1->next;
            }
            while(cur1 != cur2){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        }else{
            cur1 = loop1->next;
            while(cur1 != loop1){
                if(cur1 == loop2)
                    return loop1;
                cur1 = cur1->next;
            }
            return nullptr;
        }
    }
};

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : val(data){
        this->left = nullptr;
        this->right = nullptr;
    }
};

class PreInPosTraversal{

public:
    void preOrderRecur(TreeNode* head){
        if(head == nullptr)
            return;
        cout << head->val << " ";
        preOrderRecur(head->left);
        preOrderRecur(head->right);
    }

    void inOrderRecur(TreeNode* head){
        if(head == nullptr)
            return;
        inOrderRecur(head->left);
        cout << head->val << " ";
        inOrderRecur(head->right);
    }

    void PosOrderRecur(TreeNode* head){
        if(head == nullptr)
            return;
        PosOrderRecur(head->left);
        PosOrderRecur(head->right);
        cout << head->val << " ";
    }

    void preOrderUnRecur(TreeNode* head){
        if(head == nullptr)
            return;
        stack<TreeNode*> preStack;
        preStack.push(head);
        while(!preStack.empty()){
            head = preStack.top();
            preStack.pop();
            cout << head->val << " ";
            if(head->right != nullptr){
                preStack.push(head->right);
            }
            if(head->left != nullptr){
                preStack.push(head->left);
            }
        }
    }

    void inOrderUnRecur(TreeNode* head){
        if(head == nullptr)
            return;
        stack<TreeNode*> inStack;
        while(!inStack.empty() || head != nullptr){
            if(head != nullptr){
                inStack.push(head);
                head = head->left;
            }else{
                head = inStack.top();
                cout << head->val << " ";
                inStack.pop();
                head = head->right;
            }
        }

        cout << endl;
    }

    void posOrderUnRecur(TreeNode* head){
        if(head == nullptr)
            return;
        stack<TreeNode*> postack;
        stack<TreeNode*> help;
        postack.push(head);
        while(!postack.empty()){
            head = postack.top();
            postack.pop();
            help.push(head);
            if(head->left != nullptr){
                postack.push(head->left);
            }
            if(head->right != nullptr){
                postack.push(head->right);
            }
        }
        while(!help.empty()){
            cout << help.top()->val << " ";
            help.pop();
        }
    }
};

struct pNode{

    int val;
    pNode* left;
    pNode* right;
    pNode* parent;

    pNode(int data) : val(data){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

class SuccessorNode{

public:
    pNode* getSuccessorNode(pNode* node){
        if(node == nullptr)
            return node;
        if(node->right != nullptr){
            return getLeftMost(node->right);
        }else{
            pNode* parent = node->parent;
            while(parent != nullptr && parent->left != node){
                node = parent;
                parent = node->parent;
            }
            return parent;
        }
    }

private:
    pNode* getLeftMost(pNode* node){
        if(node == nullptr)
            return nullptr;
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }
};

class AncestorNode{

public:
    pNode* getAncestorNode(pNode* node){
        if(node == nullptr)
            return nullptr;
        if(node->left != nullptr){
            return getRightMost(node->left);
        }else{
            pNode* parent = node->parent;
            while(parent != nullptr && parent->right != node){
                node = parent;
                parent = node->parent;
            }
            return parent;
        }
    }

private:
    pNode* getRightMost(pNode* node){
        if(node == nullptr)
            return nullptr;
        while(node->right != nullptr){
            node = node->right;
        }
        return node;
    }
};

class SerializeAndReconstructTree{

public:
    string serialByPre(TreeNode* head){
        if(head == nullptr)
            return "#_";
        string res = to_string(head->val) + "_";
        res += serialByPre(head->left);
        res += serialByPre(head->right);
    }

    TreeNode* reconByPreString(string preStr){
        vector<string> v;
        splitString(preStr, v, "_");

        queue<string> myQueue;
        for(int i = 0; i < v.size(); ++i)
            myQueue.push(v[i]);

        return reconPreOrder(myQueue);
    }

    string serialByLevel(TreeNode* head){
        if(head == nullptr)
            return "#_";
        queue<TreeNode*> myQueue;
        string res = to_string(head->val) + "_";
        myQueue.push(head);
        while(!myQueue.empty()){
            head = myQueue.front();
            myQueue.pop();
            if(head->left != nullptr){
                res += to_string(head->left->val) + "_";
                myQueue.push(head->left);
            }else{
                res += "#_";
            }
            if(head->right != nullptr){
                res += to_string(head->right->val) + "_";
                myQueue.push(head->right);
            }else{
                res += "#_";
            }
        }
        return res;
    }

    TreeNode* reconByLevelString(string levelStr){
        vector<string> v;
        splitString(levelStr, v, "_");

        int index = 0;
        TreeNode* head = generateNodeByString(v[index++]);
        queue<TreeNode*> myQueue;
        if(head != nullptr)
            myQueue.push(head);
        TreeNode* node = nullptr;
        while(!myQueue.empty()){
            node = myQueue.front();
            myQueue.pop();
            node->left = generateNodeByString(v[index++]);
            node->right = generateNodeByString(v[index++]);
            if(node->left != nullptr)
                myQueue.push(node->left);
            if(node->right != nullptr)
                myQueue.push(node->right);
        }
        return head;
    }

private:
    void splitString(const string& s, vector<string>& v, const string& c){
        string::size_type pos1, pos2;
        pos1 = 0;
        pos2 = s.find(c);
        while(string::npos != pos2){
            v.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

    TreeNode* reconPreOrder(queue<string>& myQueue){
        string value = myQueue.front();
        myQueue.pop();
        if(value.compare("#") == 0)
            return nullptr;
        TreeNode* head = new TreeNode(stoi(value));
        head->left = reconPreOrder(myQueue);
        head->right = reconPreOrder(myQueue);

        return head;
    }

    TreeNode* generateNodeByString(string str){
        if(str.compare("#") == 0)
            return nullptr;
        return new TreeNode(stoi(str));
    }
};

struct ReturnData{

    bool isBalanced;
    int height;

    ReturnData(bool isB, int height){
        this->isBalanced = isB;
        this->height = height;
    }
};

class IsBalancedTree{

public:
    bool isBalancedTree(TreeNode* head){
        if(head == nullptr)
            return true;
        return process(head)->isBalanced;
    }

private:
    ReturnData* process(TreeNode* x){
        if(x == nullptr)
            return new ReturnData(true, 0);
        ReturnData* leftData = process(x->left);
        ReturnData* rightData = process(x->right);
        if(!leftData->isBalanced)
            return new ReturnData(false, 0);
        if(!rightData->isBalanced)
            return new ReturnData(false, 0);
        if(abs(leftData->height - rightData->height) > 1)
            return new ReturnData(false, 0);
        return new ReturnData(true, max(leftData->height, rightData->height) + 1);
    }
};

struct ReturnData2{

    bool isBST;
    int mins;
    int maxs;

    ReturnData2(bool isBST, int mins, int maxs){
        this->isBST = isBST;
        this->mins = mins;
        this->maxs = maxs;
    }
};

class IsBST{

public:
    bool isBinarySearchTree(TreeNode* head){
        if(head == nullptr)
            return true;
        return process(head)->isBST;
    }

    bool isBinarySearchTree2(TreeNode* head){
        if(head == nullptr)
            return true;

        int pre = std::numeric_limits<int>::min();
        stack<TreeNode*> inStack;
        while(!inStack.empty() || head != nullptr){
            if(head != nullptr){
                inStack.push(head);
                head = head->left;
            }else{
                head = inStack.top();
                inStack.pop();
                if(head->val > pre) {
                    pre = head->val;
                }else{
                    return false;
                }
                head = head->right;
            }
        }
        return true;
    }

private:
    ReturnData2* process(TreeNode* x){
        if(x == nullptr)
            return new ReturnData2(true, std::numeric_limits<int>::max(), std::numeric_limits<int>::min());
        ReturnData2* leftData = process(x->left);
        ReturnData2* rightData = process(x->right);
        int mins = min(x->val, min(leftData->mins, rightData->mins));
        int maxs = max(x->val, max(leftData->maxs, rightData->maxs));
        bool isBST = true;
        if(!leftData->isBST || !rightData->isBST || x->val <= leftData->maxs || x->val >= rightData->mins)
            isBST = false;
        return new ReturnData2(isBST, mins, maxs);
    }
};

class IsCBT{

public:
    bool isCompleteBinaryTree(TreeNode* head){
        if(head == nullptr)
            return true;
        list<TreeNode*> myList;
        bool leaf = false;
        TreeNode* L = nullptr;
        TreeNode* R = nullptr;
        myList.push_back(head);
        while(!myList.empty()){
            head = myList.front();
            myList.pop_front();
            L = head->left;
            R = head->right;
            if((L == nullptr && R != nullptr) || (leaf && (L != nullptr || R != nullptr)))
                return false;
            if(L != nullptr)
                myList.push_back(L);
            if(R != nullptr)
                myList.push_back(R);
            if(L == nullptr || R == nullptr)
                leaf = true;
        }
        return true;
    }
};

class CompleteTreeNodeNumber{

public:
    int nodeNum(TreeNode* head){
        if(head == nullptr)
            return 0;
        return process(head, 1, mostLeftLevel(head, 1));
    }

private:
    int mostLeftLevel(TreeNode* node, int level){
        while(node != nullptr){
            ++level;
            node = node->left;
        }
        return level - 1;
    }

    int process(TreeNode* node, int level, int h){
        if(level == h)
            return 1;
        if(mostLeftLevel(node->right, level + 1) == h){
            return (1 << (h - level) + process(node->right, level + 1, h));
        }else{
            return (1 << (h - level - 1) + process(node->left, level + 1, h));
        }
    }
};



int main() {




    return 0;
}